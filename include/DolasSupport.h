#ifndef DOLAS_SUPPORT_H
#define DOLAS_SUPPORT_H

#define DOLAS_NEW(T) \
new T();

#define DOLAS_DELETE(ptr) \
if (ptr) \
{ \
    delete ptr; \
    ptr = nullptr; \
}

#endif // DOLAS_SUPPORT_H