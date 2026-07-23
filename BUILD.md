# Build Instructions for Linux

## Quick Start

```bash
# 1. Install dependencies
sudo apt-get update
sudo apt-get install -y cmake qt6-base-dev qt6-tools-dev build-essential

# 2. Clone and build
git clone https://github.com/Emran-10/callib.git
cd callib
mkdir build && cd build
cmake ..
make -j$(nproc)

# 3. Run
./callib
```

## Detailed Setup

### Prerequisites

**Ubuntu 20.04 LTS:**
```bash
sudo apt-get install -y \
    build-essential \
    cmake \
    git \
    qt6-base-dev \
    qt6-tools-dev \
    libqt6core6 \
    libqt6gui6 \
    libqt6widgets6
```

**Ubuntu 22.04 LTS:**
```bash
sudo apt-get install -y \
    build-essential \
    cmake \
    git \
    qt6-base-dev \
    qt6-tools-dev
```

### Build Steps

1. **Create build directory:**
   ```bash
   mkdir build
   cd build
   ```

2. **Configure with CMake:**
   ```bash
   cmake -DCMAKE_BUILD_TYPE=Release ..
   ```

3. **Build:**
   ```bash
   make -j$(nproc)
   ```
   - `-j$(nproc)` uses all available CPU cores
   - For single-threaded build: `make`

4. **Install (optional):**
   ```bash
   sudo make install
   ```

### Run

```bash
./callib
```

## Troubleshooting

### Error: "Could not find Qt6"

Specify Qt6 location:
```bash
cmake -DQt6_DIR=/usr/lib/cmake/Qt6 ..
```

### Error: "Cannot find moc"

Install MOC tools:
```bash
sudo apt-get install qt6-tools-dev
```

### Build fails with "No rule to make target"

Clean and rebuild:
```bash
cd ..
rm -rf build
mkdir build && cd build
cmake ..
make
```

## Development Build

For debugging with symbols:
```bash
cmake -DCMAKE_BUILD_TYPE=Debug ..
make
gdb ./callib
```

## Verbose Build

To see full compiler commands:
```bash
make VERBOSE=1
```
