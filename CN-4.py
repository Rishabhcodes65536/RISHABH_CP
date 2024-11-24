from http.server import BaseHTTPRequestHandler, HTTPServer
import time
import http.cookies as Cookies
class MyServer(BaseHTTPRequestHandler):

    def do_GET(self):
        self.send_response(200)
        self.send_header("Content-type", "text/html")
        self.end_headers()
        self.wfile.write(b"Welcome to my beautiful server")
    def do_HEAD(self):
        self.send_response(200)
        self.send_header("Content-type", "text/html")
        self.end_headers()
    def do_POST(self):
        content_length = int(self.headers['Content-Length'])
        post_data = self.rfile.read(content_length)
        self.send_response(200)
        self.send_header('Content-type', 'text/html')
        self.end_headers()
        self.wfile.write(b'POST request for ' + self.path.encode('utf-8') + post_data)
    def do_PUT(self):
        content_length = int(self.headers['Content-Length'])
        put_data = self.rfile.read(content_length)
        self.send_response(200)
        self.send_header('Content-type', 'text/html')
        self.end_headers()
        self.wfile.write(b'PUT request for ' + self.path.encode('utf-8') + put_data)
    def do_DELETE(self):
        self.send_response(200)
        self.send_header('Content-type', 'text/html')
        self.end_headers()
        self.wfile.write(b'DELETED' + self.path.encode('utf-8'))
    def send_cookie(self):
        cookie = Cookies.SimpleCookie()
        cookie['session'] = '123456789'
        self.send_header('Set-Cookie', cookie.output(header='', sep=''))
    def read_cookie(self):
        if 'Cookie' in self.headers:
            cookie = Cookies.SimpleCookie(self.headers['Cookie'])
            session_id = cookie['session'].value
            return session_id
        else:
            return None


def run():
    host_name = '192.168.1.14'
    host_port = 8081
    server = HTTPServer((host_name, host_port), MyServer)
    print(f'Server started http://{host_name}:{host_port}')

    try:
        server.serve_forever()
    except KeyboardInterrupt:
        pass

    server.server_close()
    print(f'Server stopped http://{host_name}:{host_port}')
if __name__ == '__main__':
    run()
