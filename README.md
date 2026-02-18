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

<p>Only Linux now.</p>
<p>MacOS and Windows coming soon.</p>

### Linux
#### 1. Global install

```bash
git clone https://github.com/NathanMelegari/lamon-monitor
cd lamon-monitor/
cmake -S . -B build
cmake --build build
sudo cmake --install build
```
Then:
```bash
lamon <URL>
```

#### 2. User install

1. Install binary
2. Go to download directory
3. Run the command below:
```bash
chmod +x lamon-1.0.0-linux-x86_64
mv lamon-1.0.0-linux-x86_64 lamon
mkdir -p ~/.local/bin
mv lamon ~/.local/bin
```
Make sure ~/.local/bin is in your PATH:
export PATH="$HOME/.local/bin:$PATH"

Then:
```bash
lamon <URL>
```

#### 3. Run without install
```bash
git clone https://github.com/NathanMelegari/lamon-monitor
cd lamon-monitor/
cmake -B build && cmake --build build
cd build/
```
Then:
```bash
./lamon <URL>
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
