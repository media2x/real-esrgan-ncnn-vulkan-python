# CMakeList is tricky! To prevent failure of compilation, shall copy all the generated `spv.hex.h` files to `real-esrgan-ncnn-vulkan` submodule folder!

# realesrgan ncnn Vulkan Python

![CI](https://github.com/media2x/realcugan-ncnn-vulkan-python/workflows/CI/badge.svg)

## Introduction

A Python FFI of xinntao/Real-ESRGAN-ncnn-vulkan achieved with SWIG.

[Real-ESRGAN-ncnn-vulkan](https://github.com/xinntao/Real-ESRGAN-ncnn-vulkan) is xinntao's ncnn implementation of realesrgan converter. Runs fast on Intel / AMD / Nvidia with Vulkan API.

This project only wrapped the original RealESRGAN class. As a result, functions other than the core upscaling and denoising such as multi-thread loading and saving are not available. Of course, the auto tilesize and prepadding settings are implements, so don't worry about them.

## Download

linux x64, Windows x64 and MacOS x64 releases are available now. For other platforms, you may compile it on your own.
The reason why MacOS ARM64 build is not available is that it needs ARM Python Dev Libs which I have no ideas on how to
get it on Github's MacOS x64 VM. Moreover, I don't have a Mac.

- However, for Linux (Like Ubuntu 18.04) with an older GLIBC (version < 2.29), you may try to use the ubuntu-1804 release or just compile it on your own.

Update: it has been uploaded to PyPI, and you can install it with pip now.

## Installation

```shell
TODO
```

## Build

First, you have to install python, python development package (Python native development libs in Visual Studio), vulkan SDK and SWIG on your platform. And then, there are two ways to build it:

- Use setuptools to build and install into python package directly. (Currently in developing)
- Use CMake directly (The old way)

### Use setuptools

```shell
TODO
```

### Use CMake

TODO

#### Windows

I used Visual Studio 2019 and msvc v142 to build this project for Windows.

Install visual studio and open the project directory, and build. Job done.

The only problem on Windows is that, you cannot use [CMake for Windows](https://cmake.org/download/) GUI to generate the Visual Studio solution file and build it. This will make the lib crash on loading.

One way is [using Visual Studio to open the project as directory](https://www.microfocus.com/documentation/visual-cobol/vc50/VS2019/GUID-BE1C48AA-DB22-4F38-9644-E9B48658EF36.html), and build it from Visual Studio.
And another way is build it from powershell just like what is written in the [release.yml](.github/workflows/release.yml)

#### Mac OS X

TODO

### Example program

```python
import cv2
from realesrgan_ncnn_vulkan import RealESRGAN

with cv2.imread("input.png") as image:
  realesrgan = RealESRGAN(gpuid=0, scale=2)
  image = realesrgan.process(image)
  cv2.imwrite("output.png", image)
```

## [Docs](Docs.md)

## Known issues

- TODO

## Original realesrgan Project

- https://github.com/xinntao/Real-ESRGAN-ncnn-vulkan
- https://github.com/xinntao/Real-ESRGAN

## Other Open-Source Code Used

- https://github.com/Tencent/ncnn for fast neural network inference on ALL PLATFORMS
- https://github.com/webmproject/libwebp for encoding and decoding Webp images on ALL PLATFORMS
- https://github.com/nothings/stb for decoding and encoding image on Linux / MacOS
- https://github.com/tronkko/dirent for listing files in directory on Windows
