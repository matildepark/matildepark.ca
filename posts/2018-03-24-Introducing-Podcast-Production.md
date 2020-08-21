<meta name="description" content="Step by step, how I produce podcasts." />
<meta name="twitter:description" content="Step by step, how I produce podcasts." />
<h1 class="h1-title">Introduction to Podcast Production</h1>
<p class="post-date">
  <time datetime="2018-03-2412:00:00+00:00" itemprop="datePublished">March 24, 2018</time>
</p>

During [Metagame's short-lived tenure](https://archive.org/details/MetagameEpisode3), I did the audio production for most of the episodes from the second one onward, with the exception of one episode (where I was recovering from surgery). I fell into a process, and it became something theraputic, and enjoyable, but it also took a lot of research to hone the process. So, for the benefit of any other budding podcasters who want to make a podcast sound good, I figured I'd outline my process from start to finish.


# 0: Tools

I use Zencastr for most of my sessions with online participants. [Zencastr](https://zencastr.com/) is an incredible service that shaves off most of the logistical work: it records local audio on both sides of the conversation, and allows guests to just talk and not worry about the logistics of recording. It also is where you have your "virtual call" itself, so it's all in-browser for everyone. Once the podcast is done recording, a WAV is uploaded and you have lossless, synchronised audio for every participant.

My equipment is very spartan: a set of [Audio Technica ATR-2100 USB Microphones](http://www.audio-technica.com/cms/wired_mics/b8dd84773f83092c/). They're fairly inexpensive and sound phenomenal. If you're recording multiple people in an entirely local setting, I highly recommend picking up [Loopback](https://rogueamoeba.com/loopback/), too, which allows you to combine the USB microphones into a single interface with four (or six, if there's three people) channels.

My postprocessing DAW software of choice is Logic Pro X. It seems to be an uncommon choice, but it works really well for the job. [Audacity](https://www.audacityteam.org/) is also used at the very start and end of the process, as is the "secret sauce": [The Levelator](http://www.conversationsnetwork.org/levelator).

# 1: Recording

There really isn't enough said about speaking on-air in a way that's really enjoyable to hear. I don't just mean being "on". I mean keeping a listener engaged, staying in touch with your participants, etc.

What I learned to do as I recorded more podcasts was to be a brief and precise speaker. Most people vulture around their point: they circle their thoughts before, finally, hitting the thesis. If you know what your thesis is, state it first, then follow it up with your points.

It's also very easy to use filler words to clarify that you're still thinking, like "um" or "uh". You can remove these in post, but it's more work for you later -- just know that removing gaps of silence is the easiest part of your job. You can have long gaps of nothing if you're still thinking, and your production will clean those thoughts up and string them together.

When I was producing Metagame, I also organised most of the shows -- I made a bullet-point list with questions or points that "needed" to be addressed, but I also let tangents happen if they happened. If the conversation ran away from a question, I eventually learned it didn't need to come up. A gentle structure is the best structure for a conversation. There's a reason the conversation is taking place, but let everyone explore a bit before edging them forward in the structure.

# 2: Initially cleaning up the audio

Download the tracks from everyone. Open Audacity, open each track and perform [noise removal](https://manual.audacityteam.org/man/noise_reduction.html). Export the (now less noisy) WAV for each.

# 3: Start the Logic project

Open Logic Pro X and create a multi-track template. Drag in the noiseless WAVs to independent tracks.

# 4: Really clean up the audio

Your three best friends are the compressor, the EQ, and the noise gate. I took a page from [this guide](https://sixcolors.com/post/2015/08/add-podcasting-plug-ins-in-garageband/), for GarageBand.

The compressor reduces the dynamic range of the audio to help vocals sit better in the mix. It lowers the loudest parts to raise the entire track up. Signal levels above the listed threshold will cause the compressor to react and reduce the DR. The ratio controls how much any signal over the threshold is attenuated (4:1 would attenuate the signal by 25%, for example).

The EQ raises or lowers parts of the frequency of the signal.

The noise gate eliminates all sound that occurs beyond its listed threshold. So if you're gating at 35dB, then only signals of 35dB or higher will show in the recording. This is used since noise will usually be low, but consistent, but people speaking are louder than the gate, immediately, so they show in the signal, but the noise doesn't.

Apply selection-based processing to the track.

- **Compressor**: Threshold should be -17.0dB, ratio to 3.1:1, attack to 9ms. I didn't bother with Gain, it usually wasn't necessary to apply it on either end of things.
- **Channel EQ**: In Logic, I usually used the "Improve Speaking Voice" preset.
- **Noise Gate**: A lot of guides say to stick the noise gate to -35.0dB, but I found that this cut off quiet speakers. I had much better luck with -40.0dB or -45.0dB, which still eliminated their noise but allowed them to come through.

# 5: Cut up the audio

Excellent! Now each track sounds good and you can strip the silence to see the conversation play out and really manipulate it.

Press Ctrl+X in Logic and you'll configure what it thinks "silence" is, so you can remove it from each track:

- **Threshold**: 4%
- **Minimum time to accept as silence**: 1 second
- **Pre-attack time**: 0.1 second
- **Post-release time**: 0

Leave "search zero crossing" checked.

Perform this to each independent track and you'll now see when everyone starts or stops talking (or when another noise is interrupting someone as they talk).

# 6: Listen to the conversation

This might be the most inefficient way I produce, but I listen to the episode at 1x speed and remove noises that aren't talking as they appear. I also remove "cross-talk" (people interrupting each other), sometimes moving the interruption later on to make the conversation less clumsy; I shorten the delay between online participants so that it sounds more like they're in the same room, reacting to each other quickly; and I often remove "yeah", "uh huh", etc. from the person listening, unless it's integral to the conversation.

Your best friend is gonna be **Shift+F**, which grabs all the audio after the highlighted track so you can move it all at once. When you're shortening a section, this is integral to not annihilating the conversation flow.

I often ran into an issue where a participant would start a thought, take a few seconds to process, and then finish the thought -- I would just remove the silence and string the thought together.

If you hit a "weird" sound -- mouth clicking or someone tapping the table or whatever -- you can use the [scissor tool](https://support.apple.com/kb/PH13043?locale=en_US&viewlocale=en_US) in Logic, zoomed in enough (use Cmd+Right to zoom the track in a bit further) to remove the noise and connect the track back together with Shift+F.

# 7: Bounce the rough mix and Levelate

Hit Cmd+B to open Bounce and export a PCM, WAV mix of the episode. Now you're gonna stick it in the Levelator, which will normalise the channels and make it just sound generally better. I don't know what it does beyond normalisation, but episodes sound great after it processes them. So...yeah.

# 8: Export the final

Open the output from the Levelator in Audacity and chop off excess silence from the end, then export it. I usually export at 96kbps, mono audio, in MP3. This produces about ~26MB of audio per hour, which is fantastic.

# 9: Upload it!

If you're doing your own podcast, I do highly recommend going to a hosting service like [Blubrry](https://www.blubrry.com/), since it's, in the long run, far less expensive than hosting it yourself. They also give you an embeddable HTML5 player for your site.

I also made YouTube videos of my podcasts. That one's easy if you're a command line person. Install [FFmpeg](https://www.ffmpeg.org/) (I can't recall if I used [Homebrew](https://brew.sh/) on my Mac to install it, but I might've -- in any case, Homebrew is so useful, you should have it anyway).

Open your command line and use this command, dragging in your appropriate file for the two inputs listed, so it puts the full path in for you:

```
ffmpeg -loop 1 -r 2 -i /path/to/podcastimage.jpg -i /path/to/podcast.mp3 -vf scale=-1:380 -c:v libx264 -preset slow -tune stillimage -crf 18 -c:a copy -shortest -pix_fmt yuv420p -threads 0 output.mkv
```

It'll render the video in about 3 minutes per hour of audio, creating a small video at 360p for the podcast.

I hope this is useful for you -- or at the very least, provided some insight on my process. Podcasting is super rewarding: it lets you hone down conversations until they're something really special you can come back and listen to later, and as a producer it can be a really theraputic, fun thing to do.

Oh, and if you have tips on improving this process, please do [let me know](mailto:matilde@park.computer).
