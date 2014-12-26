#ifndef ZIPCOMPRESS_H
#define ZIPCOMPRESS_H
#include <string>
#include <functional>
#include <Windows.h>
#include <ppltasks.h>

DWORD WINAPI ZipCompressThread(LPVOID lParam);

class ZipCompress{
    public:
        enum MessageReportCode{
            REPORT_FAILD=0,
            REPORT_WARNING=1,
            REPORT_ASK=2
        };
        ZipCompress();
        ~ZipCompress();
        void SetMessageThrow(std::function<bool(std::wstring,int)> fun)
        {
            this->MessageThrow=fun;
        }
    private:
        int iRet;
        std::function<bool(std::wstring,int)> MessageThrow;
    public:
        bool CreateCompressBuffer(BYTE* buffer,/**/size_t* bszie,std::wstring zipfile);
        bool CreateCompressBufferToBuffer(BYTE *buffer,size_t *bsize,BYTE *dest,size_t *dsize);
        bool CreateCompressFile(std::wstring sourcefile,/*OutDir*/std::wstring zipfile);
        bool UnCompressToBuffer(std::wstring zipfile,BYTE*dest,size_t *destlen);
        bool UnCompressToDisk(std::wstring zipfile,std::wstring folder);
};

//Asynchronous Compress:
class ZipAsynchronousCompress{
private:
    std::wstring filePath;
    std::function<bool(int)> NotifyFunction;
public:
    ZipAsynchronousCompress(std::wstring filepath);
    ~ZipAsynchronousCompress();
    void SetAsynchronousNotify(std::function<bool(int)> fun);
};

#endif
