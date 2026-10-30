# Mr. Whoami?

A weird little desktop hardware agent that physically tests and benchmarks localized AI models vs basic scripted responses in real time.

## 🚀 What even is THIS?
`Mr. Whoami?` is a physical desk lil guy built around an ESP32-S3. Instead of running heavy LLM evaluations on a massive cloud server this little guy takes live audio input, processes local response logic on-chip, and physically tests HOW fast and accurately edge hardware can handle interactive AI vs hardcoded fallback scripts.

It gives real-time diagnostic feedback using a mini OLED screen and an I2S speaker setup.

## 💡 Why build it?
Most AI benchmarks are focused on huge GPUs and cloud infrastructure which doesn't help much when your you know trying to build lowpower and instant-response hardware on a desk. I made this to test local model latency and audio input pipelines and physical UI states directly on a microcontroller without relying on external cloud APIs.

## 🛠️ Hardware Stack
* **Brain:** ESP32-S3 DevKit (Dual-core LX7 + AI vector instructions)
* **Mic:** INMP441 I2S digital omnidirectional microphone
* **Audio Out:** MAX98357A I2S Class D amp + 8Ω 2W mini speaker
* **Display:** 0.96" I2C OLED (128x64) for emotion states / debug logs
* **Power:** TP4056 Type-C Li-Ion charging module + 18650 battery

## 📂 Repo Structure
* `BOM.csv` - Complete parts list with prices and vendor links.
* `/schematics` - Wiring diagrams, pinouts, and circuit layouts.
* `/firmware` - ESP32-S3 firmware for audio handling and benchmarking logic.

Check out [`BOM.csv`](./BOM.csv) for the full parts list and pricing.
