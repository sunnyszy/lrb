#ifndef LHD_VARIANTS_H
#define LHD_VARIANTS_H

#include <unordered_map>
#include <list>
#include "cache.h"
//#include "cache_object.h"

namespace cache {
    class Cache;
}


class LHDBase : public Cache
{
protected:
    cache::Cache* lhdcache;

public:
    LHDBase();

    virtual void setSize(uint64_t cs);
    virtual bool lookup(SimpleRequest& req);
    virtual void admit(SimpleRequest& req);
    virtual void evict(SimpleRequest& req);
    virtual void evict();
};


class LHDHyperbolic : public LHDBase
{
public:
    LHDHyperbolic();
};

static Factory<LHDHyperbolic> factoryHyperbolic("LHDHyperbolic");


class LHDSAMPLEDGDSF : public LHDBase
{
public:
    LHDSAMPLEDGDSF();
};

static Factory<LHDSAMPLEDGDSF> factoryLHDSAMPLEDGDSF("LHDSampledGDSF");


class LHDGDWheel : public LHDBase
{
public:
    LHDGDWheel();
};

static Factory<LHDGDWheel> factoryLHDGDWheel("LHDGDWheel");



#endif /* LHD_VARIANTS_H */
