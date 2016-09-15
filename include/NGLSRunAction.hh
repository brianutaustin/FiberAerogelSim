#ifndef NGLSRunAction_h
#define NGLSRunAction_h 1

#include "G4UserRunAction.hh"
#include "globals.hh"

class G4Run;

class NGLSRunAction : public G4UserRunAction {
  public:
    NGLSRunAction();
    virtual ~NGLSRunAction();

    virtual void BeginOfRunAction(const G4Run* run);
    virtual void EndOfRunAction(const G4Run* run);
};

#endif
