
#ifndef TIACTOR_ACTOR_ACTORBASE_H
#define TIACTOR_ACTOR_ACTORBASE_H

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

#include <string>
#include <iostream>

#include "TiActor/basic/stddef.h"
#include "TiActor/actor/IInternalActorRef.h"
#include "TiActor/actor/IActorContext.h"
#include "TiActor/actor/IActorRef.h"

namespace TiActor {

class ActorSystem;

class IInternalActor {
public:
    virtual IActorContext * getActorContext() const = 0;
};

class ActorBase : public IInternalActor {
protected:
    std::string name_;
    IActorRef * clearedSelf_;
    IActorContext * context_;

public:
    ActorBase() : clearedSelf_(nullptr), context_(nullptr) {
        initActor("default");
    }

    ActorBase(const std::string & name, ActorSystem * parent = nullptr)
     : clearedSelf_(nullptr), context_(nullptr) {
        initActor(name);
    }

    ActorBase(const ActorBase & src) {
        cloneActor(src);
    }

    ~ActorBase() {
    }

private:
    void initActor(const std::string & name) {
        name_ = name;
    }

    bool hasBeenCleared() const {
        return (clearedSelf_ != nullptr);
    }

protected:
    void cloneActor(const ActorBase & src) {
        this->name_ = src.name_;
    }

public:
    // For IActorContext
    Props * getProps() const        { return ((getContext() != nullptr) ? getContext()->getProps() : nullptr); }
    IActorRef * getSelf() const {
        return (hasBeenCleared() ? clearedSelf_ : ((getContext() != nullptr) ? getContext()->getSelf() : nullptr));
    }
    IActorRef * getSender() const   { return ((getContext() != nullptr) ? getContext()->getSender() : nullptr); }
    IActorRef * getParent() const   { return ((getContext() != nullptr) ? getContext()->getParent() : nullptr); }
    IActorRef * getChild() const    { return ((getContext() != nullptr) ? getContext()->getChild()  : nullptr); }
    ActorSystem * getSystem() const { return ((getContext() != nullptr) ? getContext()->getSystem() : nullptr); }
    
    // For call IActorContext
    IActorContext * getContext() const { return context_; }
    void setContext(IActorContext * context) { context_ = context; }

    // IInternalActor
    IActorContext * getActorContext() const override {
        return this->getContext();
    }

    void clear(IActorRef * self) {
        clearedSelf_ = self;
    }

    void unclear() {
        clearedSelf_ = nullptr;
    }

    std::string getName() const {
        return name_;
    }

    void setName(const std::string & name) {
        name_ = name;
    }

    void Unhandle(MessageObject message) {
        std::cout << ">>> Unhandle Message <<<" << std::endl;
        std::cout << "Message Object: " << message << "." << std::endl;
        std::cout << ">>> ---------------- <<<" << std::endl;
    }

    void Unhandle(const std::string & className, MessageObject message) {
        std::cout << ">>> Class " << className << " unknown message. <<<" << std::endl;
        std::cout << "Message Object: " << message << "." << std::endl;
        std::cout << ">>> ---------------- <<<" << std::endl;
    }
};

} // namespace TiActor

#endif  /* TIACTOR_ACTOR_ACTORBASE_H */
