#ifndef DEBUG_VOLUME_RENDERER_H
#define DEBUG_VOLUME_RENDERER_H

#include "volume_renderer.h"

#include <QOpenGLVertexArrayObject>
#include <QOpenGLBuffer>


class DebugVolumeRenderer : public VolumeRenderer
{
  public:
    DebugVolumeRenderer(void)
      : VolumeRenderer()
      , m_prog()
      , m_vao()
      , m_vbo_cube(QOpenGLBuffer::VertexBuffer)
      , m_ibo_cube(QOpenGLBuffer::IndexBuffer)
    {
      // tieto 2 prikazy v skutocnosti ani nie us potrebne,
      // pretoze StaticDraw je pre QOpenGLBuffer defaultny
      m_vbo_cube.setUsagePattern(QOpenGLBuffer::StaticDraw);
      m_ibo_cube.setUsagePattern(QOpenGLBuffer::StaticDraw);
    }

  protected:
    virtual bool reset_impl(int /* w */, int /* h */) override;
    virtual void render_impl(const QQuaternion & rotation,
                             const QVector3D & scale,
                             const QVector3D & translation,
                             float /* peel_depth */,
                             int /* detail */) override;

  protected:
    QOpenGLShaderProgram m_prog;
    QOpenGLVertexArrayObject m_vao;
    QOpenGLBuffer m_vbo_cube;
    QOpenGLBuffer m_ibo_cube;
};

#endif // VOLUME_RENDERER_H
