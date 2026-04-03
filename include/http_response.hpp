// http_response.hpp - Declaration of the HttpResponse class
// After processing a request, the server sends back a response like:
//   HTTP/1.1 200 OK
//   Content-Type: text/html
//   <html>...</html>
// This class will build that response.

#ifndef HTTP_RESPONSE_HPP
#define HTTP_RESPONSE_HPP

class HttpResponse {
public:
    HttpResponse();
    ~HttpResponse();
};

#endif // HTTP_RESPONSE_HPP
