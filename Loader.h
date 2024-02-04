#ifndef LOADER_H
#define LOADER_H

#include <functional>
#include <vector>
#include <string>
#include <iostream>

class Loader
{
public:
    struct FileConfig
    {
        std::string filename;
        std::string destiny;
    };

    struct Events
    {
        std::function<void()> onJob;
        std::function<void()> onErrors;
    };

    using Callback = std::function<void(Loader &)>;

    Loader() {}

    static Loader Build(Callback callback)
    {
        Loader loader;
        callback(loader);
        return loader;
    }

    Loader &Files(const std::vector<FileConfig> &fileConfigs)
    {
        this->fileConfigs = fileConfigs;
        return *this;
    }

    Loader &Events(const std::function<void(Events &)> &eventsCallback)
    {
      
        return *this;
    }

    Loader &Download()
    {
        for (const auto &config : fileConfigs)
        {
            std::cout << "Downloading file: " << config.filename << " to " << config.destiny << "\n";
            // Lógica para download do arquivo
        }
        return *this;
    }

private:
    std::vector<FileConfig> fileConfigs;
    
};

#endif // LOADER_H