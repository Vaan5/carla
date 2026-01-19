// Copyright (c) 2025 Computer Vision Center (CVC) at the Universitat Autonoma
// de Barcelona (UAB).
//
// This work is licensed under the terms of the MIT license.
// For a copy, see <https://opensource.org/licenses/MIT>.
//
// Additional functionality added by AVL List GmbH under the terms of the MIT license.

#pragma once

#include <sstream>
#include <vector>
#include "Carla/Vehicle/CarlaWheeledVehicle.h"

#pragma pack(push, 1)
struct WheelInfo
{
  uint8_t Idx = 0U;
  float SteeringAngle = 0.0f;
  float TireRotation = 0.0f;

  void Read(std::istream &InFile);
  void Write(std::ostream &OutFile) const;
};

#pragma pack(pop)
#pragma pack(push, 1)
struct CarlaRecorderAnimWheels
{
  uint32_t DatabaseId;
  std::vector<WheelInfo> WheelValues;

  void Read(std::istream &InFile);
  void Write(std::ostream &OutFile);
};
#pragma pack(pop)

class CarlaRecorderAnimVehicleWheels
{
public:

  void Add(const CarlaRecorderAnimWheels &InObj);

  void Clear(void);

  void Write(std::ostream &OutFile);

  void Read(std::istream &InFile);

  const std::vector<CarlaRecorderAnimWheels>& GetVehicleWheels();
private:

  std::vector<CarlaRecorderAnimWheels> VehicleWheels;
};
