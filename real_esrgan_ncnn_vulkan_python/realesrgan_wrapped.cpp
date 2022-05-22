#include "realesrgan_wrapped.h"

int RealESRGANWrapped::process(const Image &inimage, Image &outimage) const
{
    int c = inimage.elempack;
    ncnn::Mat inimagemat =
        ncnn::Mat(inimage.w, inimage.h, (void *)inimage.data, (size_t)c, c);
    ncnn::Mat outimagemat =
        ncnn::Mat(outimage.w, outimage.h, (void *)outimage.data, (size_t)c, c);
    return RealESRGAN::process(inimagemat, outimagemat);
}

RealESRGANWrapped::RealESRGANWrapped(int gpuid, bool tta_mode)
    : RealESRGAN(gpuid, tta_mode)
{
    this->gpuid = gpuid;
}

uint32_t RealESRGANWrapped::get_heap_budget()
{
    return ncnn::get_gpu_device(this->gpuid)->get_heap_budget();
}

int RealESRGANWrapped::load(const StringType &parampath,
                           const StringType &modelpath)
{
#if _WIN32
    return RealESRGAN::load(*parampath.wstr, *modelpath.wstr);
#else
    return RealESRGAN::load(*parampath.str, *modelpath.str);
#endif
}

int get_gpu_count() { return ncnn::get_gpu_count(); }

void destroy_gpu_instance() { ncnn::destroy_gpu_instance(); }
