#ifndef _STREAM_BUFFER_H_
#define _STREAM_BUFFER_H_

#ifdef SPARK
#include "application.h"
#else
#include "Arduino.h"
#endif

#include "QueueArray.h"

class StreamBuffer : public Stream {
  public:
    StreamBuffer();
    StreamBuffer(QueueArray<unsigned char> *buf);
    
    // int read(uint8_t *buf, size_t size);
    void flush();
    int available();
    int read();
    size_t write(uint8_t c);
    size_t write(char *payload, size_t length);

    int peek();

  private:
    QueueArray<unsigned char> *_buf;
};

#endif // _STREAM_BUFFER_H_
