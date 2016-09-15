#ifndef NGLSActionInitialization_h
#define NGLSActionInitialization_h 1

#include "G4VUserActionInitialization.hh"

class NGLSDetectorConstruction;

class NGLSActionInitialization : public G4VUserActionInitialization {
  public:
    NGLSActionInitialization();
    virtual ~NGLSActionInitialization();

    virtual void BuildForMaster() const;
    virtual void Build() const;
};

#endif
