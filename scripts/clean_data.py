import pandas as pd
import numpy as np
import os
import re

def clean_weight(val):
    if pd.isna(val) or not isinstance(val, str):
        return np.nan
    val = val.replace(' lbs.', '').strip()
    try:
        return float(val)
    except:
        return np.nan

def clean_height(val):
    if pd.isna(val) or not isinstance(val, str):
        return np.nan
    # e.g. "5' 11\""
    match = re.search(r"(\d+)'\s*(\d+)", val)
    if match:
        feet = int(match.group(1))
        inches = int(match.group(2))
        return float(feet * 12 + inches)
    return np.nan

def clean_percentage(val):
    if pd.isna(val) or not isinstance(val, str):
        return np.nan
    val = val.replace('%', '').strip()
    try:
        return float(val) / 100.0
    except:
        return np.nan

def clean_reach(val):
    if pd.isna(val) or not isinstance(val, str):
        return np.nan
    val = val.replace('"', '').strip()
    try:
        return float(val)
    except:
        return np.nan

def main():
    script_dir = os.path.dirname(os.path.abspath(__file__))
    project_dir = os.path.dirname(script_dir)
    raw_path = os.path.join(project_dir, 'data', 'raw_fighter_details.csv')
    clean_path = os.path.join(project_dir, 'data', 'clean_fighters.csv')

    print(f"Loading data from {raw_path}...")
    df = pd.read_csv(raw_path)

    # Clean Weight
    df['Weight'] = df['Weight'].apply(clean_weight)
    
    # Clean Height
    df['Height'] = df['Height'].apply(clean_height)
    
    # Clean Reach
    df['Reach'] = df['Reach'].apply(clean_reach)

    # Clean Percentages
    pct_cols = ['Str_Acc', 'Str_Def', 'TD_Acc', 'TD_Def']
    for col in pct_cols:
        df[col] = df[col].apply(clean_percentage)

    # Handle Missing Values gracefully
    # We will fill missing numeric values with the column median
    num_cols = ['Height', 'Weight', 'Reach', 'SLpM', 'SApM', 'TD_Avg', 'Sub_Avg'] + pct_cols
    for col in num_cols:
        if col in df.columns:
            median_val = df[col].median()
            df[col] = df[col].fillna(median_val)

    # Feature Engineering: Style
    # Let's use a function based on row stats
    def determine_style(row):
        td = row.get('TD_Avg', 0)
        sub = row.get('Sub_Avg', 0)
        slpm = row.get('SLpM', 0)
        
        # 0 = Balanced, 1 = Grappler, 2 = Striker
        if td > 2.0 or sub > 1.0:
            return 1
        elif slpm > 3.5:
            return 2
        else:
            return 0

    df['Style'] = df.apply(determine_style, axis=1)

    # Final selection
    final_cols = ['fighter_name', 'Height', 'Weight', 'Reach', 'SLpM', 'Str_Acc', 'SApM', 'Str_Def', 'TD_Avg', 'TD_Acc', 'TD_Def', 'Sub_Avg', 'Style']
    clean_df = df[final_cols].copy()
    
    # Drop rows where fighter_name is missing just in case
    clean_df = clean_df.dropna(subset=['fighter_name'])

    print(f"Saving {len(clean_df)} clean records to {clean_path}...")
    clean_df.to_csv(clean_path, index=False)
    print("Done!")

if __name__ == '__main__':
    main()
