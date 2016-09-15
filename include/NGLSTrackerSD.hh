#ifndef NGLSTrackerSD_h
#define NGLSTrackerSD_h 1

#include "G4VSensitiveDetector.hh"

#include "NGLSTrackerHit.hh"

#include <vector>

class G4Step;
class G4HCofThisEvent;

class NGLSTrackerSD : public G4VSensitiveDetector {
  public:
    NGLSTrackerSD(const G4String& name, const G4String& hitsCollectionName);
    virtual ~NGLSTrackerSD();

    // methods from base class
    virtual void   Initialize(G4HCofThisEvent* hitCollection);
    virtual G4bool ProcessHits(G4Step* step, G4TouchableHistory* history);
    virtual void   EndOfEvent(G4HCofThisEvent* hitCollection);

  private:
    NGLSTrackerHitsCollection* fHitsCollection;
};

#endif
