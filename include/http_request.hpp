// http_request.hpp - Declaration of the HttpRequest class
// When a browser visits your server, it sends an HTTP request like:
//   GET /index.html HTTP/1.1
// This class will parse that raw text into something we can work with.

#ifndef HTTP_REQUEST_HPP
#define HTTP_REQUEST_HPP

class HttpRequest {
public:
    HttpRequest();
    ~HttpRequest();
};

#endif // HTTP_REQUEST_HPP
