# Compile settings
APP_STL := gnustl_static
APP_CPPFLAGS := -frtti -fexceptions

# Build all available ABIs
APP_ABI := all
#APP_ABI := armeabi-v7a arm64-v8a

LOCAL_ARM_NEON  := true
# What platform (API level) to build against
APP_PLATFORM := android-19