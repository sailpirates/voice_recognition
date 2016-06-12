#ifndef RECORDER
#define RECORDER

#include <QAudioRecorder>
#include <QQueue>
#include <QUrl>
#include <QJsonDocument>

class AudioRecorder: public QObject {
    Q_OBJECT
    Q_PROPERTY (bool recording READ recording NOTIFY recordingChanged)
    Q_PROPERTY (QString textCommand READ getTextCommand NOTIFY textCommandChanged)
public:
    AudioRecorder(QObject* parent=0);
    const bool& recording() const;
    QUrl get_raw_audio();
public slots:
    Q_INVOKABLE void record();
    Q_INVOKABLE void stop();
    QString getTextCommand();
signals:
    void recordingChanged();
    void textCommandChanged();
private:
    QString speechToText(QUrl audioUrl);
    QAudioRecorder* qAudioRecorder;
    QQueue<QUrl> mediaContentUrls;
    QQueue<QJsonDocument> jsonResults;
    QString textCommand;
    bool bRecording;
};

#endif // RECORDER

