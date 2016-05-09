
cmake -DANDROID_STL="gnustl_static" \
    -DANDROID_STL_FORCE_FEATURES="ON" \
#    -DANDROID_TOOLCHAIN_NAME="arm-linux-androideabi-4.9" \
    -DANDROID_ABI="armeabi-v7a with NEON" \
    -DANDROID_NATIVE_API_LEVEL="android-19" \
    -DANDROID_FORCE_ARM_BUILD="ON" \
    -DBUILD_SHARED_LIBS="ON" \
    -DCMAKE_TOOLCHAIN_FILE="${CB}/android.toolchain.cmake" \
    -DCMAKE_BUILD_TYPE="Release"
