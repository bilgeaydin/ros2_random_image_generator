/*!
 * \copyright (C) 2026 Bilge Aydin. All rights reserved.
 *
 * PROPRIETARY/CONFIDENTIAL
 *
 * This software is the confidential and proprietary information of
 * Bilge Aydin ("Confidential Information"). You shall not
 * disclose such Confidential Information and shall use it only in
 * accordance with the terms of the license agreement you entered
 * into with Bilge Aydin.  Bilge Aydin make no representations
 * or warranties about the suitability of the software, either
 * express or implied, including but not limited to the implied
 * warranties of merchantability, fitness for a particular purpose,
 * or non-infringement. Bilge Aydin shall not be liable for any damages
 * suffered by licensee as a result of using, modifying or distributing
 * this software or its derivatives.
 */

#include "node.h"

int main(int argc, char *argv[]) {
  rclcpp::init(argc, argv);
  // create a ros2 node
  auto node = std::make_shared<BilgeRandomImageGeneratorNode>();
  // process ros2 callbacks until receiving a SIGINT (ctrl-c)
  rclcpp::spin(node);
  rclcpp::shutdown();
  return 0;
}