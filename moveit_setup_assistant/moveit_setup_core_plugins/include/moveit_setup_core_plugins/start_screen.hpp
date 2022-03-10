/*********************************************************************
 * Software License Agreement (BSD License)
 *
 *  Copyright (c) 2012, Willow Garage, Inc.
 *  All rights reserved.
 *
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions
 *  are met:
 *
 *   * Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 *   * Redistributions in binary form must reproduce the above
 *     copyright notice, this list of conditions and the following
 *     disclaimer in the documentation and/or other materials provided
 *     with the distribution.
 *   * Neither the name of Willow Garage nor the names of its
 *     contributors may be used to endorse or promote products derived
 *     from this software without specific prior written permission.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 *  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 *  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 *  FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 *  COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 *  INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 *  BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 *  LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 *  CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 *  LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 *  ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 *  POSSIBILITY OF SUCH DAMAGE.
 *********************************************************************/

#pragma once
#include <moveit_setup_framework/setup_step.hpp>
#include <moveit_setup_framework/data/package_settings_config.hpp>
#include <moveit_setup_framework/data/srdf_config.hpp>
#include <moveit_setup_framework/data/urdf_config.hpp>

namespace moveit_setup_core_plugins
{
class StartScreen : public moveit_setup_framework::SetupStep
{
public:
  std::string getName() const override
  {
    return "Start Screen";
  }

  void onInit() override;

  std::string getURDFPath();
  std::string getXacroArgs();
  std::string getPackagePath();
  std::string getURDFName();

  bool isXacroFile();

  void loadURDFFile(const std::string& urdf_file_path, const std::string& xacro_args);

  void loadExisting(const std::string& package_path);

  void setSRDFFile(const std::string& srdf_string);

protected:
  std::shared_ptr<moveit_setup_framework::PackageSettingsConfig> package_settings_;
  std::shared_ptr<moveit_setup_framework::SRDFConfig> srdf_config_;
  std::shared_ptr<moveit_setup_framework::URDFConfig> urdf_config_;
};
}  // namespace moveit_setup_core_plugins