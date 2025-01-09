//
// Created by saif on 12/30/24.
//

#ifndef DRAWABLEOBJECT_H
#define DRAWABLEOBJECT_H

class DrawableObject {
public:
     void load() ;  // تحميل البيانات (مثل vertices)
     void render() ;  // رسم الكائن
    virtual ~DrawableObject() = default;
};

#endif //DRAWABLEOBJECT_H
