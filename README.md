# Roadmap

## GBM

- [x] Basic GBM Formula logic

## Bank Roll

- [ ] Prediction : Correct or wrong? Start with simple random dice roll stuff
- [ ] Bank roll
- [ ] Add CSV export functionality
- [ ] Implement daily price paths
- [ ] Add CLI arguments for Volatility and Drift

---

User is able to access his bet history, and make a prediction given the fight night information.
Then we _simulate_ using past data, then users payroll (bank account) gets updated?

## Monte Carlo Simul?

- [ ] Real life stock data : Either fetch remote or local csv file
- [ ] Different formula for numerical checking

# Simulation

## Single fight

### V1.

Single fight is simulated using a win rate from previous games.
$$p = \frac{x}{x+ y}, \quad X \sim U(0, 1), \quad \mathbb{P}(X< p)$$

We just interpret winrate...

Then, we use monte-carlo simulation, to simulate $n$ times, and record how many times each player won.

# Betting Strategy

We can use _Kelly criterion_?

**Adaptive betting strategy**? : If we have enough money why not bet on low odds (high return?)
