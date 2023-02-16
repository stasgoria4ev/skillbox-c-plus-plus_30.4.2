#include <iostream>
#include <cpr/cpr.h>

int main() {
    cpr::Response r = cpr::Get(cpr::Url("http://httpbin.org/html"),
                               cpr::Header({{"Accept", "text/html"}}));

    unsigned int h1 = r.text.find("<h1>");
    unsigned int h2 = r.text.find("</h1>");

    std::cout << r.text.substr(h1 + 4, h2 - h1 - 4) << "\n";
}