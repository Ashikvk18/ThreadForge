# ThreadForge - Development Log

---

## Step 1: Project Setup

**Status:** ✅ Complete

**What was done:**
- Created folder structure: `include/`, `src/`, `public/`, `docs/`, `tests/`
- Created placeholder classes: Server, ThreadPool, HttpRequest, HttpResponse, Logger
- Created `CMakeLists.txt` for build configuration
- Created `public/index.html` with a simple test page
- Created `main.cpp` that prints "ThreadForge server starting..."

**Files added:**
- `CMakeLists.txt`
- `src/main.cpp`
- `include/server.hpp` / `src/server.cpp`
- `include/thread_pool.hpp` / `src/thread_pool.cpp`
- `include/http_request.hpp` / `src/http_request.cpp`
- `include/http_response.hpp` / `src/http_response.cpp`
- `include/logger.hpp` / `src/logger.cpp`
- `public/index.html`
- `README.md`

**Build command (using MSYS2 bash):**
```
C:\msys64\usr\bin\bash.exe -c "export PATH=/ucrt64/bin:/usr/bin:$PATH; cd /c/Users/ashik/Desktop/ThreadForge; g++ -std=c++17 -I include src/*.cpp -o threadforge.exe"
```

**Verified:** Compiles and prints "ThreadForge server starting..."

**Next step:**
- Step 2: Build a basic TCP socket server (listen for connections)
