# EDIT THIS FILE! THIS IS SCAFFOLDING FOR YOU TO OWN!
# THIS FILE WAS ORIGINALLY GENERATED BY CONAN-UE4CLI VERSION 0.0.34.
from conans import ConanFile
import os

class GDALConan(ConanFile):
    settings = "os", "compiler", "build_type", "arch"
    generators = "json"
    
    def _requireUnreal(self, dependency):
        '''
        Adds a package as a dependency, filling in the Unreal Engine version string.
        
        Call this with a package reference that uses a placeholder for the channel, e.g.:
        self._requireUnreal("my-package/1.0.0@adamrehn/{}")
        '''
        self.requires(dependency.format(os.environ["UNREAL_ENGINE_VERSION"]))
    
    def requirements(self):
        self._requireUnreal("gdal-ue4/3.10.0@adamrehn/{}")
        self._requireUnreal("mergetiff-ue4/0.0.7@adamrehn/{}")
        self._requireUnreal("OpenSSL/ue4@adamrehn/{}") 
        self._requireUnreal("nghttp2/ue4@adamrehn/{}")
