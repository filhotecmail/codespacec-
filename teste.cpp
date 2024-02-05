// main.cpp

#include <iostream>
#include "functional.filedownloads.h"

int main()
{

    FileDownloader::Build([](IFileDownLoad::FilesControl &filesControl, IFileDownLoad::Events &ev)
                          {
                              filesControl.addFile({
                                  "Curso gratuito de Linux",
                                  "link1",
                                  "/dirA",
                                  []()
                                  {
                                      std::cout << "Ação após o download do Curso gratuito de Linux...\n";
                                  },
                                  []()
                                  {
                                      std::cerr << "Ação em caso de erro para o Curso gratuito de Linux...\n";
                                  },

                              });

                              filesControl.addFile({
                                  "Download do ISO Ubuntu",
                                  "link2",
                                  "/dirB",
                                  []()
                                  {
                                      std::cout << "Ação após o download do Download do ISO Ubuntu...\n";
                                  },
                                  []()
                                  {
                                      std::cerr << "Ação em caso de erro para o Download do ISO Ubuntu...\n";
                                  },

                              });

                              filesControl.addFile({
                                  "Mega Hits Beyoncé",
                                  "link3",
                                  "/DirC",
                                  []()
                                  {
                                      std::cout << "Ação após o download do Mega Hits Beyoncé...\n";
                                  },
                                  []()
                                  {
                                      std::cerr << "Ação em caso de erro para o Mega Hits Beyoncé...\n";
                                  },

                              });

                              filesControl.removeFile("Download do iso Ubuntu");

                              ev.onJob = [](std::vector<FileDownloader::FileConfig>)
                              {
                                  std::cout << "Lendo dados de progresso dos downloads ......\n";
                              };

                              ev.onErrors = [](std::vector<FileDownloader::FileConfig>)
                              {
                                  std::cerr << "Erros que serão disparados caso aconteçam falhas no processo de Download\n";
                              };

                              ev.onFinished = [](std::vector<FileDownloader::FileConfig>)
                              {
                                  std::cerr << "Erros que serão disparados caso aconteçam falhas no processo de Download\n";
                              };

                              ev.onPause = [](std::vector<FileDownloader::FileConfig>)
                              {
                                  std::cerr << "Erros que serão disparados caso aconteçam falhas no processo de Download\n";
                              };

                              ev.onResume = [](std::vector<FileDownloader::FileConfig>)
                              {
                                  std::cerr << "Erros que serão disparados caso aconteçam falhas no processo de Download\n";
                              };

                              ev.onAbort = [](std::vector<FileDownloader::FileConfig>)
                              {
                                  std::cerr << "Erros que serão disparados caso aconteçam falhas no processo de Download\n";
                              };
                          })
        .Manager()
          .StartAll()
            .Pause("Mega Hits Beonce")
             .ResumeAll()
          .Abort("Curso gratuito de linux")
        .AbortAll();

    return 0;
}
