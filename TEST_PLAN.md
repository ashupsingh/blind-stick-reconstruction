# New build test plan

These are tests to perform on the reconstructed build, not results already measured. Start with indicators/dummy loads and verify the supply and input voltage limits from CIRCUIT.md.

| Input / condition | Expected observation |
|---|---|
| Valid near/mid/far distances | Corresponding vibration cadence |
| Echo timeout | Fault indication rather than a false clear path |

For every test record date, firmware commit, exact component/module, measured supply voltage, input, output and elapsed time. Mark each pass/fail only after observing it. Keep failed trials and calibration readings. Sensor thresholds must be calibrated for the actual module.
