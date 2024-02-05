#ifndef LOADER_H
#define LOADER_H

#include <functional>
#include <vector>
#include <string>
#include <iostream>

class IFileDownLoad
{
public:     
    enum StateFile { STF_PROGRESS, STF_PAUSED, STF_ABORTED  };
    struct FileConfig    
    {
        
        std::string filename;
        std::string link;
        std::string destiny;
        std::function<void()> actionBeforeDownload;
        std::function<void()> actionAfterDownload;
        std::function<void()> actionOnErrorDownload;
        StateFile state;
    };

    std::vector<FileConfig> files;

    struct FilesControl
    {
        FilesControl addFile(FileConfig arg)
        {
            return *this;
        }
        FilesControl removeFile(std::string filename)
        {
            return *this;
        }
    };



    struct Events
    {
        std::function<void(std::vector<FileConfig>)> onJob;
        std::function<void(std::vector<FileConfig>)> onFinished;
        std::function<void(std::vector<FileConfig>)> onPause;
        std::function<void(std::vector<FileConfig>)> onResume;
        std::function<void(std::vector<FileConfig>)> onAbort;
        std::function<void(std::vector<FileConfig>)> onErrors;
    };

    struct Controls
    {
        Controls StartAll()
        {
            return *this;
        };

        Controls Start(std::string filename)
        {
            return *this;
        };

        Controls PauseAll()
        {
            return *this;
        };

        Controls Pause(std::string filename)
        {
            return *this;
        }

        Controls ResumeAll()
        {
            return *this;
        };

        Controls Resume(std::string filename)
        {
            return *this;
        }

        Controls AbortAll()
        {
            return *this;
        };

        Controls Abort(std::string filename)
        {
            return *this;
        }
    };

    using Callback = std::function<void(FilesControl &, Events &)>;

    IFileDownLoad();

    static IFileDownLoad Build(Callback callback);
    Controls Manager()
    {
        return Controls{};
    }

private:
};

class FileDownloader : public IFileDownLoad
{
public:
    FileDownloader();

    Controls Manager()
    {
        return Controls{};
    }
};

#endif
