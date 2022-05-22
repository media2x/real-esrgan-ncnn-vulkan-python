#ifndef REALESRGAN_NCNN_VULKAN_REALESRGAN_WRAPPED_H
#define REALESRGAN_NCNN_VULKAN_REALESRGAN_WRAPPED_H
#include "realesrgan.h"

// wrapper class of ncnn::Mat
typedef struct Image {
    unsigned char *data;
    int w;
    int h;
    int elempack;
    Image(unsigned char *d, int w, int h, int channels)
    {
        this->data = d;
        this->w = w;
        this->h = h;
        this->elempack = channels;
    }

} Image;

union StringType {
    std::string *str;
    std::wstring *wstr;
};

class RealESRGANWrapped : public RealESRGAN
{
  public:
    RealESRGANWrapped(int gpuid, bool tta_mode = false);
    int load(const StringType &parampath, const StringType &modelpath);
    int process(const Image &inimage, Image &outimage) const;
    uint32_t get_heap_budget();

  private:
    int gpuid;
};

int get_gpu_count();
void destroy_gpu_instance();
#endif // REALESRGAN_NCNN_VULKAN_REALESRGAN_WRAPPED_H
