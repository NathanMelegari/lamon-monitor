<p align="center">
  <img src="./assets/lamon_logo.png" width="220">
</p>

<h1 align="center">Lamon</h1>
<p align="center">
Real-time API monitoring from your terminal.
</p>

Lamon is a lightweight CLI tool for monitoring API latency, status codes, and uptime in real time directly from the terminal.


---

## Features

- Monitor API latency and status in real time
- Works directly in the terminal
- Lightweight and fast
- No UI, no browser, no bloat
- Simple CLI usage



---

## Install

Only Linux now
MacOS and Windows coming soon.

### Linux
#### 1.Install the executable
```bash
chmod +x lamon-v1.0.0-linux-x86_64
mv lamon-v1.0.0-linux-x86_64 lamon
sudo mv lamon /usr/local/bin
```

#### 2.Install with CMake
```bash
git clone https://github.com/NathanMelegari/lamon-monitor
cd lamon-monitor/
cmake -B build && cmake --build build && sudo cmake --install build
```


---

## Usage

![Preview](./assets/run_example.png)

### Example output:

![Preview](./assets/output_example.png)


---

## Why Lamon?

When debugging APIs, opening a browser or heavy tools slows you down. Lamon keeps everything inside the terminal so you can monitor performance instantly while coding.


---

## Roadmap

- Multiple endpoint monitoring
- Graph mode
- JSON output
- Config file support
- Alerts



---

## Contributing

Pull requests are welcome.

1. Fork the repo
2. Create a branch
3. Commit changes
4. Open a PR



For major changes, open an issue first.
