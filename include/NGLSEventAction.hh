#ifndef NGLSEventAction_h
#define NGLSEventAction_h 1

#include "G4UserEventAction.hh"

#include "globals.hh"

class NGLSEventAction : public G4UserEventAction {
  public:
    NGLSEventAction();
    virtual ~NGLSEventAction();

    virtual void  BeginOfEventAction(const G4Event* );
    virtual void  EndOfEventAction(const G4Event* );
};

#endif
