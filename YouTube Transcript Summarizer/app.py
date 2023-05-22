from flask import Flask, request
from youtube_transcript_api import YouTubeTranscriptApi as yta
from transformers import pipeline

app = Flask(__name__)

@app.get('/summary')
#function to summarize a YouTube video
def summarize():

    link = request.args.get('url','')
    print(link)
    yt_video_id = link.split('=')[1]
    print(yt_video_id +"\n\n\n")

    #extracting the video ID from the link

    video_transcript_list = yta.get_transcript(yt_video_id)
    print(video_transcript_list)
    print("\n\n\n")
    transcript = ' '.join([line['text'] for line in video_transcript_list])
    print(transcript +"\n\n\n")
    #fetching the transcript

    summariser = pipeline('summarization')
    summary = ''
    for i in range(0, (len(transcript)//1000)+1):
        summary_text = summariser(transcript[i*1000:(i+1)*1000])[0]['summary_text']
        print("Please wait, summarization in progress.....")
        summary = summary + summary_text + ' '
    return summary, 200
    #splitting transcript into smaller sentences and summarizing it and apending it to summary
    
if __name__ == '__main__':
    app.run()
