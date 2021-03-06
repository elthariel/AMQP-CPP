/**
 *  ByteByffer.h
 *
 *  Very simple implementation of the buffer class that simply wraps
 *  around a buffer of bytes
 *
 *  @author Emiel Bruijntjes <emiel.bruijntjes@copernica.com>
 *  @copyright 2014 Copernica BV
 */

/**
 *  Include guard
 */
#pragma once

/**
 *  Open namespace
 */
namespace AMQP {

/**
 *  Class definition
 */
class ByteBuffer : public Buffer
{
private:
    /**
     *  The actual byte buffer
     *  @var const char *
     */
    const char *_data;
    
    /**
     *  Size of the buffer
     *  @var size_t
     */
    size_t _size;

public:
    /**
     *  Constructor
     *  @param  data
     *  @param  size
     */
    ByteBuffer(const char *data, size_t size) : _data(data), _size(size) {}
    
    /**
     *  Destructor
     */
    virtual ~ByteBuffer() {}

    /**
     *  Total size of the buffer
     *  @return size_t
     */
    virtual size_t size() const override
    {
        return _size;
    }

    /**
     *  Get access to a single byte
     *  @param  pos         position in the buffer
     *  @return char        value of the byte in the buffer
     */
    virtual char byte(size_t pos) const override
    {
        return _data[pos];
    }

    /**
     *  Get access to the raw data
     *  @param  pos         position in the buffer
     *  @param  size        number of continuous bytes
     *  @return char*
     */
    virtual const char *data(size_t pos, size_t size) const override
    {
        return _data + pos;
    }
    
    /**
     *  Copy bytes to a buffer
     *  @param  pos         position in the buffer
     *  @param  size        number of bytes to copy
     *  @param  buffer      buffer to copy into
     *  @return size_t      pointer to buffer
     */
    virtual void *copy(size_t pos, size_t size, void *buffer) const override
    {
        return memcpy(buffer, _data + pos, size);
    }
};

/**
 *  End namespace
 */
}
