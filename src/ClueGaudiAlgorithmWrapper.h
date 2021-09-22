#ifndef CLUE_GAUDI_ALGORITHM_WRAPPER_H
#define CLUE_GAUDI_ALGORITHM_WRAPPER_H

#include <GaudiAlg/GaudiAlgorithm.h>

// FWCore
#include <k4FWCore/DataHandle.h>

#include <edm4hep/CalorimeterHitCollection.h>

class ClueGaudiAlgorithmWrapper : public GaudiAlgorithm {
public:
  explicit ClueGaudiAlgorithmWrapper(const std::string& name, ISvcLocator* svcLoc);
  virtual ~ClueGaudiAlgorithmWrapper() = default;
  virtual StatusCode execute() override final;
  virtual StatusCode finalize() override final;
  virtual StatusCode initialize() override final;

  void runAlgo(std::vector<float>& x, std::vector<float>& y, std::vector<int>& layer, std::vector<float>& weight,
               std::string outputFileName,
               bool verbose  );

  private:
  // Parameters in input
  float dc;
  float rhoc;
  float outlierDeltaFactor;

  std::vector<float> x;
  std::vector<float> y;
  std::vector<int> layer;
  std::vector<float> weight;

  // Collections in output
  DataHandle<edm4hep::CalorimeterHitCollection> clustersHandle{"Output_hits", Gaudi::DataHandle::Writer, this};

};

#endif
