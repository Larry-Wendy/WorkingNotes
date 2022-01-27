# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "")
  file(REMOVE_RECURSE
  "/home/maoyuxuan/esp/esp-idf/components/micro_ros_espidf_component/esp32_toolchain.cmake"
  "/home/maoyuxuan/esp/esp-idf/components/micro_ros_espidf_component/include"
  "/home/maoyuxuan/esp/esp-idf/components/micro_ros_espidf_component/micro_ros_dev"
  "/home/maoyuxuan/esp/esp-idf/components/micro_ros_espidf_component/micro_ros_src"
  )
endif()
