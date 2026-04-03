# ThreadForge

A multithreaded HTTP web server built from scratch in C++.

## Goal

Learn networking, threading, and HTTP by building a real server — one step at a time.

## Build

```bash
g++ -std=c++17 -I include src/*.cpp -o threadforge
./threadforge
```

## Project Structure

```
ThreadForge/
├── CMakeLists.txt        # Build configuration
├── README.md             # This file
├── PROJECT_LOG.md        # Step-by-step progress log
├── include/              # Header files (.hpp)
├── src/                  # Source files (.cpp)
├── public/               # Static web files (HTML, CSS, etc.)
├── docs/                 # Documentation
└── tests/                # Unit tests
```
