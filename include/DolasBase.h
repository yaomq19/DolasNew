#ifndef DOLAS_BASE_H
#define DOLAS_BASE_H

class DolasBase
{
public:
    DolasBase() = default;
    virtual ~DolasBase() = default;

    virtual bool Initialize(){};
    virtual void Clear(){};
};
#endif