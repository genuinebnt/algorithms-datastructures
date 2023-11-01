from conan import ConanFile
from conan.tools.cmake import CMakeToolchain


class ConanPackage(ConanFile):
    name = "network-monitor"
    version = "0.1.0"

    settings = "os", "compiler", "build_type", "arch"

    generators = "CMakeDeps"

    def generate(self):
        tc = CMakeToolchain(self, generator="Ninja")
        tc.generate()

    def requirements(self):
        self.requires("gtest/1.14.0")