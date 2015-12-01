
#include "TiActor/actor/Actor.h"
#include "TiActor/actor/ActorSystem.h"
#include "TiActor/actor/ActorSystemImpl.h"
#include "TiActor/actor/ActorCell.h"

#include "TiActor/basic/threadlocal.h"

namespace TiActor {

TI_THREAD_LOCAL ActorCell * InternalCurrentActorCellKeeper::current_ = nullptr;

ActorSystem * ActorSystemImpl::createSystemImpl(const std::string & name, const Config & config) {
	ActorSystem * system = new ActorSystemImpl(name, config);
	return system;
}

ActorSystem * ActorSystemImpl::createAndStartSystemImpl(const std::string & name, const Config & config) {
	ActorSystem * system = new ActorSystemImpl(name, config);
	if (system) {
		system->start();
	}
	return system;
}

// IActorRefFactory
IActorRef * ActorSystemImpl::actorOf(const Props * props, const std::string & name) {
    IActorRef * actorNew = ActorSystem::findActorRef(props, name);
    if (actorNew == nullptr) {
        Actor * actor = new Actor(name, this);
        if (actor) {
            ActorSystem::addActor(name, actor);
            actorNew = actor->getSelf();
            actor->start();
        }
    }
    return actorNew;
}

} // namespace TiActor
