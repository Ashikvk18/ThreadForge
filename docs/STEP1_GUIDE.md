# ThreadForge - Step 1 Visual Guide
# ===================================
# Read this file to understand EVERYTHING we built and WHY.
# All diagrams use plain text so you can read them right here.


# =====================================================================
# PART 1: WHAT IS A WEB SERVER?
# =====================================================================
#
# You already use web servers every day. Here's what happens when you
# type "google.com" in your browser:
#
#
#   YOU (Browser)                         GOOGLE (Server)
#   +-------------+                       +-------------+
#   |             |  --- "Hey, give me  -->|             |
#   |  Chrome /   |      your homepage    |  A computer |
#   |  Firefox    |                       |  running a  |
#   |             |  <-- "Here you go!" --|  program    |
#   +-------------+      (HTML page)      +-------------+
#
#
# That program running on Google's computer? That's a WEB SERVER.
# It just sits there, waiting for requests, and sends back answers.
#
# WE are building that program. In C++. From scratch.
#
# Our server won't run on Google's computer -- it will run on YOUR
# computer. But it works the same way.


# =====================================================================
# PART 2: WHAT IS ThreadForge?
# =====================================================================
#
# ThreadForge is our web server. When it's done, this will happen:
#
#   1. You run threadforge.exe
#   2. It starts listening on your computer (like picking up a phone)
#   3. You open your browser and go to: http://localhost:8080
#   4. ThreadForge receives your request
#   5. ThreadForge sends back the HTML page (public/index.html)
#   6. Your browser shows: "Hello from ThreadForge"
#
#
#   Your Browser                          ThreadForge (our program)
#   +-------------+                       +---------------------+
#   |             |  "GET /index.html" -->|                     |
#   | localhost:  |                       |  1. Read request     |
#   |   8080      |                       |  2. Find the file    |
#   |             |  <-- index.html ------|  3. Send it back     |
#   +-------------+                       +---------------------+
#
#
# But we're not there yet! Step 1 is just setting up the foundation.


# =====================================================================
# PART 3: WHY DO WE NEED SO MANY FILES?
# =====================================================================
#
# Think of building a car:
#
#   - You don't put the engine, seats, wheels, and radio
#     all in one giant blob. You build them SEPARATELY.
#
#   - Each part has ONE job.
#   - Each part can be tested alone.
#   - If the radio breaks, you fix the radio, not the engine.
#
# Same idea with code. Each file has ONE job:
#
#
#   +------------------+----------------------------------------+
#   | FILE             | JOB                                    |
#   +------------------+----------------------------------------+
#   | main.cpp         | Starts the program (turns the key)     |
#   | server.cpp       | Manages network connections (engine)   |
#   | thread_pool.cpp  | Manages worker threads (assembly line) |
#   | http_request.cpp | Reads what the browser asked for (ears)|
#   | http_response.cpp| Builds the answer to send back (mouth) |
#   | logger.cpp       | Prints status messages (dashboard)     |
#   +------------------+----------------------------------------+


# =====================================================================
# PART 4: WHAT IS A .hpp FILE vs .cpp FILE?
# =====================================================================
#
# You know classes in C++, right? Like:
#
#   class Dog {
#   public:
#       void bark();    // <-- DECLARATION: "I CAN bark"
#   };
#
#   void Dog::bark() {  // <-- IMPLEMENTATION: "Here's HOW I bark"
#       std::cout << "Woof!";
#   }
#
# In a real project, we SPLIT these into two files:
#
#
#   include/server.hpp          src/server.cpp
#   +---------------------+     +---------------------+
#   |                     |     |                     |
#   |  class Server {     |     |  #include           |
#   |  public:            |     |    "server.hpp"     |
#   |      Server();      |     |                     |
#   |      ~Server();     |     |  Server::Server() { |
#   |  };                 |     |    // actual code   |
#   |                     |     |  }                  |
#   | "Here's WHAT I can  |     |                     |
#   |  do"                |     | "Here's HOW I do it"|
#   +---------------------+     +---------------------+
#
#        MENU                        KITCHEN
#     (promises)                  (actual cooking)
#
#
# WHY split them?
#   - Other files only need the MENU (.hpp) to know what's available
#   - The KITCHEN (.cpp) can change without affecting anyone else
#   - It compiles faster (the compiler doesn't re-read everything)


# =====================================================================
# PART 5: OUR FOLDER STRUCTURE (AND WHY)
# =====================================================================
#
#   ThreadForge/
#   |
#   |-- include/            <-- All the MENUS (.hpp files)
#   |   |-- server.hpp
#   |   |-- thread_pool.hpp
#   |   |-- http_request.hpp
#   |   |-- http_response.hpp
#   |   |-- logger.hpp
#   |
#   |-- src/                <-- All the KITCHENS (.cpp files)
#   |   |-- main.cpp           (+ the entry point)
#   |   |-- server.cpp
#   |   |-- thread_pool.cpp
#   |   |-- http_request.cpp
#   |   |-- http_response.cpp
#   |   |-- logger.cpp
#   |
#   |-- public/             <-- Web pages to serve to browsers
#   |   |-- index.html
#   |
#   |-- docs/               <-- Teaching guides (you're here!)
#   |-- tests/              <-- Test code (coming later)
#   |
#   |-- CMakeLists.txt      <-- Build instructions
#   |-- README.md           <-- Project description
#   |-- PROJECT_LOG.md      <-- Our progress tracker
#   |-- .gitignore          <-- Tells Git what NOT to upload
#
#
# Rule of thumb:
#   - Headers (.hpp) go in include/
#   - Source  (.cpp) go in src/
#   - Anything the browser sees goes in public/


# =====================================================================
# PART 6: HOW DOES COMPILING WORK?
# =====================================================================
#
# You write C++ code. The computer can't run C++ directly.
# A COMPILER translates it into machine code (an .exe file).
#
#
#   Your Code (.cpp files)
#   +---------------------+
#   | #include <iostream>  |
#   | int main() {         |       COMPILER (g++)
#   |   cout << "Hello";   | ---> +-----------+ ---> threadforge.exe
#   |   return 0;          |      | Translates|      (machine code)
#   | }                    |      | C++ to    |
#   +---------------------+      | binary    |
#                                 +-----------+
#
#
# Our compile command:
#
#   g++                       <-- The compiler
#     -std=c++17              <-- Use modern C++ features
#     -I include              <-- "Look in include/ for .hpp files"
#     src/*.cpp               <-- "Compile ALL .cpp files in src/"
#     -o threadforge.exe      <-- "Name the output threadforge.exe"
#
#
# What happens step by step:
#
#   1. g++ reads main.cpp
#   2. main.cpp says #include "server.hpp"
#   3. g++ looks in include/ folder (because we said -I include)
#   4. g++ finds server.hpp and reads it
#   5. g++ compiles server.cpp (the implementation)
#   6. Repeat for ALL .cpp files
#   7. g++ LINKS everything together into one .exe file
#   8. Done! You can run threadforge.exe


# =====================================================================
# PART 7: WHAT DOES OUR CODE DO RIGHT NOW?
# =====================================================================
#
# Right now, not much! And that's on purpose.
#
#   main.cpp:
#     - Prints "ThreadForge server starting..."
#     - That's it!
#
#   Every other file:
#     - Has an empty class with a constructor and destructor
#     - Like building a car frame with no engine yet
#
#
#   CURRENT STATE:
#
#   +----main.cpp----+
#   |                 |
#   |  print message  |
#   |  exit           |
#   |                 |
#   +-----------------+
#
#   +---server---+ +--thread_pool--+ +--http_request--+
#   |            | |               | |                |
#   |  (empty)   | |   (empty)     | |    (empty)     |
#   |            | |               | |                |
#   +------------+ +---------------+ +----------------+
#
#   +--http_response--+ +---logger---+
#   |                 | |            |
#   |    (empty)      | |  (empty)   |
#   |                 | |            |
#   +-----------------+ +------------+
#
#   All shells. No logic yet. That comes in Step 2!


# =====================================================================
# PART 8: THE BIG PICTURE - HOW IT WILL ALL CONNECT
# =====================================================================
#
# Here's the full architecture we're building toward:
#
#
#   Browser makes request
#        |
#        v
#   +=========================================+
#   |              SERVER                      |
#   |                                          |
#   |   1. Socket listens on port 8080         |
#   |   2. New connection arrives!             |
#   |   3. Hand it to the Thread Pool          |
#   |                                          |
#   |   +-----------------------------------+  |
#   |   |         THREAD POOL               |  |
#   |   |                                   |  |
#   |   |  Worker 1: [busy with client A]   |  |
#   |   |  Worker 2: [handling client B]    |  |
#   |   |  Worker 3: [waiting for work...]  |  |<-- Reuses threads!
#   |   |  Worker 4: [waiting for work...]  |  |
#   |   |                                   |  |
#   |   +-----------------------------------+  |
#   |        |                                 |
#   |        v                                 |
#   |   +--------------+    +--------------+   |
#   |   | HTTP REQUEST |    | HTTP RESPONSE|   |
#   |   | "What did    |--->| "Build the   |   |
#   |   |  they ask?"  |    |  answer"     |   |
#   |   +--------------+    +--------------+   |
#   |                            |             |
#   |                            v             |
#   |                     Send response        |
#   |                     back to browser      |
#   |                                          |
#   |   +-----------------------------------+  |
#   |   |            LOGGER                 |  |
#   |   | [INFO] New connection from 1.2.3.4|  |
#   |   | [INFO] GET /index.html            |  |
#   |   | [INFO] Response: 200 OK           |  |
#   |   +-----------------------------------+  |
#   |                                          |
#   +==========================================+
#
#
# Each box = one of our files. They work TOGETHER like a team.


# =====================================================================
# PART 9: WHAT IS #ifndef / #define / #endif? (Header Guards)
# =====================================================================
#
# You saw this at the top of every .hpp file:
#
#   #ifndef SERVER_HPP
#   #define SERVER_HPP
#   ...
#   #endif
#
# Why? Imagine this:
#
#   file_a.cpp:  #include "server.hpp"
#   file_b.cpp:  #include "server.hpp"
#   file_c.cpp:  #include "server.hpp"  AND  #include "file_a.hpp"
#                                             (which also includes server.hpp!)
#
# Without guards, the compiler sees class Server TWICE in file_c.
# It gets confused: "Wait, you already defined this!"
#
# Header guards say:
#   "If you've already read this file, SKIP IT."
#
#   First time:   SERVER_HPP is NOT defined --> read the file, define it
#   Second time:  SERVER_HPP IS defined     --> skip everything
#
# It's like a bouncer at a club: "Already inside? You can't enter again."


# =====================================================================
# PART 10: WHAT'S NEXT? (Step 2 Preview)
# =====================================================================
#
# In Step 2, we'll learn about SOCKETS.
#
# A socket is how programs talk over a network.
# Think of it like a phone:
#
#   1. Buy a phone           = create a socket
#   2. Get a phone number    = bind to a port (like 8080)
#   3. Turn it on            = start listening
#   4. Someone calls         = a browser connects
#   5. You answer            = accept the connection
#   6. You talk              = send/receive data
#   7. Hang up               = close the connection
#
#   Step 2 will fill in server.hpp and server.cpp with this logic.
#
# =====================================================================
# END OF STEP 1 GUIDE
# =====================================================================
