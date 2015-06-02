
// DO NOT EDIT THIS FILE - it is machine generated -*- c++ -*-

#ifndef __javax_imageio_stream_FileImageOutputStream__
#define __javax_imageio_stream_FileImageOutputStream__

#pragma interface

#include <javax/imageio/stream/ImageOutputStreamImpl.h>
#include <gcj/array.h>

extern "Java"
{
  namespace javax
  {
    namespace imageio
    {
      namespace stream
      {
          class FileImageOutputStream;
      }
    }
  }
}

class javax::imageio::stream::FileImageOutputStream : public ::javax::imageio::stream::ImageOutputStreamImpl
{

public:
  FileImageOutputStream(::java::io::File *);
  FileImageOutputStream(::java::io::RandomAccessFile *);
  virtual void close();
  virtual jlong length();
  virtual jint read();
  virtual jint read(JArray< jbyte > *, jint, jint);
  virtual void seek(jlong);
  virtual void write(JArray< jbyte > *, jint, jint);
  virtual void write(jint);
private:
  ::java::io::RandomAccessFile * __attribute__((aligned(__alignof__( ::javax::imageio::stream::ImageOutputStreamImpl)))) file;
public:
  static ::java::lang::Class class$;
};

#endif // __javax_imageio_stream_FileImageOutputStream__