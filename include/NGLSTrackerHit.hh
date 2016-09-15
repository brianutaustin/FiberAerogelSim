#ifndef NGLSTrackerHit_h
#define NGLSTrackerHit_h 1

#include "G4VHit.hh"
#include "G4THitsCollection.hh"
#include "G4Allocator.hh"
#include "G4ThreeVector.hh"
#include "tls.hh"

class NGLSTrackerHit : public G4VHit {
  public:
    NGLSTrackerHit();
    NGLSTrackerHit(const NGLSTrackerHit&);
    virtual ~NGLSTrackerHit();

    // operators
    const NGLSTrackerHit& operator=(const NGLSTrackerHit&);
    G4int operator==(const NGLSTrackerHit&) const;

    inline void* operator new(size_t);
    inline void  operator delete(void*);

    // methods from base class
    virtual void Draw();
    virtual void Print();

    // Set methods
    void SetTrackID  (G4int track)      { fTrackID = track; };
    void SetChamberNb(G4int chamb)      { fChamberNb = chamb; };
    void SetEdep     (G4double de)      { fEdep = de; };
    void SetPos      (G4ThreeVector xyz){ fPos = xyz; };

    // Get methods
    G4int GetTrackID() const     { return fTrackID; };
    G4int GetChamberNb() const   { return fChamberNb; };
    G4double GetEdep() const     { return fEdep; };
    G4ThreeVector GetPos() const { return fPos; };

  private:

      G4int         fTrackID;
      G4int         fChamberNb;
      G4double      fEdep;
      G4ThreeVector fPos;
};

typedef G4THitsCollection<NGLSTrackerHit> NGLSTrackerHitsCollection;

extern G4ThreadLocal G4Allocator<NGLSTrackerHit>* NGLSTrackerHitAllocator;

inline void* NGLSTrackerHit::operator new(size_t) {
  if(!NGLSTrackerHitAllocator)
      NGLSTrackerHitAllocator = new G4Allocator<NGLSTrackerHit>;
  return (void *) NGLSTrackerHitAllocator->MallocSingle();
}

inline void NGLSTrackerHit::operator delete(void *hit) {
  NGLSTrackerHitAllocator->FreeSingle((NGLSTrackerHit*) hit);
}

#endif
