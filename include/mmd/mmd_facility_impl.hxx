
/**
             Copyright itsuhane@gmail.com, 2012.
  Distributed under the Boost Software License, Version 1.0.
      (See accompanying file LICENSE_1_0.txt or copy at
            http://www.boost.org/LICENSE_1_0.txt)
**/

inline MMDNG::MMDNG() {
}

inline MMDNG& MMDNG::GetMMDNG() {
    static MMDNG mmdng;
    return mmdng;
}

inline TextureRegistry& MMDNG::GetTextureRegistry() {
    return texture_registry_;
}

inline Model* ReadModel(FileReader& file) {
    Model *model = NULL;
    try {
        ModelReader::ModelFormat format = ModelReader::GetModelFormat(file);
        switch(format) {
        case ModelReader::MODEL_TYPE_PMD:
            model = PmdReader().Read(file);
            break;
        case ModelReader::MODEL_TYPE_PMX:
            model = PmxReader().Read(file);
            break;
        }
    } catch (std::exception& e) {
        throw exception(std::string("ReadModel: Exception caught."), e);
    } catch (...) {
        throw exception(std::string("ReadModel: Non-standard exception caught."));
    }
    return model;
}