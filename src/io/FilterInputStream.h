// FilterInputStream.h: interface for the FilterInputStream class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_FILTERINPUTSTREAM_H__F7D22593_2F6D_4AFF_BD06_661F601D9660__INCLUDED_)
#define AFX_FILTERINPUTSTREAM_H__F7D22593_2F6D_4AFF_BD06_661F601D9660__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/// namespace stream
namespace stream
{
/// namespace io
namespace io
{

class FilterInputStream  
{
public:
	FilterInputStream(std::auto_ptr<IDataProcessor> processor,io::IInputStream* input);
	virtual ~FilterInputStream();

	///Returns the number of bytes that can be read (or skipped over) from this input stream without blocking by the next caller of a method for this input stream. 
	virtual int available();
	///Closes this input stream and releases any system resources associated with the stream. 
	virtual void close();
	///Marks the current position in this input stream. 
	virtual void mark(int readlimit);
	///Tests if this input stream supports the mark and reset methods. 
	virtual bool markSupported();
	///Reads the next byte of data from the input stream. 
	/// Return 0 if no more data available. DON'T USE THIS METHOD USE "int read(unsigned char* b,long length)" instead.
	virtual int read();
	///Reads some number of bytes from the input stream and stores them into the buffer array b. 
	virtual int read(unsigned char* b,long length);
	///Reads up to len bytes of data from the input stream into an array of bytes. 
	virtual int read(unsigned char* b, int off, int len);
	///Repositions this stream to the position at the time the mark method was last called on this input stream. 
	virtual void reset();
	///Skips over and discards n bytes of data from this input stream. 
	virtual long skip(long n);


private:
	io::Blob<unsigned char> m_cache;

	std::auto_ptr<IDataProcessor> m_processor;
	io::IInputStream* m_input;
};

} // namespace io

} // namespace stream

#endif // !defined(AFX_FILTERINPUTSTREAM_H__F7D22593_2F6D_4AFF_BD06_661F601D9660__INCLUDED_)
