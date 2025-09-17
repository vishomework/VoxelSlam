/****************************************************************************
** Meta object code from reading C++ file 'voxelslam_pc2.hpp'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../src/Voxel-SLAM/VoxelSLAMPointCloud2/src/voxelslam_pc2.hpp"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'voxelslam_pc2.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_voxelslam_pointcloud2__PointCloud2Display_t {
    QByteArrayData data[1];
    char stringdata0[42];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_voxelslam_pointcloud2__PointCloud2Display_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_voxelslam_pointcloud2__PointCloud2Display_t qt_meta_stringdata_voxelslam_pointcloud2__PointCloud2Display = {
    {
QT_MOC_LITERAL(0, 0, 41) // "voxelslam_pointcloud2::PointC..."

    },
    "voxelslam_pointcloud2::PointCloud2Display"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_voxelslam_pointcloud2__PointCloud2Display[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

void voxelslam_pointcloud2::PointCloud2Display::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject voxelslam_pointcloud2::PointCloud2Display::staticMetaObject = { {
    &rviz::MessageFilterDisplay<sensor_msgs::PointCloud2>::staticMetaObject,
    qt_meta_stringdata_voxelslam_pointcloud2__PointCloud2Display.data,
    qt_meta_data_voxelslam_pointcloud2__PointCloud2Display,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *voxelslam_pointcloud2::PointCloud2Display::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *voxelslam_pointcloud2::PointCloud2Display::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_voxelslam_pointcloud2__PointCloud2Display.stringdata0))
        return static_cast<void*>(this);
    return rviz::MessageFilterDisplay<sensor_msgs::PointCloud2>::qt_metacast(_clname);
}

int voxelslam_pointcloud2::PointCloud2Display::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = rviz::MessageFilterDisplay<sensor_msgs::PointCloud2>::qt_metacall(_c, _id, _a);
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
