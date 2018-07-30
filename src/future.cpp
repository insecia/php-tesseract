#include "future.h"

namespace tesseract { namespace php {

    zend_object_handlers Future::handler_future = zend_object_handlers();

    zend_object* Future::create_object(zend_class_entry* ce TSRMLS_CC)
    {
        Future* intern = (Future*)ecalloc(1, sizeof(Future) + zend_object_properties_size(ce));

        zend_object_std_init(&intern->std, ce TSRMLS_CC);

        intern->std.handlers = &Future::handler_future;
        return &intern->std;
    }

    Future* Future::fetch_object(zend_object* obj)
    {
        return (Future *)((char *)obj - XtOffsetOf(Future, std));
    }

    Future::Future(std::shared_future<char*> future): future(future)
    {
    }

    char* Future::get()
    {
        return this->future.get();
    }

}}
