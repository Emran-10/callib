# CalLib - Document Management System

A Qt-based C++ application for document and educational content management with features for clipboard monitoring, document normalization, TOC generation, and more.

## Features

- **Document Management**: Create and manage documents with sections
- **Clipboard Monitoring**: Monitor and manage clipboard content
- **TOC Generation**: Automatically generate table of contents
- **Document Normalization**: Normalize document formatting
- **Image Capture**: Capture and embed images
- **Keyboard Shortcuts**: Customizable keyboard shortcuts
- **Settings Management**: Persistent application settings

## Requirements

- **CMake**: 3.20 or higher
- **Qt6**: Core, Gui, Widgets modules
- **C++ Compiler**: Supporting C++17 standard
- **Linux**: Ubuntu 20.04 LTS or later (tested)

### Install Dependencies on Ubuntu/Debian

```bash
sudo apt-get update
sudo apt-get install -y \
    cmake \
    qt6-base-dev \
    qt6-tools-dev \
    build-essential \
    git
```

## Building

### 1. Clone the repository

```bash
git clone https://github.com/Emran-10/callib.git
cd callib
```

### 2. Create build directory

```bash
mkdir build
cd build
```

### 3. Configure and build

```bash
cmake ..
make
```

### 4. Run the application

```bash
./callib
```

## Project Structure

```
callib/
├── src/
│   ├── core/
│   │   ├── application.h/cpp      # Qt app initialization
│   │   ├── service_locator.h      # Dependency injection container
│   │   └── interfaces/            # Abstract service contracts
│   ├── features/
│   │   ├── ui/                    # User interface
│   │   ├── clipboard/             # Clipboard monitoring
│   │   ├── document_normalizer/   # Document normalization
│   │   ├── toc_generator/         # TOC generation
│   │   ├── section_manager/       # Section management
│   │   ├── image_capture/         # Image capture
│   │   ├── subject_management/    # Subject management
│   │   ├── keyboard_shortcuts/    # Keyboard shortcuts
│   │   ├── settings/              # Settings management
│   │   └── heading_search/        # Heading search
│   ├── utilities/
│   │   ├── logger.h/cpp           # Logging utility
│   │   └── file_handler.h/cpp     # File I/O utility
│   └── main.cpp                   # Application entry point
├── CMakeLists.txt                 # Root CMake configuration
└── README.md                      # This file
```

## Architecture

CalLib follows a **Service Locator** design pattern with dependency injection:

1. **Core Layer**: Abstract interfaces and application bootstrap
2. **Features Layer**: Concrete implementations of features
3. **Utilities Layer**: Common utilities (logging, file handling)
4. **UI Layer**: Qt-based user interface

## Development

### Adding a New Feature

1. Define interface in `src/core/interfaces/i_your_feature.h`
2. Implement feature in `src/features/your_feature/`
3. Register in `Application::initializeServices()` in `src/core/application.cpp`
4. Add to `src/features/CMakeLists.txt`

### Logging

Use the registered logger service:

```cpp
auto logger = core::ServiceLocator::get<core::interfaces::ILogger>();
logger->logInfo("Message");
logger->logError("Error message");
```

## Troubleshooting

### Qt6 not found

Make sure Qt6 is installed and in your PATH:

```bash
export Qt6_DIR=/usr/lib/qt6  # Adjust path as needed
```

### CMake configuration fails

Try:

```bash
rm -rf build/
mkdir build
cd build
cmake -DCMAKE_BUILD_TYPE=Release ..
make
```

## License

MIT License - See LICENSE file for details

## Contributing

Contributions are welcome! Please feel free to submit issues or pull requests.
