#pragma once

#include <string>

class Texture {
public:
    Texture();
    ~Texture();

    void LoadFromFile(const std::string& path);
    void Bind() const;
    // void Unbind() const;
private:
    unsigned int id;
};