// server.hpp - Declaration of the Server class
// This class will manage the entire web server:
//   - Opening a network socket
//   - Listening for incoming connections
//   - Handing connections off to worker threads

#ifndef SERVER_HPP
#define SERVER_HPP

class Server {
public:
    Server();
    ~Server();
};

#endif // SERVER_HPP
