.. _api-datamodel-python:

seiscomp.datamodel
===================

.. py:module:: seiscomp.datamodel

Base Objects
------------

* :ref:`Object <api-python-datamodel-object>`
* :ref:`PublicObject <api-python-datamodel-publicobject>`
* :ref:`Notifier <api-python-datamodel-notifier>`


Domain Overview
---------------


EventParameters
............................................................

.. graphviz::
   :name: EventParameters
   :caption: EventParameters object connections from parent to child.
   :align: center

   digraph "EventParameters hierarchy" {
      node [fontname=Verdana fontsize=8 shape=plaintext penwidth=0.5 style="rounded,filled" fillcolor="#fcf2e3" color="#000000"]
      edge [color="#000000"]
      layout="dot"
      Pick [label="Pick", href="../base/api-python.html#api-python-datamodel-pick", target="_top"]
      Comment [label="Comment", href="../base/api-python.html#api-python-datamodel-comment", target="_top"]
      Amplitude [label="Amplitude", href="../base/api-python.html#api-python-datamodel-amplitude", target="_top"]
      Reading [label="Reading", href="../base/api-python.html#api-python-datamodel-reading", target="_top"]
      PickReference [label="PickReference", href="../base/api-python.html#api-python-datamodel-pickreference", target="_top"]
      AmplitudeReference [label="AmplitudeReference", href="../base/api-python.html#api-python-datamodel-amplitudereference", target="_top"]
      Origin [label="Origin", href="../base/api-python.html#api-python-datamodel-origin", target="_top"]
      CompositeTime [label="CompositeTime", href="../base/api-python.html#api-python-datamodel-compositetime", target="_top"]
      Arrival [label="Arrival", href="../base/api-python.html#api-python-datamodel-arrival", target="_top"]
      StationMagnitude [label="StationMagnitude", href="../base/api-python.html#api-python-datamodel-stationmagnitude", target="_top"]
      Magnitude [label="Magnitude", href="../base/api-python.html#api-python-datamodel-magnitude", target="_top"]
      StationMagnitudeContribution [label="StationMagnitudeContribution", href="../base/api-python.html#api-python-datamodel-stationmagnitudecontribution", target="_top"]
      FocalMechanism [label="FocalMechanism", href="../base/api-python.html#api-python-datamodel-focalmechanism", target="_top"]
      MomentTensor [label="MomentTensor", href="../base/api-python.html#api-python-datamodel-momenttensor", target="_top"]
      DataUsed [label="DataUsed", href="../base/api-python.html#api-python-datamodel-dataused", target="_top"]
      MomentTensorPhaseSetting [label="MomentTensorPhaseSetting", href="../base/api-python.html#api-python-datamodel-momenttensorphasesetting", target="_top"]
      MomentTensorStationContribution [label="MomentTensorStationContribution", href="../base/api-python.html#api-python-datamodel-momenttensorstationcontribution", target="_top"]
      MomentTensorComponentContribution [label="MomentTensorComponentContribution", href="../base/api-python.html#api-python-datamodel-momenttensorcomponentcontribution", target="_top"]
      Event [label="Event", href="../base/api-python.html#api-python-datamodel-event", target="_top"]
      EventDescription [label="EventDescription", href="../base/api-python.html#api-python-datamodel-eventdescription", target="_top"]
      OriginReference [label="OriginReference", href="../base/api-python.html#api-python-datamodel-originreference", target="_top"]
      FocalMechanismReference [label="FocalMechanismReference", href="../base/api-python.html#api-python-datamodel-focalmechanismreference", target="_top"]
      EventParameters [label="EventParameters", href="../base/api-python.html#api-python-datamodel-eventparameters", target="_top"]
      EventParameters -> Pick [dir=back arrowtail=diamond]
      MomentTensor -> Comment [dir=back arrowtail=diamond]
      FocalMechanism -> Comment [dir=back arrowtail=diamond]
      Amplitude -> Comment [dir=back arrowtail=diamond]
      Magnitude -> Comment [dir=back arrowtail=diamond]
      StationMagnitude -> Comment [dir=back arrowtail=diamond]
      Pick -> Comment [dir=back arrowtail=diamond]
      Event -> Comment [dir=back arrowtail=diamond]
      Origin -> Comment [dir=back arrowtail=diamond]
      EventParameters -> Amplitude [dir=back arrowtail=diamond]
      EventParameters -> Reading [dir=back arrowtail=diamond]
      Reading -> PickReference [dir=back arrowtail=diamond]
      Reading -> AmplitudeReference [dir=back arrowtail=diamond]
      EventParameters -> Origin [dir=back arrowtail=diamond]
      Origin -> CompositeTime [dir=back arrowtail=diamond]
      Origin -> Arrival [dir=back arrowtail=diamond]
      Origin -> StationMagnitude [dir=back arrowtail=diamond]
      Origin -> Magnitude [dir=back arrowtail=diamond]
      Magnitude -> StationMagnitudeContribution [dir=back arrowtail=diamond]
      EventParameters -> FocalMechanism [dir=back arrowtail=diamond]
      FocalMechanism -> MomentTensor [dir=back arrowtail=diamond]
      MomentTensor -> DataUsed [dir=back arrowtail=diamond]
      MomentTensor -> MomentTensorPhaseSetting [dir=back arrowtail=diamond]
      MomentTensor -> MomentTensorStationContribution [dir=back arrowtail=diamond]
      MomentTensorStationContribution -> MomentTensorComponentContribution [dir=back arrowtail=diamond]
      EventParameters -> Event [dir=back arrowtail=diamond]
      Event -> EventDescription [dir=back arrowtail=diamond]
      Event -> OriginReference [dir=back arrowtail=diamond]
      Event -> FocalMechanismReference [dir=back arrowtail=diamond]
   }

.. graphviz::
   :name: EventParameters
   :caption: EventParameters object connections from parent to child including attributes and elements.
   :align: center

   digraph "EventParameters hierarchy" {
      node [fontname=Verdana fontsize=8 shape=plaintext penwidth=0.5 style="rounded,filled" fillcolor="#fcf2e3" color="#000000"]
      edge [color="#000000"]
      layout = "dot"
      Pick [
          labeltooltip = "Pick"
          label = <
              <table border="0" cellpadding="0" cellspacing="2">
                  <tr><td>Pick</td></tr>
                  <hr/>
                  <tr><td> </td></tr>
                  <tr><td align="left" port="publicID"><font color="#8b0000">+ publicID: string</font></td></tr>
                  <tr><td align="left" port="time"><font color="#8b0000">+ time: TimeQuantity</font></td></tr>
                  <tr><td align="left" port="waveformID"><font color="#8b0000">+ waveformID: WaveformStreamID</font></td></tr>
                  <tr><td align="left" port="filterID"><font color="#8b0000">+ filterID: string</font></td></tr>
                  <tr><td align="left" port="methodID"><font color="#8b0000">+ methodID: string</font></td></tr>
                  <tr><td align="left" port="horizontalSlowness"><font color="#8b0000">+ horizontalSlowness: RealQuantity  [0..1]</font></td></tr>
                  <tr><td align="left" port="backazimuth"><font color="#8b0000">+ backazimuth: RealQuantity  [0..1]</font></td></tr>
                  <tr><td align="left" port="slownessMethodID"><font color="#8b0000">+ slownessMethodID: string</font></td></tr>
                  <tr><td align="left" port="onset"><font color="#8b0000">+ onset: PickOnset  [0..1]</font></td></tr>
                  <tr><td align="left" port="phaseHint"><font color="#8b0000">+ phaseHint: Phase  [0..1]</font></td></tr>
                  <tr><td align="left" port="polarity"><font color="#8b0000">+ polarity: PickPolarity  [0..1]</font></td></tr>
                  <tr><td align="left" port="evaluationMode"><font color="#8b0000">+ evaluationMode: EvaluationMode  [0..1]</font></td></tr>
                  <tr><td align="left" port="evaluationStatus"><font color="#8b0000">+ evaluationStatus: EvaluationStatus  [0..1]</font></td></tr>
                  <tr><td align="left" port="creationInfo"><font color="#8b0000">+ creationInfo: CreationInfo  [0..1]</font></td></tr>
                  <tr><td align="left"><font color="#8b0000">+ comment: Comment [0..*]</font></td></tr>
              </table>
          >
          href = "../base/api-python.html#api-python-datamodel-pick"
          target = "_top"
      ]
      Comment [
          labeltooltip = "Comment"
          label = <
              <table border="0" cellpadding="0" cellspacing="2">
                  <tr><td>Comment</td></tr>
                  <hr/>
                  <tr><td> </td></tr>
                  <tr><td align="left" port="text"><font color="#8b0000">+ text: string</font></td></tr>
                  <tr><td align="left" port="id"><font color="#8b0000">+ id: string</font></td></tr>
                  <tr><td align="left" port="start"><font color="#8b0000">+ start: datetime  [0..1]</font></td></tr>
                  <tr><td align="left" port="end"><font color="#8b0000">+ end: datetime  [0..1]</font></td></tr>
                  <tr><td align="left" port="creationInfo"><font color="#8b0000">+ creationInfo: CreationInfo  [0..1]</font></td></tr>
              </table>
          >
          href = "../base/api-python.html#api-python-datamodel-comment"
          target = "_top"
      ]
      Amplitude [
          labeltooltip = "Amplitude"
          label = <
              <table border="0" cellpadding="0" cellspacing="2">
                  <tr><td>Amplitude</td></tr>
                  <hr/>
                  <tr><td> </td></tr>
                  <tr><td align="left" port="publicID"><font color="#8b0000">+ publicID: string</font></td></tr>
                  <tr><td align="left" port="type"><font color="#8b0000">+ type: string</font></td></tr>
                  <tr><td align="left" port="amplitude"><font color="#8b0000">+ amplitude: RealQuantity  [0..1]</font></td></tr>
                  <tr><td align="left" port="timeWindow"><font color="#8b0000">+ timeWindow: TimeWindow  [0..1]</font></td></tr>
                  <tr><td align="left" port="period"><font color="#8b0000">+ period: RealQuantity  [0..1]</font></td></tr>
                  <tr><td align="left" port="snr"><font color="#8b0000">+ snr: float  [0..1]</font></td></tr>
                  <tr><td align="left" port="unit"><font color="#8b0000">+ unit: string</font></td></tr>
                  <tr><td align="left" port="pickID"><font color="#8b0000">+ pickID: string</font></td></tr>
                  <tr><td align="left" port="waveformID"><font color="#8b0000">+ waveformID: WaveformStreamID  [0..1]</font></td></tr>
                  <tr><td align="left" port="filterID"><font color="#8b0000">+ filterID: string</font></td></tr>
                  <tr><td align="left" port="methodID"><font color="#8b0000">+ methodID: string</font></td></tr>
                  <tr><td align="left" port="scalingTime"><font color="#8b0000">+ scalingTime: TimeQuantity  [0..1]</font></td></tr>
                  <tr><td align="left" port="magnitudeHint"><font color="#8b0000">+ magnitudeHint: string</font></td></tr>
                  <tr><td align="left" port="evaluationMode"><font color="#8b0000">+ evaluationMode: EvaluationMode  [0..1]</font></td></tr>
                  <tr><td align="left" port="creationInfo"><font color="#8b0000">+ creationInfo: CreationInfo  [0..1]</font></td></tr>
                  <tr><td align="left"><font color="#8b0000">+ comment: Comment [0..*]</font></td></tr>
              </table>
          >
          href = "../base/api-python.html#api-python-datamodel-amplitude"
          target = "_top"
      ]
      Reading [
          labeltooltip = "Reading"
          label = <
              <table border="0" cellpadding="0" cellspacing="2">
                  <tr><td>Reading</td></tr>
                  <hr/>
                  <tr><td> </td></tr>
                  <tr><td align="left" port="publicID"><font color="#8b0000">+ publicID: string</font></td></tr>
                  <tr><td align="left"><font color="#8b0000">+ pickReference: PickReference [0..*]</font></td></tr>
                  <tr><td align="left"><font color="#8b0000">+ amplitudeReference: AmplitudeReference [0..*]</font></td></tr>
              </table>
          >
          href = "../base/api-python.html#api-python-datamodel-reading"
          target = "_top"
      ]
      PickReference [
          labeltooltip = "PickReference"
          label = <
              <table border="0" cellpadding="0" cellspacing="2">
                  <tr><td>PickReference</td></tr>
                  <hr/>
                  <tr><td> </td></tr>
                  <tr><td align="left" port="pickID"><font color="#8b0000">+ pickID: string</font></td></tr>
              </table>
          >
          href = "../base/api-python.html#api-python-datamodel-pickreference"
          target = "_top"
      ]
      AmplitudeReference [
          labeltooltip = "AmplitudeReference"
          label = <
              <table border="0" cellpadding="0" cellspacing="2">
                  <tr><td>AmplitudeReference</td></tr>
                  <hr/>
                  <tr><td> </td></tr>
                  <tr><td align="left" port="amplitudeID"><font color="#8b0000">+ amplitudeID: string</font></td></tr>
              </table>
          >
          href = "../base/api-python.html#api-python-datamodel-amplitudereference"
          target = "_top"
      ]
      Origin [
          labeltooltip = "Origin"
          label = <
              <table border="0" cellpadding="0" cellspacing="2">
                  <tr><td>Origin</td></tr>
                  <hr/>
                  <tr><td> </td></tr>
                  <tr><td align="left" port="publicID"><font color="#8b0000">+ publicID: string</font></td></tr>
                  <tr><td align="left" port="time"><font color="#8b0000">+ time: TimeQuantity</font></td></tr>
                  <tr><td align="left" port="latitude"><font color="#8b0000">+ latitude: RealQuantity</font></td></tr>
                  <tr><td align="left" port="longitude"><font color="#8b0000">+ longitude: RealQuantity</font></td></tr>
                  <tr><td align="left" port="depth"><font color="#8b0000">+ depth: RealQuantity  [0..1]</font></td></tr>
                  <tr><td align="left" port="depthType"><font color="#8b0000">+ depthType: OriginDepthType  [0..1]</font></td></tr>
                  <tr><td align="left" port="timeFixed"><font color="#8b0000">+ timeFixed: boolean  [0..1]</font></td></tr>
                  <tr><td align="left" port="epicenterFixed"><font color="#8b0000">+ epicenterFixed: boolean  [0..1]</font></td></tr>
                  <tr><td align="left" port="referenceSystemID"><font color="#8b0000">+ referenceSystemID: string</font></td></tr>
                  <tr><td align="left" port="methodID"><font color="#8b0000">+ methodID: string</font></td></tr>
                  <tr><td align="left" port="earthModelID"><font color="#8b0000">+ earthModelID: string</font></td></tr>
                  <tr><td align="left" port="quality"><font color="#8b0000">+ quality: OriginQuality  [0..1]</font></td></tr>
                  <tr><td align="left" port="uncertainty"><font color="#8b0000">+ uncertainty: OriginUncertainty  [0..1]</font></td></tr>
                  <tr><td align="left" port="type"><font color="#8b0000">+ type: OriginType  [0..1]</font></td></tr>
                  <tr><td align="left" port="evaluationMode"><font color="#8b0000">+ evaluationMode: EvaluationMode  [0..1]</font></td></tr>
                  <tr><td align="left" port="evaluationStatus"><font color="#8b0000">+ evaluationStatus: EvaluationStatus  [0..1]</font></td></tr>
                  <tr><td align="left" port="creationInfo"><font color="#8b0000">+ creationInfo: CreationInfo  [0..1]</font></td></tr>
                  <tr><td align="left"><font color="#8b0000">+ comment: Comment [0..*]</font></td></tr>
                  <tr><td align="left"><font color="#8b0000">+ compositeTime: CompositeTime [0..*]</font></td></tr>
                  <tr><td align="left"><font color="#8b0000">+ arrival: Arrival [0..*]</font></td></tr>
                  <tr><td align="left"><font color="#8b0000">+ stationMagnitude: StationMagnitude [0..*]</font></td></tr>
                  <tr><td align="left"><font color="#8b0000">+ magnitude: Magnitude [0..*]</font></td></tr>
              </table>
          >
          href = "../base/api-python.html#api-python-datamodel-origin"
          target = "_top"
      ]
      CompositeTime [
          labeltooltip = "CompositeTime"
          label = <
              <table border="0" cellpadding="0" cellspacing="2">
                  <tr><td>CompositeTime</td></tr>
                  <hr/>
                  <tr><td> </td></tr>
                  <tr><td align="left" port="year"><font color="#8b0000">+ year: IntegerQuantity  [0..1]</font></td></tr>
                  <tr><td align="left" port="month"><font color="#8b0000">+ month: IntegerQuantity  [0..1]</font></td></tr>
                  <tr><td align="left" port="day"><font color="#8b0000">+ day: IntegerQuantity  [0..1]</font></td></tr>
                  <tr><td align="left" port="hour"><font color="#8b0000">+ hour: IntegerQuantity  [0..1]</font></td></tr>
                  <tr><td align="left" port="minute"><font color="#8b0000">+ minute: IntegerQuantity  [0..1]</font></td></tr>
                  <tr><td align="left" port="second"><font color="#8b0000">+ second: RealQuantity  [0..1]</font></td></tr>
              </table>
          >
          href = "../base/api-python.html#api-python-datamodel-compositetime"
          target = "_top"
      ]
      Arrival [
          labeltooltip = "Arrival"
          label = <
              <table border="0" cellpadding="0" cellspacing="2">
                  <tr><td>Arrival</td></tr>
                  <hr/>
                  <tr><td> </td></tr>
                  <tr><td align="left" port="pickID"><font color="#8b0000">+ pickID: string</font></td></tr>
                  <tr><td align="left" port="phase"><font color="#8b0000">+ phase: Phase</font></td></tr>
                  <tr><td align="left" port="timeCorrection"><font color="#8b0000">+ timeCorrection: float  [0..1]</font></td></tr>
                  <tr><td align="left" port="azimuth"><font color="#8b0000">+ azimuth: float  [0..1]</font></td></tr>
                  <tr><td align="left" port="distance"><font color="#8b0000">+ distance: float  [0..1]</font></td></tr>
                  <tr><td align="left" port="takeOffAngle"><font color="#8b0000">+ takeOffAngle: float  [0..1]</font></td></tr>
                  <tr><td align="left" port="timeResidual"><font color="#8b0000">+ timeResidual: float  [0..1]</font></td></tr>
                  <tr><td align="left" port="horizontalSlownessResidual"><font color="#8b0000">+ horizontalSlownessResidual: float  [0..1]</font></td></tr>
                  <tr><td align="left" port="backazimuthResidual"><font color="#8b0000">+ backazimuthResidual: float  [0..1]</font></td></tr>
                  <tr><td align="left" port="timeUsed"><font color="#8b0000">+ timeUsed: boolean  [0..1]</font></td></tr>
                  <tr><td align="left" port="horizontalSlownessUsed"><font color="#8b0000">+ horizontalSlownessUsed: boolean  [0..1]</font></td></tr>
                  <tr><td align="left" port="backazimuthUsed"><font color="#8b0000">+ backazimuthUsed: boolean  [0..1]</font></td></tr>
                  <tr><td align="left" port="weight"><font color="#8b0000">+ weight: float  [0..1]</font></td></tr>
                  <tr><td align="left" port="earthModelID"><font color="#8b0000">+ earthModelID: string</font></td></tr>
                  <tr><td align="left" port="preliminary"><font color="#8b0000">+ preliminary: boolean  [0..1]</font></td></tr>
                  <tr><td align="left" port="creationInfo"><font color="#8b0000">+ creationInfo: CreationInfo  [0..1]</font></td></tr>
              </table>
          >
          href = "../base/api-python.html#api-python-datamodel-arrival"
          target = "_top"
      ]
      StationMagnitude [
          labeltooltip = "StationMagnitude"
          label = <
              <table border="0" cellpadding="0" cellspacing="2">
                  <tr><td>StationMagnitude</td></tr>
                  <hr/>
                  <tr><td> </td></tr>
                  <tr><td align="left" port="publicID"><font color="#8b0000">+ publicID: string</font></td></tr>
                  <tr><td align="left" port="originID"><font color="#8b0000">+ originID: string</font></td></tr>
                  <tr><td align="left" port="magnitude"><font color="#8b0000">+ magnitude: RealQuantity</font></td></tr>
                  <tr><td align="left" port="type"><font color="#8b0000">+ type: string</font></td></tr>
                  <tr><td align="left" port="amplitudeID"><font color="#8b0000">+ amplitudeID: string</font></td></tr>
                  <tr><td align="left" port="methodID"><font color="#8b0000">+ methodID: string</font></td></tr>
                  <tr><td align="left" port="waveformID"><font color="#8b0000">+ waveformID: WaveformStreamID  [0..1]</font></td></tr>
                  <tr><td align="left" port="passedQC"><font color="#8b0000">+ passedQC: boolean  [0..1]</font></td></tr>
                  <tr><td align="left" port="creationInfo"><font color="#8b0000">+ creationInfo: CreationInfo  [0..1]</font></td></tr>
                  <tr><td align="left"><font color="#8b0000">+ comment: Comment [0..*]</font></td></tr>
              </table>
          >
          href = "../base/api-python.html#api-python-datamodel-stationmagnitude"
          target = "_top"
      ]
      Magnitude [
          labeltooltip = "Magnitude"
          label = <
              <table border="0" cellpadding="0" cellspacing="2">
                  <tr><td>Magnitude</td></tr>
                  <hr/>
                  <tr><td> </td></tr>
                  <tr><td align="left" port="publicID"><font color="#8b0000">+ publicID: string</font></td></tr>
                  <tr><td align="left" port="magnitude"><font color="#8b0000">+ magnitude: RealQuantity</font></td></tr>
                  <tr><td align="left" port="type"><font color="#8b0000">+ type: string</font></td></tr>
                  <tr><td align="left" port="originID"><font color="#8b0000">+ originID: string</font></td></tr>
                  <tr><td align="left" port="methodID"><font color="#8b0000">+ methodID: string</font></td></tr>
                  <tr><td align="left" port="stationCount"><font color="#8b0000">+ stationCount: int  [0..1]</font></td></tr>
                  <tr><td align="left" port="azimuthalGap"><font color="#8b0000">+ azimuthalGap: float  [0..1]</font></td></tr>
                  <tr><td align="left" port="evaluationStatus"><font color="#8b0000">+ evaluationStatus: EvaluationStatus  [0..1]</font></td></tr>
                  <tr><td align="left" port="creationInfo"><font color="#8b0000">+ creationInfo: CreationInfo  [0..1]</font></td></tr>
                  <tr><td align="left"><font color="#8b0000">+ comment: Comment [0..*]</font></td></tr>
                  <tr><td align="left"><font color="#8b0000">+ stationMagnitudeContribution: StationMagnitudeContribution [0..*]</font></td></tr>
              </table>
          >
          href = "../base/api-python.html#api-python-datamodel-magnitude"
          target = "_top"
      ]
      StationMagnitudeContribution [
          labeltooltip = "StationMagnitudeContribution"
          label = <
              <table border="0" cellpadding="0" cellspacing="2">
                  <tr><td>StationMagnitudeContribution</td></tr>
                  <hr/>
                  <tr><td> </td></tr>
                  <tr><td align="left" port="stationMagnitudeID"><font color="#8b0000">+ stationMagnitudeID: string</font></td></tr>
                  <tr><td align="left" port="residual"><font color="#8b0000">+ residual: float  [0..1]</font></td></tr>
                  <tr><td align="left" port="weight"><font color="#8b0000">+ weight: float  [0..1]</font></td></tr>
              </table>
          >
          href = "../base/api-python.html#api-python-datamodel-stationmagnitudecontribution"
          target = "_top"
      ]
      FocalMechanism [
          labeltooltip = "FocalMechanism"
          label = <
              <table border="0" cellpadding="0" cellspacing="2">
                  <tr><td>FocalMechanism</td></tr>
                  <hr/>
                  <tr><td> </td></tr>
                  <tr><td align="left" port="publicID"><font color="#8b0000">+ publicID: string</font></td></tr>
                  <tr><td align="left" port="triggeringOriginID"><font color="#8b0000">+ triggeringOriginID: string</font></td></tr>
                  <tr><td align="left" port="nodalPlanes"><font color="#8b0000">+ nodalPlanes: NodalPlanes  [0..1]</font></td></tr>
                  <tr><td align="left" port="principalAxes"><font color="#8b0000">+ principalAxes: PrincipalAxes  [0..1]</font></td></tr>
                  <tr><td align="left" port="azimuthalGap"><font color="#8b0000">+ azimuthalGap: float  [0..1]</font></td></tr>
                  <tr><td align="left" port="stationPolarityCount"><font color="#8b0000">+ stationPolarityCount: int  [0..1]</font></td></tr>
                  <tr><td align="left" port="misfit"><font color="#8b0000">+ misfit: float  [0..1]</font></td></tr>
                  <tr><td align="left" port="stationDistributionRatio"><font color="#8b0000">+ stationDistributionRatio: float  [0..1]</font></td></tr>
                  <tr><td align="left" port="methodID"><font color="#8b0000">+ methodID: string</font></td></tr>
                  <tr><td align="left" port="evaluationMode"><font color="#8b0000">+ evaluationMode: EvaluationMode  [0..1]</font></td></tr>
                  <tr><td align="left" port="evaluationStatus"><font color="#8b0000">+ evaluationStatus: EvaluationStatus  [0..1]</font></td></tr>
                  <tr><td align="left" port="creationInfo"><font color="#8b0000">+ creationInfo: CreationInfo  [0..1]</font></td></tr>
                  <tr><td align="left"><font color="#8b0000">+ comment: Comment [0..*]</font></td></tr>
                  <tr><td align="left"><font color="#8b0000">+ momentTensor: MomentTensor [0..*]</font></td></tr>
              </table>
          >
          href = "../base/api-python.html#api-python-datamodel-focalmechanism"
          target = "_top"
      ]
      MomentTensor [
          labeltooltip = "MomentTensor"
          label = <
              <table border="0" cellpadding="0" cellspacing="2">
                  <tr><td>MomentTensor</td></tr>
                  <hr/>
                  <tr><td> </td></tr>
                  <tr><td align="left" port="publicID"><font color="#8b0000">+ publicID: string</font></td></tr>
                  <tr><td align="left" port="derivedOriginID"><font color="#8b0000">+ derivedOriginID: string</font></td></tr>
                  <tr><td align="left" port="momentMagnitudeID"><font color="#8b0000">+ momentMagnitudeID: string</font></td></tr>
                  <tr><td align="left" port="scalarMoment"><font color="#8b0000">+ scalarMoment: RealQuantity  [0..1]</font></td></tr>
                  <tr><td align="left" port="tensor"><font color="#8b0000">+ tensor: Tensor  [0..1]</font></td></tr>
                  <tr><td align="left" port="variance"><font color="#8b0000">+ variance: float  [0..1]</font></td></tr>
                  <tr><td align="left" port="varianceReduction"><font color="#8b0000">+ varianceReduction: float  [0..1]</font></td></tr>
                  <tr><td align="left" port="doubleCouple"><font color="#8b0000">+ doubleCouple: float  [0..1]</font></td></tr>
                  <tr><td align="left" port="clvd"><font color="#8b0000">+ clvd: float  [0..1]</font></td></tr>
                  <tr><td align="left" port="iso"><font color="#8b0000">+ iso: float  [0..1]</font></td></tr>
                  <tr><td align="left" port="greensFunctionID"><font color="#8b0000">+ greensFunctionID: string</font></td></tr>
                  <tr><td align="left" port="filterID"><font color="#8b0000">+ filterID: string</font></td></tr>
                  <tr><td align="left" port="sourceTimeFunction"><font color="#8b0000">+ sourceTimeFunction: SourceTimeFunction  [0..1]</font></td></tr>
                  <tr><td align="left" port="methodID"><font color="#8b0000">+ methodID: string</font></td></tr>
                  <tr><td align="left" port="method"><font color="#8b0000">+ method: MomentTensorMethod  [0..1]</font></td></tr>
                  <tr><td align="left" port="status"><font color="#8b0000">+ status: MomentTensorStatus  [0..1]</font></td></tr>
                  <tr><td align="left" port="cmtName"><font color="#8b0000">+ cmtName: string</font></td></tr>
                  <tr><td align="left" port="cmtVersion"><font color="#8b0000">+ cmtVersion: string</font></td></tr>
                  <tr><td align="left" port="creationInfo"><font color="#8b0000">+ creationInfo: CreationInfo  [0..1]</font></td></tr>
                  <tr><td align="left"><font color="#8b0000">+ comment: Comment [0..*]</font></td></tr>
                  <tr><td align="left"><font color="#8b0000">+ dataUsed: DataUsed [0..*]</font></td></tr>
                  <tr><td align="left"><font color="#8b0000">+ momentTensorPhaseSetting: MomentTensorPhaseSetting [0..*]</font></td></tr>
                  <tr><td align="left"><font color="#8b0000">+ momentTensorStationContribution: MomentTensorStationContribution [0..*]</font></td></tr>
              </table>
          >
          href = "../base/api-python.html#api-python-datamodel-momenttensor"
          target = "_top"
      ]
      DataUsed [
          labeltooltip = "DataUsed"
          label = <
              <table border="0" cellpadding="0" cellspacing="2">
                  <tr><td>DataUsed</td></tr>
                  <hr/>
                  <tr><td> </td></tr>
                  <tr><td align="left" port="waveType"><font color="#8b0000">+ waveType: DataUsedWaveType</font></td></tr>
                  <tr><td align="left" port="stationCount"><font color="#8b0000">+ stationCount: int</font></td></tr>
                  <tr><td align="left" port="componentCount"><font color="#8b0000">+ componentCount: int</font></td></tr>
                  <tr><td align="left" port="shortestPeriod"><font color="#8b0000">+ shortestPeriod: float  [0..1]</font></td></tr>
              </table>
          >
          href = "../base/api-python.html#api-python-datamodel-dataused"
          target = "_top"
      ]
      MomentTensorPhaseSetting [
          labeltooltip = "MomentTensorPhaseSetting"
          label = <
              <table border="0" cellpadding="0" cellspacing="2">
                  <tr><td>MomentTensorPhaseSetting</td></tr>
                  <hr/>
                  <tr><td> </td></tr>
                  <tr><td align="left" port="code"><font color="#8b0000">+ code: string</font></td></tr>
                  <tr><td align="left" port="lowerPeriod"><font color="#8b0000">+ lowerPeriod: float</font></td></tr>
                  <tr><td align="left" port="upperPeriod"><font color="#8b0000">+ upperPeriod: float</font></td></tr>
                  <tr><td align="left" port="minimumSNR"><font color="#8b0000">+ minimumSNR: float  [0..1]</font></td></tr>
                  <tr><td align="left" port="maximumTimeShift"><font color="#8b0000">+ maximumTimeShift: float  [0..1]</font></td></tr>
              </table>
          >
          href = "../base/api-python.html#api-python-datamodel-momenttensorphasesetting"
          target = "_top"
      ]
      MomentTensorStationContribution [
          labeltooltip = "MomentTensorStationContribution"
          label = <
              <table border="0" cellpadding="0" cellspacing="2">
                  <tr><td>MomentTensorStationContribution</td></tr>
                  <hr/>
                  <tr><td> </td></tr>
                  <tr><td align="left" port="publicID"><font color="#8b0000">+ publicID: string</font></td></tr>
                  <tr><td align="left" port="active"><font color="#8b0000">+ active: boolean</font></td></tr>
                  <tr><td align="left" port="waveformID"><font color="#8b0000">+ waveformID: WaveformStreamID  [0..1]</font></td></tr>
                  <tr><td align="left" port="weight"><font color="#8b0000">+ weight: float  [0..1]</font></td></tr>
                  <tr><td align="left" port="timeShift"><font color="#8b0000">+ timeShift: float  [0..1]</font></td></tr>
                  <tr><td align="left"><font color="#8b0000">+ momentTensorComponentContribution: MomentTensorComponentContribution [0..*]</font></td></tr>
              </table>
          >
          href = "../base/api-python.html#api-python-datamodel-momenttensorstationcontribution"
          target = "_top"
      ]
      MomentTensorComponentContribution [
          labeltooltip = "MomentTensorComponentContribution"
          label = <
              <table border="0" cellpadding="0" cellspacing="2">
                  <tr><td>MomentTensorComponentContribution</td></tr>
                  <hr/>
                  <tr><td> </td></tr>
                  <tr><td align="left" port="phaseCode"><font color="#8b0000">+ phaseCode: string</font></td></tr>
                  <tr><td align="left" port="component"><font color="#8b0000">+ component: int</font></td></tr>
                  <tr><td align="left" port="active"><font color="#8b0000">+ active: boolean</font></td></tr>
                  <tr><td align="left" port="weight"><font color="#8b0000">+ weight: float</font></td></tr>
                  <tr><td align="left" port="timeShift"><font color="#8b0000">+ timeShift: float</font></td></tr>
                  <tr><td align="left" port="dataTimeWindow"><font color="#8b0000">+ dataTimeWindow: float</font></td></tr>
                  <tr><td align="left" port="misfit"><font color="#8b0000">+ misfit: float  [0..1]</font></td></tr>
                  <tr><td align="left" port="snr"><font color="#8b0000">+ snr: float  [0..1]</font></td></tr>
              </table>
          >
          href = "../base/api-python.html#api-python-datamodel-momenttensorcomponentcontribution"
          target = "_top"
      ]
      Event [
          labeltooltip = "Event"
          label = <
              <table border="0" cellpadding="0" cellspacing="2">
                  <tr><td>Event</td></tr>
                  <hr/>
                  <tr><td> </td></tr>
                  <tr><td align="left" port="publicID"><font color="#8b0000">+ publicID: string</font></td></tr>
                  <tr><td align="left" port="preferredOriginID"><font color="#8b0000">+ preferredOriginID: string</font></td></tr>
                  <tr><td align="left" port="preferredMagnitudeID"><font color="#8b0000">+ preferredMagnitudeID: string</font></td></tr>
                  <tr><td align="left" port="preferredFocalMechanismID"><font color="#8b0000">+ preferredFocalMechanismID: string</font></td></tr>
                  <tr><td align="left" port="type"><font color="#8b0000">+ type: EventType  [0..1]</font></td></tr>
                  <tr><td align="left" port="typeCertainty"><font color="#8b0000">+ typeCertainty: EventTypeCertainty  [0..1]</font></td></tr>
                  <tr><td align="left" port="creationInfo"><font color="#8b0000">+ creationInfo: CreationInfo  [0..1]</font></td></tr>
                  <tr><td align="left"><font color="#8b0000">+ eventDescription: EventDescription [0..*]</font></td></tr>
                  <tr><td align="left"><font color="#8b0000">+ comment: Comment [0..*]</font></td></tr>
                  <tr><td align="left"><font color="#8b0000">+ originReference: OriginReference [0..*]</font></td></tr>
                  <tr><td align="left"><font color="#8b0000">+ focalMechanismReference: FocalMechanismReference [0..*]</font></td></tr>
              </table>
          >
          href = "../base/api-python.html#api-python-datamodel-event"
          target = "_top"
      ]
      EventDescription [
          labeltooltip = "EventDescription"
          label = <
              <table border="0" cellpadding="0" cellspacing="2">
                  <tr><td>EventDescription</td></tr>
                  <hr/>
                  <tr><td> </td></tr>
                  <tr><td align="left" port="text"><font color="#8b0000">+ text: string</font></td></tr>
                  <tr><td align="left" port="type"><font color="#8b0000">+ type: EventDescriptionType</font></td></tr>
              </table>
          >
          href = "../base/api-python.html#api-python-datamodel-eventdescription"
          target = "_top"
      ]
      OriginReference [
          labeltooltip = "OriginReference"
          label = <
              <table border="0" cellpadding="0" cellspacing="2">
                  <tr><td>OriginReference</td></tr>
                  <hr/>
                  <tr><td> </td></tr>
                  <tr><td align="left" port="originID"><font color="#8b0000">+ originID: string</font></td></tr>
              </table>
          >
          href = "../base/api-python.html#api-python-datamodel-originreference"
          target = "_top"
      ]
      FocalMechanismReference [
          labeltooltip = "FocalMechanismReference"
          label = <
              <table border="0" cellpadding="0" cellspacing="2">
                  <tr><td>FocalMechanismReference</td></tr>
                  <hr/>
                  <tr><td> </td></tr>
                  <tr><td align="left" port="focalMechanismID"><font color="#8b0000">+ focalMechanismID: string</font></td></tr>
              </table>
          >
          href = "../base/api-python.html#api-python-datamodel-focalmechanismreference"
          target = "_top"
      ]
      EventParameters [
          labeltooltip = "EventParameters"
          label = <
              <table border="0" cellpadding="0" cellspacing="2">
                  <tr><td>EventParameters</td></tr>
                  <hr/>
                  <tr><td> </td></tr>
                  <tr><td align="left" port="publicID"><font color="#8b0000">+ publicID: string</font></td></tr>
                  <tr><td align="left"><font color="#8b0000">+ pick: Pick [0..*]</font></td></tr>
                  <tr><td align="left"><font color="#8b0000">+ amplitude: Amplitude [0..*]</font></td></tr>
                  <tr><td align="left"><font color="#8b0000">+ reading: Reading [0..*]</font></td></tr>
                  <tr><td align="left"><font color="#8b0000">+ origin: Origin [0..*]</font></td></tr>
                  <tr><td align="left"><font color="#8b0000">+ focalMechanism: FocalMechanism [0..*]</font></td></tr>
                  <tr><td align="left"><font color="#8b0000">+ event: Event [0..*]</font></td></tr>
              </table>
          >
          href = "../base/api-python.html#api-python-datamodel-eventparameters"
          target = "_top"
      ]
      EventParameters -> Pick [dir=back arrowtail=diamond]
      MomentTensor -> Comment [dir=back arrowtail=diamond]
      FocalMechanism -> Comment [dir=back arrowtail=diamond]
      Amplitude -> Comment [dir=back arrowtail=diamond]
      Magnitude -> Comment [dir=back arrowtail=diamond]
      StationMagnitude -> Comment [dir=back arrowtail=diamond]
      Pick -> Comment [dir=back arrowtail=diamond]
      Event -> Comment [dir=back arrowtail=diamond]
      Origin -> Comment [dir=back arrowtail=diamond]
      EventParameters -> Amplitude [dir=back arrowtail=diamond]
      EventParameters -> Reading [dir=back arrowtail=diamond]
      Reading -> PickReference [dir=back arrowtail=diamond]
      Reading -> AmplitudeReference [dir=back arrowtail=diamond]
      EventParameters -> Origin [dir=back arrowtail=diamond]
      Origin -> CompositeTime [dir=back arrowtail=diamond]
      Origin -> Arrival [dir=back arrowtail=diamond]
      Origin -> StationMagnitude [dir=back arrowtail=diamond]
      Origin -> Magnitude [dir=back arrowtail=diamond]
      Magnitude -> StationMagnitudeContribution [dir=back arrowtail=diamond]
      EventParameters -> FocalMechanism [dir=back arrowtail=diamond]
      FocalMechanism -> MomentTensor [dir=back arrowtail=diamond]
      MomentTensor -> DataUsed [dir=back arrowtail=diamond]
      MomentTensor -> MomentTensorPhaseSetting [dir=back arrowtail=diamond]
      MomentTensor -> MomentTensorStationContribution [dir=back arrowtail=diamond]
      MomentTensorStationContribution -> MomentTensorComponentContribution [dir=back arrowtail=diamond]
      EventParameters -> Event [dir=back arrowtail=diamond]
      Event -> EventDescription [dir=back arrowtail=diamond]
      Event -> OriginReference [dir=back arrowtail=diamond]
      Event -> FocalMechanismReference [dir=back arrowtail=diamond]
   }


Config
............................................................


.. graphviz::
   :name: Config
   :caption: Config object connections from parent to child including attributes and elements.
   :align: center

   digraph "Config hierarchy" {
      node [fontname=Verdana fontsize=8 shape=plaintext penwidth=0.5 style="rounded,filled" fillcolor="#fcf2e3" color="#000000"]
      edge [color="#000000"]
      layout = "dot"
      ParameterSet [
          labeltooltip = "ParameterSet"
          label = <
              <table border="0" cellpadding="0" cellspacing="2">
                  <tr><td>ParameterSet</td></tr>
                  <hr/>
                  <tr><td> </td></tr>
                  <tr><td align="left" port="publicID"><font color="#8b0000">+ publicID: string</font></td></tr>
                  <tr><td align="left" port="baseID"><font color="#8b0000">+ baseID: string</font></td></tr>
                  <tr><td align="left" port="moduleID"><font color="#8b0000">+ moduleID: string</font></td></tr>
                  <tr><td align="left" port="created"><font color="#8b0000">+ created: datetime  [0..1]</font></td></tr>
                  <tr><td align="left"><font color="#8b0000">+ parameter: Parameter [0..*]</font></td></tr>
                  <tr><td align="left"><font color="#8b0000">+ comment: Comment [0..*]</font></td></tr>
              </table>
          >
          href = "../base/api-python.html#api-python-datamodel-parameterset"
          target = "_top"
      ]
      Parameter [
          labeltooltip = "Parameter"
          label = <
              <table border="0" cellpadding="0" cellspacing="2">
                  <tr><td>Parameter</td></tr>
                  <hr/>
                  <tr><td> </td></tr>
                  <tr><td align="left" port="publicID"><font color="#8b0000">+ publicID: string</font></td></tr>
                  <tr><td align="left" port="name"><font color="#8b0000">+ name: string</font></td></tr>
                  <tr><td align="left" port="value"><font color="#8b0000">+ value: string</font></td></tr>
                  <tr><td align="left"><font color="#8b0000">+ comment: Comment [0..*]</font></td></tr>
              </table>
          >
          href = "../base/api-python.html#api-python-datamodel-parameter"
          target = "_top"
      ]
      Comment [
          labeltooltip = "Comment"
          label = <
              <table border="0" cellpadding="0" cellspacing="2">
                  <tr><td>Comment</td></tr>
                  <hr/>
                  <tr><td> </td></tr>
                  <tr><td align="left" port="text"><font color="#8b0000">+ text: string</font></td></tr>
                  <tr><td align="left" port="id"><font color="#8b0000">+ id: string</font></td></tr>
                  <tr><td align="left" port="start"><font color="#8b0000">+ start: datetime  [0..1]</font></td></tr>
                  <tr><td align="left" port="end"><font color="#8b0000">+ end: datetime  [0..1]</font></td></tr>
                  <tr><td align="left" port="creationInfo"><font color="#8b0000">+ creationInfo: CreationInfo  [0..1]</font></td></tr>
              </table>
          >
          href = "../base/api-python.html#api-python-datamodel-comment"
          target = "_top"
      ]
      ConfigModule [
          labeltooltip = "ConfigModule"
          label = <
              <table border="0" cellpadding="0" cellspacing="2">
                  <tr><td>ConfigModule</td></tr>
                  <hr/>
                  <tr><td> </td></tr>
                  <tr><td align="left" port="publicID"><font color="#8b0000">+ publicID: string</font></td></tr>
                  <tr><td align="left" port="name"><font color="#8b0000">+ name: string</font></td></tr>
                  <tr><td align="left" port="parameterSetID"><font color="#8b0000">+ parameterSetID: string</font></td></tr>
                  <tr><td align="left" port="enabled"><font color="#8b0000">+ enabled: boolean</font></td></tr>
                  <tr><td align="left"><font color="#8b0000">+ configStation: ConfigStation [0..*]</font></td></tr>
              </table>
          >
          href = "../base/api-python.html#api-python-datamodel-configmodule"
          target = "_top"
      ]
      ConfigStation [
          labeltooltip = "ConfigStation"
          label = <
              <table border="0" cellpadding="0" cellspacing="2">
                  <tr><td>ConfigStation</td></tr>
                  <hr/>
                  <tr><td> </td></tr>
                  <tr><td align="left" port="publicID"><font color="#8b0000">+ publicID: string</font></td></tr>
                  <tr><td align="left" port="networkCode"><font color="#8b0000">+ networkCode: string</font></td></tr>
                  <tr><td align="left" port="stationCode"><font color="#8b0000">+ stationCode: string</font></td></tr>
                  <tr><td align="left" port="enabled"><font color="#8b0000">+ enabled: boolean</font></td></tr>
                  <tr><td align="left" port="creationInfo"><font color="#8b0000">+ creationInfo: CreationInfo  [0..1]</font></td></tr>
                  <tr><td align="left"><font color="#8b0000">+ setup: Setup [0..*]</font></td></tr>
              </table>
          >
          href = "../base/api-python.html#api-python-datamodel-configstation"
          target = "_top"
      ]
      Setup [
          labeltooltip = "Setup"
          label = <
              <table border="0" cellpadding="0" cellspacing="2">
                  <tr><td>Setup</td></tr>
                  <hr/>
                  <tr><td> </td></tr>
                  <tr><td align="left" port="name"><font color="#8b0000">+ name: string</font></td></tr>
                  <tr><td align="left" port="parameterSetID"><font color="#8b0000">+ parameterSetID: string</font></td></tr>
                  <tr><td align="left" port="enabled"><font color="#8b0000">+ enabled: boolean</font></td></tr>
              </table>
          >
          href = "../base/api-python.html#api-python-datamodel-setup"
          target = "_top"
      ]
      Config [
          labeltooltip = "Config"
          label = <
              <table border="0" cellpadding="0" cellspacing="2">
                  <tr><td>Config</td></tr>
                  <hr/>
                  <tr><td> </td></tr>
                  <tr><td align="left" port="publicID"><font color="#8b0000">+ publicID: string</font></td></tr>
                  <tr><td align="left"><font color="#8b0000">+ parameterSet: ParameterSet [0..*]</font></td></tr>
                  <tr><td align="left"><font color="#8b0000">+ configModule: ConfigModule [0..*]</font></td></tr>
              </table>
          >
          href = "../base/api-python.html#api-python-datamodel-config"
          target = "_top"
      ]
      Config -> ParameterSet [dir=back arrowtail=diamond]
      ParameterSet -> Parameter [dir=back arrowtail=diamond]
      Parameter -> Comment [dir=back arrowtail=diamond]
      ParameterSet -> Comment [dir=back arrowtail=diamond]
      Config -> ConfigModule [dir=back arrowtail=diamond]
      ConfigModule -> ConfigStation [dir=back arrowtail=diamond]
      ConfigStation -> Setup [dir=back arrowtail=diamond]
   }


QualityControl
............................................................


.. graphviz::
   :name: QualityControl
   :caption: QualityControl object connections from parent to child including attributes and elements.
   :align: center

   digraph "QualityControl hierarchy" {
      node [fontname=Verdana fontsize=8 shape=plaintext penwidth=0.5 style="rounded,filled" fillcolor="#fcf2e3" color="#000000"]
      edge [color="#000000"]
      layout = "dot"
      QCLog [
          labeltooltip = "QCLog"
          label = <
              <table border="0" cellpadding="0" cellspacing="2">
                  <tr><td>QCLog</td></tr>
                  <hr/>
                  <tr><td> </td></tr>
                  <tr><td align="left" port="publicID"><font color="#8b0000">+ publicID: string</font></td></tr>
                  <tr><td align="left" port="waveformID"><font color="#8b0000">+ waveformID: WaveformStreamID</font></td></tr>
                  <tr><td align="left" port="creatorID"><font color="#8b0000">+ creatorID: string</font></td></tr>
                  <tr><td align="left" port="created"><font color="#8b0000">+ created: datetime</font></td></tr>
                  <tr><td align="left" port="start"><font color="#8b0000">+ start: datetime</font></td></tr>
                  <tr><td align="left" port="end"><font color="#8b0000">+ end: datetime</font></td></tr>
                  <tr><td align="left" port="message"><font color="#8b0000">+ message: string</font></td></tr>
              </table>
          >
          href = "../base/api-python.html#api-python-datamodel-qclog"
          target = "_top"
      ]
      WaveformQuality [
          labeltooltip = "WaveformQuality"
          label = <
              <table border="0" cellpadding="0" cellspacing="2">
                  <tr><td>WaveformQuality</td></tr>
                  <hr/>
                  <tr><td> </td></tr>
                  <tr><td align="left" port="waveformID"><font color="#8b0000">+ waveformID: WaveformStreamID</font></td></tr>
                  <tr><td align="left" port="creatorID"><font color="#8b0000">+ creatorID: string</font></td></tr>
                  <tr><td align="left" port="created"><font color="#8b0000">+ created: datetime</font></td></tr>
                  <tr><td align="left" port="start"><font color="#8b0000">+ start: datetime</font></td></tr>
                  <tr><td align="left" port="end"><font color="#8b0000">+ end: datetime  [0..1]</font></td></tr>
                  <tr><td align="left" port="type"><font color="#8b0000">+ type: string</font></td></tr>
                  <tr><td align="left" port="parameter"><font color="#8b0000">+ parameter: string</font></td></tr>
                  <tr><td align="left" port="value"><font color="#8b0000">+ value: float</font></td></tr>
                  <tr><td align="left" port="lowerUncertainty"><font color="#8b0000">+ lowerUncertainty: float  [0..1]</font></td></tr>
                  <tr><td align="left" port="upperUncertainty"><font color="#8b0000">+ upperUncertainty: float  [0..1]</font></td></tr>
                  <tr><td align="left" port="windowLength"><font color="#8b0000">+ windowLength: float  [0..1]</font></td></tr>
              </table>
          >
          href = "../base/api-python.html#api-python-datamodel-waveformquality"
          target = "_top"
      ]
      Outage [
          labeltooltip = "Outage"
          label = <
              <table border="0" cellpadding="0" cellspacing="2">
                  <tr><td>Outage</td></tr>
                  <hr/>
                  <tr><td> </td></tr>
                  <tr><td align="left" port="waveformID"><font color="#8b0000">+ waveformID: WaveformStreamID</font></td></tr>
                  <tr><td align="left" port="creatorID"><font color="#8b0000">+ creatorID: string</font></td></tr>
                  <tr><td align="left" port="created"><font color="#8b0000">+ created: datetime</font></td></tr>
                  <tr><td align="left" port="start"><font color="#8b0000">+ start: datetime</font></td></tr>
                  <tr><td align="left" port="end"><font color="#8b0000">+ end: datetime  [0..1]</font></td></tr>
              </table>
          >
          href = "../base/api-python.html#api-python-datamodel-outage"
          target = "_top"
      ]
      QualityControl [
          labeltooltip = "QualityControl"
          label = <
              <table border="0" cellpadding="0" cellspacing="2">
                  <tr><td>QualityControl</td></tr>
                  <hr/>
                  <tr><td> </td></tr>
                  <tr><td align="left" port="publicID"><font color="#8b0000">+ publicID: string</font></td></tr>
                  <tr><td align="left"><font color="#8b0000">+ qCLog: QCLog [0..*]</font></td></tr>
                  <tr><td align="left"><font color="#8b0000">+ waveformQuality: WaveformQuality [0..*]</font></td></tr>
                  <tr><td align="left"><font color="#8b0000">+ outage: Outage [0..*]</font></td></tr>
              </table>
          >
          href = "../base/api-python.html#api-python-datamodel-qualitycontrol"
          target = "_top"
      ]
      QualityControl -> QCLog [dir=back arrowtail=diamond]
      QualityControl -> WaveformQuality [dir=back arrowtail=diamond]
      QualityControl -> Outage [dir=back arrowtail=diamond]
   }


Inventory
............................................................

.. graphviz::
   :name: Inventory
   :caption: Inventory object connections from parent to child.
   :align: center

   digraph "Inventory hierarchy" {
      node [fontname=Verdana fontsize=8 shape=plaintext penwidth=0.5 style="rounded,filled" fillcolor="#fcf2e3" color="#000000"]
      edge [color="#000000"]
      layout="dot"
      StationGroup [label="StationGroup", href="../base/api-python.html#api-python-datamodel-stationgroup", target="_top"]
      StationReference [label="StationReference", href="../base/api-python.html#api-python-datamodel-stationreference", target="_top"]
      AuxDevice [label="AuxDevice", href="../base/api-python.html#api-python-datamodel-auxdevice", target="_top"]
      AuxSource [label="AuxSource", href="../base/api-python.html#api-python-datamodel-auxsource", target="_top"]
      Sensor [label="Sensor", href="../base/api-python.html#api-python-datamodel-sensor", target="_top"]
      SensorCalibration [label="SensorCalibration", href="../base/api-python.html#api-python-datamodel-sensorcalibration", target="_top"]
      Datalogger [label="Datalogger", href="../base/api-python.html#api-python-datamodel-datalogger", target="_top"]
      DataloggerCalibration [label="DataloggerCalibration", href="../base/api-python.html#api-python-datamodel-dataloggercalibration", target="_top"]
      Decimation [label="Decimation", href="../base/api-python.html#api-python-datamodel-decimation", target="_top"]
      ResponsePAZ [label="ResponsePAZ", href="../base/api-python.html#api-python-datamodel-responsepaz", target="_top"]
      ResponseFIR [label="ResponseFIR", href="../base/api-python.html#api-python-datamodel-responsefir", target="_top"]
      ResponseIIR [label="ResponseIIR", href="../base/api-python.html#api-python-datamodel-responseiir", target="_top"]
      ResponsePolynomial [label="ResponsePolynomial", href="../base/api-python.html#api-python-datamodel-responsepolynomial", target="_top"]
      ResponseFAP [label="ResponseFAP", href="../base/api-python.html#api-python-datamodel-responsefap", target="_top"]
      Network [label="Network", href="../base/api-python.html#api-python-datamodel-network", target="_top"]
      Comment [label="Comment", href="../base/api-python.html#api-python-datamodel-comment", target="_top"]
      Station [label="Station", href="../base/api-python.html#api-python-datamodel-station", target="_top"]
      SensorLocation [label="SensorLocation", href="../base/api-python.html#api-python-datamodel-sensorlocation", target="_top"]
      AuxStream [label="AuxStream", href="../base/api-python.html#api-python-datamodel-auxstream", target="_top"]
      Stream [label="Stream", href="../base/api-python.html#api-python-datamodel-stream", target="_top"]
      Inventory [label="Inventory", href="../base/api-python.html#api-python-datamodel-inventory", target="_top"]
      Inventory -> StationGroup [dir=back arrowtail=diamond]
      StationGroup -> StationReference [dir=back arrowtail=diamond]
      Inventory -> AuxDevice [dir=back arrowtail=diamond]
      AuxDevice -> AuxSource [dir=back arrowtail=diamond]
      Inventory -> Sensor [dir=back arrowtail=diamond]
      Sensor -> SensorCalibration [dir=back arrowtail=diamond]
      Inventory -> Datalogger [dir=back arrowtail=diamond]
      Datalogger -> DataloggerCalibration [dir=back arrowtail=diamond]
      Datalogger -> Decimation [dir=back arrowtail=diamond]
      Inventory -> ResponsePAZ [dir=back arrowtail=diamond]
      Inventory -> ResponseFIR [dir=back arrowtail=diamond]
      Inventory -> ResponseIIR [dir=back arrowtail=diamond]
      Inventory -> ResponsePolynomial [dir=back arrowtail=diamond]
      Inventory -> ResponseFAP [dir=back arrowtail=diamond]
      Inventory -> Network [dir=back arrowtail=diamond]
      Stream -> Comment [dir=back arrowtail=diamond]
      SensorLocation -> Comment [dir=back arrowtail=diamond]
      Station -> Comment [dir=back arrowtail=diamond]
      Network -> Comment [dir=back arrowtail=diamond]
      Network -> Station [dir=back arrowtail=diamond]
      Station -> SensorLocation [dir=back arrowtail=diamond]
      SensorLocation -> AuxStream [dir=back arrowtail=diamond]
      SensorLocation -> Stream [dir=back arrowtail=diamond]
   }

.. graphviz::
   :name: Inventory
   :caption: Inventory object connections from parent to child including attributes and elements.
   :align: center

   digraph "Inventory hierarchy" {
      node [fontname=Verdana fontsize=8 shape=plaintext penwidth=0.5 style="rounded,filled" fillcolor="#fcf2e3" color="#000000"]
      edge [color="#000000"]
      layout = "dot"
      StationGroup [
          labeltooltip = "StationGroup"
          label = <
              <table border="0" cellpadding="0" cellspacing="2">
                  <tr><td>StationGroup</td></tr>
                  <hr/>
                  <tr><td> </td></tr>
                  <tr><td align="left" port="publicID"><font color="#8b0000">+ publicID: string</font></td></tr>
                  <tr><td align="left" port="type"><font color="#8b0000">+ type: StationGroupType  [0..1]</font></td></tr>
                  <tr><td align="left" port="code"><font color="#8b0000">+ code: string</font></td></tr>
                  <tr><td align="left" port="start"><font color="#8b0000">+ start: datetime  [0..1]</font></td></tr>
                  <tr><td align="left" port="end"><font color="#8b0000">+ end: datetime  [0..1]</font></td></tr>
                  <tr><td align="left" port="description"><font color="#8b0000">+ description: string</font></td></tr>
                  <tr><td align="left" port="latitude"><font color="#8b0000">+ latitude: float  [0..1]</font></td></tr>
                  <tr><td align="left" port="longitude"><font color="#8b0000">+ longitude: float  [0..1]</font></td></tr>
                  <tr><td align="left" port="elevation"><font color="#8b0000">+ elevation: float  [0..1]</font></td></tr>
                  <tr><td align="left"><font color="#8b0000">+ stationReference: StationReference [0..*]</font></td></tr>
              </table>
          >
          href = "../base/api-python.html#api-python-datamodel-stationgroup"
          target = "_top"
      ]
      StationReference [
          labeltooltip = "StationReference"
          label = <
              <table border="0" cellpadding="0" cellspacing="2">
                  <tr><td>StationReference</td></tr>
                  <hr/>
                  <tr><td> </td></tr>
                  <tr><td align="left" port="stationID"><font color="#8b0000">+ stationID: string</font></td></tr>
              </table>
          >
          href = "../base/api-python.html#api-python-datamodel-stationreference"
          target = "_top"
      ]
      AuxDevice [
          labeltooltip = "AuxDevice"
          label = <
              <table border="0" cellpadding="0" cellspacing="2">
                  <tr><td>AuxDevice</td></tr>
                  <hr/>
                  <tr><td> </td></tr>
                  <tr><td align="left" port="publicID"><font color="#8b0000">+ publicID: string</font></td></tr>
                  <tr><td align="left" port="name"><font color="#8b0000">+ name: string</font></td></tr>
                  <tr><td align="left" port="description"><font color="#8b0000">+ description: string</font></td></tr>
                  <tr><td align="left" port="model"><font color="#8b0000">+ model: string</font></td></tr>
                  <tr><td align="left" port="manufacturer"><font color="#8b0000">+ manufacturer: string</font></td></tr>
                  <tr><td align="left" port="remark"><font color="#8b0000">+ remark: Blob  [0..1]</font></td></tr>
                  <tr><td align="left"><font color="#8b0000">+ auxSource: AuxSource [0..*]</font></td></tr>
              </table>
          >
          href = "../base/api-python.html#api-python-datamodel-auxdevice"
          target = "_top"
      ]
      AuxSource [
          labeltooltip = "AuxSource"
          label = <
              <table border="0" cellpadding="0" cellspacing="2">
                  <tr><td>AuxSource</td></tr>
                  <hr/>
                  <tr><td> </td></tr>
                  <tr><td align="left" port="name"><font color="#8b0000">+ name: string</font></td></tr>
                  <tr><td align="left" port="description"><font color="#8b0000">+ description: string</font></td></tr>
                  <tr><td align="left" port="unit"><font color="#8b0000">+ unit: string</font></td></tr>
                  <tr><td align="left" port="conversion"><font color="#8b0000">+ conversion: string</font></td></tr>
                  <tr><td align="left" port="sampleRateNumerator"><font color="#8b0000">+ sampleRateNumerator: int  [0..1]</font></td></tr>
                  <tr><td align="left" port="sampleRateDenominator"><font color="#8b0000">+ sampleRateDenominator: int  [0..1]</font></td></tr>
                  <tr><td align="left" port="remark"><font color="#8b0000">+ remark: Blob  [0..1]</font></td></tr>
              </table>
          >
          href = "../base/api-python.html#api-python-datamodel-auxsource"
          target = "_top"
      ]
      Sensor [
          labeltooltip = "Sensor"
          label = <
              <table border="0" cellpadding="0" cellspacing="2">
                  <tr><td>Sensor</td></tr>
                  <hr/>
                  <tr><td> </td></tr>
                  <tr><td align="left" port="publicID"><font color="#8b0000">+ publicID: string</font></td></tr>
                  <tr><td align="left" port="name"><font color="#8b0000">+ name: string</font></td></tr>
                  <tr><td align="left" port="description"><font color="#8b0000">+ description: string</font></td></tr>
                  <tr><td align="left" port="model"><font color="#8b0000">+ model: string</font></td></tr>
                  <tr><td align="left" port="manufacturer"><font color="#8b0000">+ manufacturer: string</font></td></tr>
                  <tr><td align="left" port="type"><font color="#8b0000">+ type: string</font></td></tr>
                  <tr><td align="left" port="unit"><font color="#8b0000">+ unit: string</font></td></tr>
                  <tr><td align="left" port="lowFrequency"><font color="#8b0000">+ lowFrequency: float  [0..1]</font></td></tr>
                  <tr><td align="left" port="highFrequency"><font color="#8b0000">+ highFrequency: float  [0..1]</font></td></tr>
                  <tr><td align="left" port="response"><font color="#8b0000">+ response: string</font></td></tr>
                  <tr><td align="left" port="remark"><font color="#8b0000">+ remark: Blob  [0..1]</font></td></tr>
                  <tr><td align="left"><font color="#8b0000">+ sensorCalibration: SensorCalibration [0..*]</font></td></tr>
              </table>
          >
          href = "../base/api-python.html#api-python-datamodel-sensor"
          target = "_top"
      ]
      SensorCalibration [
          labeltooltip = "SensorCalibration"
          label = <
              <table border="0" cellpadding="0" cellspacing="2">
                  <tr><td>SensorCalibration</td></tr>
                  <hr/>
                  <tr><td> </td></tr>
                  <tr><td align="left" port="serialNumber"><font color="#8b0000">+ serialNumber: string</font></td></tr>
                  <tr><td align="left" port="channel"><font color="#8b0000">+ channel: int</font></td></tr>
                  <tr><td align="left" port="start"><font color="#8b0000">+ start: datetime</font></td></tr>
                  <tr><td align="left" port="end"><font color="#8b0000">+ end: datetime  [0..1]</font></td></tr>
                  <tr><td align="left" port="gain"><font color="#8b0000">+ gain: float  [0..1]</font></td></tr>
                  <tr><td align="left" port="gainFrequency"><font color="#8b0000">+ gainFrequency: float  [0..1]</font></td></tr>
                  <tr><td align="left" port="remark"><font color="#8b0000">+ remark: Blob  [0..1]</font></td></tr>
              </table>
          >
          href = "../base/api-python.html#api-python-datamodel-sensorcalibration"
          target = "_top"
      ]
      Datalogger [
          labeltooltip = "Datalogger"
          label = <
              <table border="0" cellpadding="0" cellspacing="2">
                  <tr><td>Datalogger</td></tr>
                  <hr/>
                  <tr><td> </td></tr>
                  <tr><td align="left" port="publicID"><font color="#8b0000">+ publicID: string</font></td></tr>
                  <tr><td align="left" port="name"><font color="#8b0000">+ name: string</font></td></tr>
                  <tr><td align="left" port="description"><font color="#8b0000">+ description: string</font></td></tr>
                  <tr><td align="left" port="digitizerModel"><font color="#8b0000">+ digitizerModel: string</font></td></tr>
                  <tr><td align="left" port="digitizerManufacturer"><font color="#8b0000">+ digitizerManufacturer: string</font></td></tr>
                  <tr><td align="left" port="recorderModel"><font color="#8b0000">+ recorderModel: string</font></td></tr>
                  <tr><td align="left" port="recorderManufacturer"><font color="#8b0000">+ recorderManufacturer: string</font></td></tr>
                  <tr><td align="left" port="clockModel"><font color="#8b0000">+ clockModel: string</font></td></tr>
                  <tr><td align="left" port="clockManufacturer"><font color="#8b0000">+ clockManufacturer: string</font></td></tr>
                  <tr><td align="left" port="clockType"><font color="#8b0000">+ clockType: string</font></td></tr>
                  <tr><td align="left" port="gain"><font color="#8b0000">+ gain: float  [0..1]</font></td></tr>
                  <tr><td align="left" port="maxClockDrift"><font color="#8b0000">+ maxClockDrift: float  [0..1]</font></td></tr>
                  <tr><td align="left" port="remark"><font color="#8b0000">+ remark: Blob  [0..1]</font></td></tr>
                  <tr><td align="left"><font color="#8b0000">+ dataloggerCalibration: DataloggerCalibration [0..*]</font></td></tr>
                  <tr><td align="left"><font color="#8b0000">+ decimation: Decimation [0..*]</font></td></tr>
              </table>
          >
          href = "../base/api-python.html#api-python-datamodel-datalogger"
          target = "_top"
      ]
      DataloggerCalibration [
          labeltooltip = "DataloggerCalibration"
          label = <
              <table border="0" cellpadding="0" cellspacing="2">
                  <tr><td>DataloggerCalibration</td></tr>
                  <hr/>
                  <tr><td> </td></tr>
                  <tr><td align="left" port="serialNumber"><font color="#8b0000">+ serialNumber: string</font></td></tr>
                  <tr><td align="left" port="channel"><font color="#8b0000">+ channel: int</font></td></tr>
                  <tr><td align="left" port="start"><font color="#8b0000">+ start: datetime</font></td></tr>
                  <tr><td align="left" port="end"><font color="#8b0000">+ end: datetime  [0..1]</font></td></tr>
                  <tr><td align="left" port="gain"><font color="#8b0000">+ gain: float  [0..1]</font></td></tr>
                  <tr><td align="left" port="gainFrequency"><font color="#8b0000">+ gainFrequency: float  [0..1]</font></td></tr>
                  <tr><td align="left" port="remark"><font color="#8b0000">+ remark: Blob  [0..1]</font></td></tr>
              </table>
          >
          href = "../base/api-python.html#api-python-datamodel-dataloggercalibration"
          target = "_top"
      ]
      Decimation [
          labeltooltip = "Decimation"
          label = <
              <table border="0" cellpadding="0" cellspacing="2">
                  <tr><td>Decimation</td></tr>
                  <hr/>
                  <tr><td> </td></tr>
                  <tr><td align="left" port="sampleRateNumerator"><font color="#8b0000">+ sampleRateNumerator: int</font></td></tr>
                  <tr><td align="left" port="sampleRateDenominator"><font color="#8b0000">+ sampleRateDenominator: int</font></td></tr>
                  <tr><td align="left" port="analogueFilterChain"><font color="#8b0000">+ analogueFilterChain: Blob  [0..1]</font></td></tr>
                  <tr><td align="left" port="digitalFilterChain"><font color="#8b0000">+ digitalFilterChain: Blob  [0..1]</font></td></tr>
              </table>
          >
          href = "../base/api-python.html#api-python-datamodel-decimation"
          target = "_top"
      ]
      ResponsePAZ [
          labeltooltip = "ResponsePAZ"
          label = <
              <table border="0" cellpadding="0" cellspacing="2">
                  <tr><td>ResponsePAZ</td></tr>
                  <hr/>
                  <tr><td> </td></tr>
                  <tr><td align="left" port="publicID"><font color="#8b0000">+ publicID: string</font></td></tr>
                  <tr><td align="left" port="name"><font color="#8b0000">+ name: string</font></td></tr>
                  <tr><td align="left" port="type"><font color="#8b0000">+ type: string</font></td></tr>
                  <tr><td align="left" port="gain"><font color="#8b0000">+ gain: float  [0..1]</font></td></tr>
                  <tr><td align="left" port="gainFrequency"><font color="#8b0000">+ gainFrequency: float  [0..1]</font></td></tr>
                  <tr><td align="left" port="normalizationFactor"><font color="#8b0000">+ normalizationFactor: float  [0..1]</font></td></tr>
                  <tr><td align="left" port="normalizationFrequency"><font color="#8b0000">+ normalizationFrequency: float  [0..1]</font></td></tr>
                  <tr><td align="left" port="numberOfZeros"><font color="#8b0000">+ numberOfZeros: int  [0..1]</font></td></tr>
                  <tr><td align="left" port="numberOfPoles"><font color="#8b0000">+ numberOfPoles: int  [0..1]</font></td></tr>
                  <tr><td align="left" port="zeros"><font color="#8b0000">+ zeros: ComplexArray  [0..1]</font></td></tr>
                  <tr><td align="left" port="poles"><font color="#8b0000">+ poles: ComplexArray  [0..1]</font></td></tr>
                  <tr><td align="left" port="remark"><font color="#8b0000">+ remark: Blob  [0..1]</font></td></tr>
                  <tr><td align="left" port="decimationFactor"><font color="#8b0000">+ decimationFactor: int  [0..1]</font></td></tr>
                  <tr><td align="left" port="delay"><font color="#8b0000">+ delay: float  [0..1]</font></td></tr>
                  <tr><td align="left" port="correction"><font color="#8b0000">+ correction: float  [0..1]</font></td></tr>
              </table>
          >
          href = "../base/api-python.html#api-python-datamodel-responsepaz"
          target = "_top"
      ]
      ResponseFIR [
          labeltooltip = "ResponseFIR"
          label = <
              <table border="0" cellpadding="0" cellspacing="2">
                  <tr><td>ResponseFIR</td></tr>
                  <hr/>
                  <tr><td> </td></tr>
                  <tr><td align="left" port="publicID"><font color="#8b0000">+ publicID: string</font></td></tr>
                  <tr><td align="left" port="name"><font color="#8b0000">+ name: string</font></td></tr>
                  <tr><td align="left" port="gain"><font color="#8b0000">+ gain: float  [0..1]</font></td></tr>
                  <tr><td align="left" port="gainFrequency"><font color="#8b0000">+ gainFrequency: float  [0..1]</font></td></tr>
                  <tr><td align="left" port="decimationFactor"><font color="#8b0000">+ decimationFactor: int  [0..1]</font></td></tr>
                  <tr><td align="left" port="delay"><font color="#8b0000">+ delay: float  [0..1]</font></td></tr>
                  <tr><td align="left" port="correction"><font color="#8b0000">+ correction: float  [0..1]</font></td></tr>
                  <tr><td align="left" port="numberOfCoefficients"><font color="#8b0000">+ numberOfCoefficients: int  [0..1]</font></td></tr>
                  <tr><td align="left" port="symmetry"><font color="#8b0000">+ symmetry: string</font></td></tr>
                  <tr><td align="left" port="coefficients"><font color="#8b0000">+ coefficients: RealArray  [0..1]</font></td></tr>
                  <tr><td align="left" port="remark"><font color="#8b0000">+ remark: Blob  [0..1]</font></td></tr>
              </table>
          >
          href = "../base/api-python.html#api-python-datamodel-responsefir"
          target = "_top"
      ]
      ResponseIIR [
          labeltooltip = "ResponseIIR"
          label = <
              <table border="0" cellpadding="0" cellspacing="2">
                  <tr><td>ResponseIIR</td></tr>
                  <hr/>
                  <tr><td> </td></tr>
                  <tr><td align="left" port="publicID"><font color="#8b0000">+ publicID: string</font></td></tr>
                  <tr><td align="left" port="name"><font color="#8b0000">+ name: string</font></td></tr>
                  <tr><td align="left" port="type"><font color="#8b0000">+ type: string</font></td></tr>
                  <tr><td align="left" port="gain"><font color="#8b0000">+ gain: float  [0..1]</font></td></tr>
                  <tr><td align="left" port="gainFrequency"><font color="#8b0000">+ gainFrequency: float  [0..1]</font></td></tr>
                  <tr><td align="left" port="decimationFactor"><font color="#8b0000">+ decimationFactor: int  [0..1]</font></td></tr>
                  <tr><td align="left" port="delay"><font color="#8b0000">+ delay: float  [0..1]</font></td></tr>
                  <tr><td align="left" port="correction"><font color="#8b0000">+ correction: float  [0..1]</font></td></tr>
                  <tr><td align="left" port="numberOfNumerators"><font color="#8b0000">+ numberOfNumerators: int  [0..1]</font></td></tr>
                  <tr><td align="left" port="numberOfDenominators"><font color="#8b0000">+ numberOfDenominators: int  [0..1]</font></td></tr>
                  <tr><td align="left" port="numerators"><font color="#8b0000">+ numerators: RealArray  [0..1]</font></td></tr>
                  <tr><td align="left" port="denominators"><font color="#8b0000">+ denominators: RealArray  [0..1]</font></td></tr>
                  <tr><td align="left" port="remark"><font color="#8b0000">+ remark: Blob  [0..1]</font></td></tr>
              </table>
          >
          href = "../base/api-python.html#api-python-datamodel-responseiir"
          target = "_top"
      ]
      ResponsePolynomial [
          labeltooltip = "ResponsePolynomial"
          label = <
              <table border="0" cellpadding="0" cellspacing="2">
                  <tr><td>ResponsePolynomial</td></tr>
                  <hr/>
                  <tr><td> </td></tr>
                  <tr><td align="left" port="publicID"><font color="#8b0000">+ publicID: string</font></td></tr>
                  <tr><td align="left" port="name"><font color="#8b0000">+ name: string</font></td></tr>
                  <tr><td align="left" port="gain"><font color="#8b0000">+ gain: float  [0..1]</font></td></tr>
                  <tr><td align="left" port="gainFrequency"><font color="#8b0000">+ gainFrequency: float  [0..1]</font></td></tr>
                  <tr><td align="left" port="frequencyUnit"><font color="#8b0000">+ frequencyUnit: string</font></td></tr>
                  <tr><td align="left" port="approximationType"><font color="#8b0000">+ approximationType: string</font></td></tr>
                  <tr><td align="left" port="approximationLowerBound"><font color="#8b0000">+ approximationLowerBound: float  [0..1]</font></td></tr>
                  <tr><td align="left" port="approximationUpperBound"><font color="#8b0000">+ approximationUpperBound: float  [0..1]</font></td></tr>
                  <tr><td align="left" port="approximationError"><font color="#8b0000">+ approximationError: float  [0..1]</font></td></tr>
                  <tr><td align="left" port="numberOfCoefficients"><font color="#8b0000">+ numberOfCoefficients: int  [0..1]</font></td></tr>
                  <tr><td align="left" port="coefficients"><font color="#8b0000">+ coefficients: RealArray  [0..1]</font></td></tr>
                  <tr><td align="left" port="remark"><font color="#8b0000">+ remark: Blob  [0..1]</font></td></tr>
              </table>
          >
          href = "../base/api-python.html#api-python-datamodel-responsepolynomial"
          target = "_top"
      ]
      ResponseFAP [
          labeltooltip = "ResponseFAP"
          label = <
              <table border="0" cellpadding="0" cellspacing="2">
                  <tr><td>ResponseFAP</td></tr>
                  <hr/>
                  <tr><td> </td></tr>
                  <tr><td align="left" port="publicID"><font color="#8b0000">+ publicID: string</font></td></tr>
                  <tr><td align="left" port="name"><font color="#8b0000">+ name: string</font></td></tr>
                  <tr><td align="left" port="gain"><font color="#8b0000">+ gain: float  [0..1]</font></td></tr>
                  <tr><td align="left" port="gainFrequency"><font color="#8b0000">+ gainFrequency: float  [0..1]</font></td></tr>
                  <tr><td align="left" port="numberOfTuples"><font color="#8b0000">+ numberOfTuples: int  [0..1]</font></td></tr>
                  <tr><td align="left" port="tuples"><font color="#8b0000">+ tuples: RealArray  [0..1]</font></td></tr>
                  <tr><td align="left" port="remark"><font color="#8b0000">+ remark: Blob  [0..1]</font></td></tr>
              </table>
          >
          href = "../base/api-python.html#api-python-datamodel-responsefap"
          target = "_top"
      ]
      Network [
          labeltooltip = "Network"
          label = <
              <table border="0" cellpadding="0" cellspacing="2">
                  <tr><td>Network</td></tr>
                  <hr/>
                  <tr><td> </td></tr>
                  <tr><td align="left" port="publicID"><font color="#8b0000">+ publicID: string</font></td></tr>
                  <tr><td align="left" port="code"><font color="#8b0000">+ code: string</font></td></tr>
                  <tr><td align="left" port="start"><font color="#8b0000">+ start: datetime</font></td></tr>
                  <tr><td align="left" port="end"><font color="#8b0000">+ end: datetime  [0..1]</font></td></tr>
                  <tr><td align="left" port="description"><font color="#8b0000">+ description: string</font></td></tr>
                  <tr><td align="left" port="institutions"><font color="#8b0000">+ institutions: string</font></td></tr>
                  <tr><td align="left" port="region"><font color="#8b0000">+ region: string</font></td></tr>
                  <tr><td align="left" port="type"><font color="#8b0000">+ type: string</font></td></tr>
                  <tr><td align="left" port="netClass"><font color="#8b0000">+ netClass: string</font></td></tr>
                  <tr><td align="left" port="archive"><font color="#8b0000">+ archive: string</font></td></tr>
                  <tr><td align="left" port="restricted"><font color="#8b0000">+ restricted: boolean  [0..1]</font></td></tr>
                  <tr><td align="left" port="shared"><font color="#8b0000">+ shared: boolean  [0..1]</font></td></tr>
                  <tr><td align="left" port="remark"><font color="#8b0000">+ remark: Blob  [0..1]</font></td></tr>
                  <tr><td align="left"><font color="#8b0000">+ comment: Comment [0..*]</font></td></tr>
                  <tr><td align="left"><font color="#8b0000">+ station: Station [0..*]</font></td></tr>
              </table>
          >
          href = "../base/api-python.html#api-python-datamodel-network"
          target = "_top"
      ]
      Comment [
          labeltooltip = "Comment"
          label = <
              <table border="0" cellpadding="0" cellspacing="2">
                  <tr><td>Comment</td></tr>
                  <hr/>
                  <tr><td> </td></tr>
                  <tr><td align="left" port="text"><font color="#8b0000">+ text: string</font></td></tr>
                  <tr><td align="left" port="id"><font color="#8b0000">+ id: string</font></td></tr>
                  <tr><td align="left" port="start"><font color="#8b0000">+ start: datetime  [0..1]</font></td></tr>
                  <tr><td align="left" port="end"><font color="#8b0000">+ end: datetime  [0..1]</font></td></tr>
                  <tr><td align="left" port="creationInfo"><font color="#8b0000">+ creationInfo: CreationInfo  [0..1]</font></td></tr>
              </table>
          >
          href = "../base/api-python.html#api-python-datamodel-comment"
          target = "_top"
      ]
      Station [
          labeltooltip = "Station"
          label = <
              <table border="0" cellpadding="0" cellspacing="2">
                  <tr><td>Station</td></tr>
                  <hr/>
                  <tr><td> </td></tr>
                  <tr><td align="left" port="publicID"><font color="#8b0000">+ publicID: string</font></td></tr>
                  <tr><td align="left" port="code"><font color="#8b0000">+ code: string</font></td></tr>
                  <tr><td align="left" port="start"><font color="#8b0000">+ start: datetime</font></td></tr>
                  <tr><td align="left" port="end"><font color="#8b0000">+ end: datetime  [0..1]</font></td></tr>
                  <tr><td align="left" port="description"><font color="#8b0000">+ description: string</font></td></tr>
                  <tr><td align="left" port="latitude"><font color="#8b0000">+ latitude: float  [0..1]</font></td></tr>
                  <tr><td align="left" port="longitude"><font color="#8b0000">+ longitude: float  [0..1]</font></td></tr>
                  <tr><td align="left" port="elevation"><font color="#8b0000">+ elevation: float  [0..1]</font></td></tr>
                  <tr><td align="left" port="place"><font color="#8b0000">+ place: string</font></td></tr>
                  <tr><td align="left" port="country"><font color="#8b0000">+ country: string</font></td></tr>
                  <tr><td align="left" port="affiliation"><font color="#8b0000">+ affiliation: string</font></td></tr>
                  <tr><td align="left" port="type"><font color="#8b0000">+ type: string</font></td></tr>
                  <tr><td align="left" port="archive"><font color="#8b0000">+ archive: string</font></td></tr>
                  <tr><td align="left" port="archiveNetworkCode"><font color="#8b0000">+ archiveNetworkCode: string</font></td></tr>
                  <tr><td align="left" port="restricted"><font color="#8b0000">+ restricted: boolean  [0..1]</font></td></tr>
                  <tr><td align="left" port="shared"><font color="#8b0000">+ shared: boolean  [0..1]</font></td></tr>
                  <tr><td align="left" port="remark"><font color="#8b0000">+ remark: Blob  [0..1]</font></td></tr>
                  <tr><td align="left"><font color="#8b0000">+ comment: Comment [0..*]</font></td></tr>
                  <tr><td align="left"><font color="#8b0000">+ sensorLocation: SensorLocation [0..*]</font></td></tr>
              </table>
          >
          href = "../base/api-python.html#api-python-datamodel-station"
          target = "_top"
      ]
      SensorLocation [
          labeltooltip = "SensorLocation"
          label = <
              <table border="0" cellpadding="0" cellspacing="2">
                  <tr><td>SensorLocation</td></tr>
                  <hr/>
                  <tr><td> </td></tr>
                  <tr><td align="left" port="publicID"><font color="#8b0000">+ publicID: string</font></td></tr>
                  <tr><td align="left" port="code"><font color="#8b0000">+ code: string</font></td></tr>
                  <tr><td align="left" port="start"><font color="#8b0000">+ start: datetime</font></td></tr>
                  <tr><td align="left" port="end"><font color="#8b0000">+ end: datetime  [0..1]</font></td></tr>
                  <tr><td align="left" port="latitude"><font color="#8b0000">+ latitude: float  [0..1]</font></td></tr>
                  <tr><td align="left" port="longitude"><font color="#8b0000">+ longitude: float  [0..1]</font></td></tr>
                  <tr><td align="left" port="elevation"><font color="#8b0000">+ elevation: float  [0..1]</font></td></tr>
                  <tr><td align="left"><font color="#8b0000">+ comment: Comment [0..*]</font></td></tr>
                  <tr><td align="left"><font color="#8b0000">+ auxStream: AuxStream [0..*]</font></td></tr>
                  <tr><td align="left"><font color="#8b0000">+ stream: Stream [0..*]</font></td></tr>
              </table>
          >
          href = "../base/api-python.html#api-python-datamodel-sensorlocation"
          target = "_top"
      ]
      AuxStream [
          labeltooltip = "AuxStream"
          label = <
              <table border="0" cellpadding="0" cellspacing="2">
                  <tr><td>AuxStream</td></tr>
                  <hr/>
                  <tr><td> </td></tr>
                  <tr><td align="left" port="code"><font color="#8b0000">+ code: string</font></td></tr>
                  <tr><td align="left" port="start"><font color="#8b0000">+ start: datetime</font></td></tr>
                  <tr><td align="left" port="end"><font color="#8b0000">+ end: datetime  [0..1]</font></td></tr>
                  <tr><td align="left" port="device"><font color="#8b0000">+ device: string</font></td></tr>
                  <tr><td align="left" port="deviceSerialNumber"><font color="#8b0000">+ deviceSerialNumber: string</font></td></tr>
                  <tr><td align="left" port="source"><font color="#8b0000">+ source: string</font></td></tr>
                  <tr><td align="left" port="format"><font color="#8b0000">+ format: string</font></td></tr>
                  <tr><td align="left" port="flags"><font color="#8b0000">+ flags: string</font></td></tr>
                  <tr><td align="left" port="restricted"><font color="#8b0000">+ restricted: boolean  [0..1]</font></td></tr>
                  <tr><td align="left" port="shared"><font color="#8b0000">+ shared: boolean  [0..1]</font></td></tr>
              </table>
          >
          href = "../base/api-python.html#api-python-datamodel-auxstream"
          target = "_top"
      ]
      Stream [
          labeltooltip = "Stream"
          label = <
              <table border="0" cellpadding="0" cellspacing="2">
                  <tr><td>Stream</td></tr>
                  <hr/>
                  <tr><td> </td></tr>
                  <tr><td align="left" port="publicID"><font color="#8b0000">+ publicID: string</font></td></tr>
                  <tr><td align="left" port="code"><font color="#8b0000">+ code: string</font></td></tr>
                  <tr><td align="left" port="start"><font color="#8b0000">+ start: datetime</font></td></tr>
                  <tr><td align="left" port="end"><font color="#8b0000">+ end: datetime  [0..1]</font></td></tr>
                  <tr><td align="left" port="datalogger"><font color="#8b0000">+ datalogger: string</font></td></tr>
                  <tr><td align="left" port="dataloggerSerialNumber"><font color="#8b0000">+ dataloggerSerialNumber: string</font></td></tr>
                  <tr><td align="left" port="dataloggerChannel"><font color="#8b0000">+ dataloggerChannel: int  [0..1]</font></td></tr>
                  <tr><td align="left" port="sensor"><font color="#8b0000">+ sensor: string</font></td></tr>
                  <tr><td align="left" port="sensorSerialNumber"><font color="#8b0000">+ sensorSerialNumber: string</font></td></tr>
                  <tr><td align="left" port="sensorChannel"><font color="#8b0000">+ sensorChannel: int  [0..1]</font></td></tr>
                  <tr><td align="left" port="clockSerialNumber"><font color="#8b0000">+ clockSerialNumber: string</font></td></tr>
                  <tr><td align="left" port="sampleRateNumerator"><font color="#8b0000">+ sampleRateNumerator: int  [0..1]</font></td></tr>
                  <tr><td align="left" port="sampleRateDenominator"><font color="#8b0000">+ sampleRateDenominator: int  [0..1]</font></td></tr>
                  <tr><td align="left" port="depth"><font color="#8b0000">+ depth: float  [0..1]</font></td></tr>
                  <tr><td align="left" port="azimuth"><font color="#8b0000">+ azimuth: float  [0..1]</font></td></tr>
                  <tr><td align="left" port="dip"><font color="#8b0000">+ dip: float  [0..1]</font></td></tr>
                  <tr><td align="left" port="gain"><font color="#8b0000">+ gain: float  [0..1]</font></td></tr>
                  <tr><td align="left" port="gainFrequency"><font color="#8b0000">+ gainFrequency: float  [0..1]</font></td></tr>
                  <tr><td align="left" port="gainUnit"><font color="#8b0000">+ gainUnit: string</font></td></tr>
                  <tr><td align="left" port="format"><font color="#8b0000">+ format: string</font></td></tr>
                  <tr><td align="left" port="flags"><font color="#8b0000">+ flags: string</font></td></tr>
                  <tr><td align="left" port="restricted"><font color="#8b0000">+ restricted: boolean  [0..1]</font></td></tr>
                  <tr><td align="left" port="shared"><font color="#8b0000">+ shared: boolean  [0..1]</font></td></tr>
                  <tr><td align="left"><font color="#8b0000">+ comment: Comment [0..*]</font></td></tr>
              </table>
          >
          href = "../base/api-python.html#api-python-datamodel-stream"
          target = "_top"
      ]
      Inventory [
          labeltooltip = "Inventory"
          label = <
              <table border="0" cellpadding="0" cellspacing="2">
                  <tr><td>Inventory</td></tr>
                  <hr/>
                  <tr><td> </td></tr>
                  <tr><td align="left" port="publicID"><font color="#8b0000">+ publicID: string</font></td></tr>
                  <tr><td align="left"><font color="#8b0000">+ stationGroup: StationGroup [0..*]</font></td></tr>
                  <tr><td align="left"><font color="#8b0000">+ auxDevice: AuxDevice [0..*]</font></td></tr>
                  <tr><td align="left"><font color="#8b0000">+ sensor: Sensor [0..*]</font></td></tr>
                  <tr><td align="left"><font color="#8b0000">+ datalogger: Datalogger [0..*]</font></td></tr>
                  <tr><td align="left"><font color="#8b0000">+ responsePAZ: ResponsePAZ [0..*]</font></td></tr>
                  <tr><td align="left"><font color="#8b0000">+ responseFIR: ResponseFIR [0..*]</font></td></tr>
                  <tr><td align="left"><font color="#8b0000">+ responseIIR: ResponseIIR [0..*]</font></td></tr>
                  <tr><td align="left"><font color="#8b0000">+ responsePolynomial: ResponsePolynomial [0..*]</font></td></tr>
                  <tr><td align="left"><font color="#8b0000">+ responseFAP: ResponseFAP [0..*]</font></td></tr>
                  <tr><td align="left"><font color="#8b0000">+ network: Network [0..*]</font></td></tr>
              </table>
          >
          href = "../base/api-python.html#api-python-datamodel-inventory"
          target = "_top"
      ]
      Inventory -> StationGroup [dir=back arrowtail=diamond]
      StationGroup -> StationReference [dir=back arrowtail=diamond]
      Inventory -> AuxDevice [dir=back arrowtail=diamond]
      AuxDevice -> AuxSource [dir=back arrowtail=diamond]
      Inventory -> Sensor [dir=back arrowtail=diamond]
      Sensor -> SensorCalibration [dir=back arrowtail=diamond]
      Inventory -> Datalogger [dir=back arrowtail=diamond]
      Datalogger -> DataloggerCalibration [dir=back arrowtail=diamond]
      Datalogger -> Decimation [dir=back arrowtail=diamond]
      Inventory -> ResponsePAZ [dir=back arrowtail=diamond]
      Inventory -> ResponseFIR [dir=back arrowtail=diamond]
      Inventory -> ResponseIIR [dir=back arrowtail=diamond]
      Inventory -> ResponsePolynomial [dir=back arrowtail=diamond]
      Inventory -> ResponseFAP [dir=back arrowtail=diamond]
      Inventory -> Network [dir=back arrowtail=diamond]
      Stream -> Comment [dir=back arrowtail=diamond]
      SensorLocation -> Comment [dir=back arrowtail=diamond]
      Station -> Comment [dir=back arrowtail=diamond]
      Network -> Comment [dir=back arrowtail=diamond]
      Network -> Station [dir=back arrowtail=diamond]
      Station -> SensorLocation [dir=back arrowtail=diamond]
      SensorLocation -> AuxStream [dir=back arrowtail=diamond]
      SensorLocation -> Stream [dir=back arrowtail=diamond]
   }


Routing
............................................................


.. graphviz::
   :name: Routing
   :caption: Routing object connections from parent to child including attributes and elements.
   :align: center

   digraph "Routing hierarchy" {
      node [fontname=Verdana fontsize=8 shape=plaintext penwidth=0.5 style="rounded,filled" fillcolor="#fcf2e3" color="#000000"]
      edge [color="#000000"]
      layout = "dot"
      Route [
          labeltooltip = "Route"
          label = <
              <table border="0" cellpadding="0" cellspacing="2">
                  <tr><td>Route</td></tr>
                  <hr/>
                  <tr><td> </td></tr>
                  <tr><td align="left" port="publicID"><font color="#8b0000">+ publicID: string</font></td></tr>
                  <tr><td align="left" port="networkCode"><font color="#8b0000">+ networkCode: string</font></td></tr>
                  <tr><td align="left" port="stationCode"><font color="#8b0000">+ stationCode: string</font></td></tr>
                  <tr><td align="left" port="locationCode"><font color="#8b0000">+ locationCode: string</font></td></tr>
                  <tr><td align="left" port="streamCode"><font color="#8b0000">+ streamCode: string</font></td></tr>
                  <tr><td align="left"><font color="#8b0000">+ routeArclink: RouteArclink [0..*]</font></td></tr>
                  <tr><td align="left"><font color="#8b0000">+ routeSeedlink: RouteSeedlink [0..*]</font></td></tr>
              </table>
          >
          href = "../base/api-python.html#api-python-datamodel-route"
          target = "_top"
      ]
      RouteArclink [
          labeltooltip = "RouteArclink"
          label = <
              <table border="0" cellpadding="0" cellspacing="2">
                  <tr><td>RouteArclink</td></tr>
                  <hr/>
                  <tr><td> </td></tr>
                  <tr><td align="left" port="address"><font color="#8b0000">+ address: string</font></td></tr>
                  <tr><td align="left" port="start"><font color="#8b0000">+ start: datetime</font></td></tr>
                  <tr><td align="left" port="end"><font color="#8b0000">+ end: datetime  [0..1]</font></td></tr>
                  <tr><td align="left" port="priority"><font color="#8b0000">+ priority: int  [0..1]</font></td></tr>
              </table>
          >
          href = "../base/api-python.html#api-python-datamodel-routearclink"
          target = "_top"
      ]
      RouteSeedlink [
          labeltooltip = "RouteSeedlink"
          label = <
              <table border="0" cellpadding="0" cellspacing="2">
                  <tr><td>RouteSeedlink</td></tr>
                  <hr/>
                  <tr><td> </td></tr>
                  <tr><td align="left" port="address"><font color="#8b0000">+ address: string</font></td></tr>
                  <tr><td align="left" port="priority"><font color="#8b0000">+ priority: int  [0..1]</font></td></tr>
              </table>
          >
          href = "../base/api-python.html#api-python-datamodel-routeseedlink"
          target = "_top"
      ]
      Access [
          labeltooltip = "Access"
          label = <
              <table border="0" cellpadding="0" cellspacing="2">
                  <tr><td>Access</td></tr>
                  <hr/>
                  <tr><td> </td></tr>
                  <tr><td align="left" port="networkCode"><font color="#8b0000">+ networkCode: string</font></td></tr>
                  <tr><td align="left" port="stationCode"><font color="#8b0000">+ stationCode: string</font></td></tr>
                  <tr><td align="left" port="locationCode"><font color="#8b0000">+ locationCode: string</font></td></tr>
                  <tr><td align="left" port="streamCode"><font color="#8b0000">+ streamCode: string</font></td></tr>
                  <tr><td align="left" port="user"><font color="#8b0000">+ user: string</font></td></tr>
                  <tr><td align="left" port="start"><font color="#8b0000">+ start: datetime</font></td></tr>
                  <tr><td align="left" port="end"><font color="#8b0000">+ end: datetime  [0..1]</font></td></tr>
              </table>
          >
          href = "../base/api-python.html#api-python-datamodel-access"
          target = "_top"
      ]
      Routing [
          labeltooltip = "Routing"
          label = <
              <table border="0" cellpadding="0" cellspacing="2">
                  <tr><td>Routing</td></tr>
                  <hr/>
                  <tr><td> </td></tr>
                  <tr><td align="left" port="publicID"><font color="#8b0000">+ publicID: string</font></td></tr>
                  <tr><td align="left"><font color="#8b0000">+ route: Route [0..*]</font></td></tr>
                  <tr><td align="left"><font color="#8b0000">+ access: Access [0..*]</font></td></tr>
              </table>
          >
          href = "../base/api-python.html#api-python-datamodel-routing"
          target = "_top"
      ]
      Routing -> Route [dir=back arrowtail=diamond]
      Route -> RouteArclink [dir=back arrowtail=diamond]
      Route -> RouteSeedlink [dir=back arrowtail=diamond]
      Routing -> Access [dir=back arrowtail=diamond]
   }


Journaling
............................................................


.. graphviz::
   :name: Journaling
   :caption: Journaling object connections from parent to child including attributes and elements.
   :align: center

   digraph "Journaling hierarchy" {
      node [fontname=Verdana fontsize=8 shape=plaintext penwidth=0.5 style="rounded,filled" fillcolor="#fcf2e3" color="#000000"]
      edge [color="#000000"]
      layout = "dot"
      JournalEntry [
          labeltooltip = "JournalEntry"
          label = <
              <table border="0" cellpadding="0" cellspacing="2">
                  <tr><td>JournalEntry</td></tr>
                  <hr/>
                  <tr><td> </td></tr>
                  <tr><td align="left" port="created"><font color="#8b0000">+ created: datetime  [0..1]</font></td></tr>
                  <tr><td align="left" port="objectID"><font color="#8b0000">+ objectID: string</font></td></tr>
                  <tr><td align="left" port="sender"><font color="#8b0000">+ sender: string</font></td></tr>
                  <tr><td align="left" port="action"><font color="#8b0000">+ action: string</font></td></tr>
                  <tr><td align="left" port="parameters"><font color="#8b0000">+ parameters: string</font></td></tr>
              </table>
          >
          href = "../base/api-python.html#api-python-datamodel-journalentry"
          target = "_top"
      ]
      Journaling [
          labeltooltip = "Journaling"
          label = <
              <table border="0" cellpadding="0" cellspacing="2">
                  <tr><td>Journaling</td></tr>
                  <hr/>
                  <tr><td> </td></tr>
                  <tr><td align="left" port="publicID"><font color="#8b0000">+ publicID: string</font></td></tr>
                  <tr><td align="left"><font color="#8b0000">+ journalEntry: JournalEntry [0..*]</font></td></tr>
              </table>
          >
          href = "../base/api-python.html#api-python-datamodel-journaling"
          target = "_top"
      ]
      Journaling -> JournalEntry [dir=back arrowtail=diamond]
   }


ArclinkLog
............................................................


.. graphviz::
   :name: ArclinkLog
   :caption: ArclinkLog object connections from parent to child including attributes and elements.
   :align: center

   digraph "ArclinkLog hierarchy" {
      node [fontname=Verdana fontsize=8 shape=plaintext penwidth=0.5 style="rounded,filled" fillcolor="#fcf2e3" color="#000000"]
      edge [color="#000000"]
      layout = "dot"
      ArclinkRequest [
          labeltooltip = "ArclinkRequest"
          label = <
              <table border="0" cellpadding="0" cellspacing="2">
                  <tr><td>ArclinkRequest</td></tr>
                  <hr/>
                  <tr><td> </td></tr>
                  <tr><td align="left" port="publicID"><font color="#8b0000">+ publicID: string</font></td></tr>
                  <tr><td align="left" port="requestID"><font color="#8b0000">+ requestID: string</font></td></tr>
                  <tr><td align="left" port="userID"><font color="#8b0000">+ userID: string</font></td></tr>
                  <tr><td align="left" port="userIP"><font color="#8b0000">+ userIP: string</font></td></tr>
                  <tr><td align="left" port="clientID"><font color="#8b0000">+ clientID: string</font></td></tr>
                  <tr><td align="left" port="clientIP"><font color="#8b0000">+ clientIP: string</font></td></tr>
                  <tr><td align="left" port="type"><font color="#8b0000">+ type: string</font></td></tr>
                  <tr><td align="left" port="created"><font color="#8b0000">+ created: datetime</font></td></tr>
                  <tr><td align="left" port="status"><font color="#8b0000">+ status: string</font></td></tr>
                  <tr><td align="left" port="message"><font color="#8b0000">+ message: string</font></td></tr>
                  <tr><td align="left" port="label"><font color="#8b0000">+ label: string</font></td></tr>
                  <tr><td align="left" port="header"><font color="#8b0000">+ header: string</font></td></tr>
                  <tr><td align="left" port="summary"><font color="#8b0000">+ summary: ArclinkRequestSummary  [0..1]</font></td></tr>
                  <tr><td align="left"><font color="#8b0000">+ arclinkStatusLine: ArclinkStatusLine [0..*]</font></td></tr>
                  <tr><td align="left"><font color="#8b0000">+ arclinkRequestLine: ArclinkRequestLine [0..*]</font></td></tr>
              </table>
          >
          href = "../base/api-python.html#api-python-datamodel-arclinkrequest"
          target = "_top"
      ]
      ArclinkStatusLine [
          labeltooltip = "ArclinkStatusLine"
          label = <
              <table border="0" cellpadding="0" cellspacing="2">
                  <tr><td>ArclinkStatusLine</td></tr>
                  <hr/>
                  <tr><td> </td></tr>
                  <tr><td align="left" port="type"><font color="#8b0000">+ type: string</font></td></tr>
                  <tr><td align="left" port="status"><font color="#8b0000">+ status: string</font></td></tr>
                  <tr><td align="left" port="size"><font color="#8b0000">+ size: int  [0..1]</font></td></tr>
                  <tr><td align="left" port="message"><font color="#8b0000">+ message: string</font></td></tr>
                  <tr><td align="left" port="volumeID"><font color="#8b0000">+ volumeID: string</font></td></tr>
              </table>
          >
          href = "../base/api-python.html#api-python-datamodel-arclinkstatusline"
          target = "_top"
      ]
      ArclinkRequestLine [
          labeltooltip = "ArclinkRequestLine"
          label = <
              <table border="0" cellpadding="0" cellspacing="2">
                  <tr><td>ArclinkRequestLine</td></tr>
                  <hr/>
                  <tr><td> </td></tr>
                  <tr><td align="left" port="start"><font color="#8b0000">+ start: datetime</font></td></tr>
                  <tr><td align="left" port="end"><font color="#8b0000">+ end: datetime</font></td></tr>
                  <tr><td align="left" port="streamID"><font color="#8b0000">+ streamID: WaveformStreamID</font></td></tr>
                  <tr><td align="left" port="restricted"><font color="#8b0000">+ restricted: boolean  [0..1]</font></td></tr>
                  <tr><td align="left" port="shared"><font color="#8b0000">+ shared: boolean  [0..1]</font></td></tr>
                  <tr><td align="left" port="netClass"><font color="#8b0000">+ netClass: string</font></td></tr>
                  <tr><td align="left" port="constraints"><font color="#8b0000">+ constraints: string</font></td></tr>
                  <tr><td align="left" port="status"><font color="#8b0000">+ status: ArclinkStatusLine</font></td></tr>
              </table>
          >
          href = "../base/api-python.html#api-python-datamodel-arclinkrequestline"
          target = "_top"
      ]
      ArclinkUser [
          labeltooltip = "ArclinkUser"
          label = <
              <table border="0" cellpadding="0" cellspacing="2">
                  <tr><td>ArclinkUser</td></tr>
                  <hr/>
                  <tr><td> </td></tr>
                  <tr><td align="left" port="publicID"><font color="#8b0000">+ publicID: string</font></td></tr>
                  <tr><td align="left" port="name"><font color="#8b0000">+ name: string</font></td></tr>
                  <tr><td align="left" port="email"><font color="#8b0000">+ email: string</font></td></tr>
                  <tr><td align="left" port="password"><font color="#8b0000">+ password: string</font></td></tr>
              </table>
          >
          href = "../base/api-python.html#api-python-datamodel-arclinkuser"
          target = "_top"
      ]
      ArclinkLog [
          labeltooltip = "ArclinkLog"
          label = <
              <table border="0" cellpadding="0" cellspacing="2">
                  <tr><td>ArclinkLog</td></tr>
                  <hr/>
                  <tr><td> </td></tr>
                  <tr><td align="left" port="publicID"><font color="#8b0000">+ publicID: string</font></td></tr>
                  <tr><td align="left"><font color="#8b0000">+ arclinkRequest: ArclinkRequest [0..*]</font></td></tr>
                  <tr><td align="left"><font color="#8b0000">+ arclinkUser: ArclinkUser [0..*]</font></td></tr>
              </table>
          >
          href = "../base/api-python.html#api-python-datamodel-arclinklog"
          target = "_top"
      ]
      ArclinkLog -> ArclinkRequest [dir=back arrowtail=diamond]
      ArclinkRequest -> ArclinkStatusLine [dir=back arrowtail=diamond]
      ArclinkRequest -> ArclinkRequestLine [dir=back arrowtail=diamond]
      ArclinkLog -> ArclinkUser [dir=back arrowtail=diamond]
   }


DataAvailability
............................................................


.. graphviz::
   :name: DataAvailability
   :caption: DataAvailability object connections from parent to child including attributes and elements.
   :align: center

   digraph "DataAvailability hierarchy" {
      node [fontname=Verdana fontsize=8 shape=plaintext penwidth=0.5 style="rounded,filled" fillcolor="#fcf2e3" color="#000000"]
      edge [color="#000000"]
      layout = "dot"
      DataExtent [
          labeltooltip = "DataExtent"
          label = <
              <table border="0" cellpadding="0" cellspacing="2">
                  <tr><td>DataExtent</td></tr>
                  <hr/>
                  <tr><td> </td></tr>
                  <tr><td align="left" port="publicID"><font color="#8b0000">+ publicID: string</font></td></tr>
                  <tr><td align="left" port="waveformID"><font color="#8b0000">+ waveformID: WaveformStreamID</font></td></tr>
                  <tr><td align="left" port="start"><font color="#8b0000">+ start: datetime</font></td></tr>
                  <tr><td align="left" port="end"><font color="#8b0000">+ end: datetime</font></td></tr>
                  <tr><td align="left" port="updated"><font color="#8b0000">+ updated: datetime</font></td></tr>
                  <tr><td align="left" port="lastScan"><font color="#8b0000">+ lastScan: datetime</font></td></tr>
                  <tr><td align="left" port="segmentOverflow"><font color="#8b0000">+ segmentOverflow: boolean</font></td></tr>
                  <tr><td align="left"><font color="#8b0000">+ dataSegment: DataSegment [0..*]</font></td></tr>
                  <tr><td align="left"><font color="#8b0000">+ dataAttributeExtent: DataAttributeExtent [0..*]</font></td></tr>
              </table>
          >
          href = "../base/api-python.html#api-python-datamodel-dataextent"
          target = "_top"
      ]
      DataSegment [
          labeltooltip = "DataSegment"
          label = <
              <table border="0" cellpadding="0" cellspacing="2">
                  <tr><td>DataSegment</td></tr>
                  <hr/>
                  <tr><td> </td></tr>
                  <tr><td align="left" port="start"><font color="#8b0000">+ start: datetime</font></td></tr>
                  <tr><td align="left" port="end"><font color="#8b0000">+ end: datetime</font></td></tr>
                  <tr><td align="left" port="updated"><font color="#8b0000">+ updated: datetime</font></td></tr>
                  <tr><td align="left" port="sampleRate"><font color="#8b0000">+ sampleRate: double</font></td></tr>
                  <tr><td align="left" port="quality"><font color="#8b0000">+ quality: string</font></td></tr>
                  <tr><td align="left" port="outOfOrder"><font color="#8b0000">+ outOfOrder: boolean</font></td></tr>
              </table>
          >
          href = "../base/api-python.html#api-python-datamodel-datasegment"
          target = "_top"
      ]
      DataAttributeExtent [
          labeltooltip = "DataAttributeExtent"
          label = <
              <table border="0" cellpadding="0" cellspacing="2">
                  <tr><td>DataAttributeExtent</td></tr>
                  <hr/>
                  <tr><td> </td></tr>
                  <tr><td align="left" port="start"><font color="#8b0000">+ start: datetime</font></td></tr>
                  <tr><td align="left" port="end"><font color="#8b0000">+ end: datetime</font></td></tr>
                  <tr><td align="left" port="sampleRate"><font color="#8b0000">+ sampleRate: double</font></td></tr>
                  <tr><td align="left" port="quality"><font color="#8b0000">+ quality: string</font></td></tr>
                  <tr><td align="left" port="updated"><font color="#8b0000">+ updated: datetime</font></td></tr>
                  <tr><td align="left" port="segmentCount"><font color="#8b0000">+ segmentCount: int</font></td></tr>
              </table>
          >
          href = "../base/api-python.html#api-python-datamodel-dataattributeextent"
          target = "_top"
      ]
      DataAvailability [
          labeltooltip = "DataAvailability"
          label = <
              <table border="0" cellpadding="0" cellspacing="2">
                  <tr><td>DataAvailability</td></tr>
                  <hr/>
                  <tr><td> </td></tr>
                  <tr><td align="left" port="publicID"><font color="#8b0000">+ publicID: string</font></td></tr>
                  <tr><td align="left"><font color="#8b0000">+ dataExtent: DataExtent [0..*]</font></td></tr>
              </table>
          >
          href = "../base/api-python.html#api-python-datamodel-dataavailability"
          target = "_top"
      ]
      DataAvailability -> DataExtent [dir=back arrowtail=diamond]
      DataExtent -> DataSegment [dir=back arrowtail=diamond]
      DataExtent -> DataAttributeExtent [dir=back arrowtail=diamond]
   }



Enumerations
------------

* :ref:`DataUsedWaveType <api-python-datamodel-datausedwavetype>`
* :ref:`EvaluationMode <api-python-datamodel-evaluationmode>`
* :ref:`EvaluationStatus <api-python-datamodel-evaluationstatus>`
* :ref:`EventDescriptionType <api-python-datamodel-eventdescriptiontype>`
* :ref:`EventType <api-python-datamodel-eventtype>`
* :ref:`EventTypeCertainty <api-python-datamodel-eventtypecertainty>`
* :ref:`MomentTensorMethod <api-python-datamodel-momenttensormethod>`
* :ref:`MomentTensorStatus <api-python-datamodel-momenttensorstatus>`
* :ref:`OriginDepthType <api-python-datamodel-origindepthtype>`
* :ref:`OriginType <api-python-datamodel-origintype>`
* :ref:`OriginUncertaintyDescription <api-python-datamodel-originuncertaintydescription>`
* :ref:`PickOnset <api-python-datamodel-pickonset>`
* :ref:`PickPolarity <api-python-datamodel-pickpolarity>`
* :ref:`SourceTimeFunctionType <api-python-datamodel-sourcetimefunctiontype>`
* :ref:`StationGroupType <api-python-datamodel-stationgrouptype>`

.. _api-python-datamodel-datausedwavetype:

**DataUsedWaveType**

.. list-table::
   :header-rows: 1

   * - ID
     - Numeric value
     - String value
   * - ``BODY_WAVES``
     - 0
     - body waves
   * - ``P_BODY_WAVES``
     - 1
     - P body waves
   * - ``LONG_PERIOD_BODY_WAVES``
     - 2
     - long-period body waves
   * - ``SURFACE_WAVES``
     - 3
     - surface waves
   * - ``INTERMEDIATE_PERIOD_SURFACE_WAVES``
     - 4
     - intermediate-period surface waves
   * - ``LONG_PERIOD_MANTLE_WAVES``
     - 5
     - long-period mantle waves
   * - ``UNKNOWN_WAVETYPE``
     - 6
     - unknown

Used by:

* :func:`DataUsed.waveType`

.. _api-python-datamodel-evaluationmode:

**EvaluationMode**

.. list-table::
   :header-rows: 1

   * - ID
     - Numeric value
     - String value
   * - ``MANUAL``
     - 0
     - manual
   * - ``AUTOMATIC``
     - 1
     - automatic

Used by:

* :func:`Amplitude.evaluationMode`
* :func:`FocalMechanism.evaluationMode`
* :func:`Origin.evaluationMode`
* :func:`Pick.evaluationMode`

.. _api-python-datamodel-evaluationstatus:

**EvaluationStatus**

.. list-table::
   :header-rows: 1

   * - ID
     - Numeric value
     - String value
   * - ``PRELIMINARY``
     - 0
     - preliminary
   * - ``CONFIRMED``
     - 1
     - confirmed
   * - ``REVIEWED``
     - 2
     - reviewed
   * - ``FINAL``
     - 3
     - final
   * - ``REJECTED``
     - 4
     - rejected
   * - ``REPORTED``
     - 5
     - reported

Used by:

* :func:`FocalMechanism.evaluationStatus`
* :func:`Magnitude.evaluationStatus`
* :func:`Origin.evaluationStatus`
* :func:`Pick.evaluationStatus`

.. _api-python-datamodel-eventdescriptiontype:

**EventDescriptionType**

.. list-table::
   :header-rows: 1

   * - ID
     - Numeric value
     - String value
   * - ``FELT_REPORT``
     - 0
     - felt report
   * - ``FLINN_ENGDAHL_REGION``
     - 1
     - Flinn-Engdahl region
   * - ``LOCAL_TIME``
     - 2
     - local time
   * - ``TECTONIC_SUMMARY``
     - 3
     - tectonic summary
   * - ``NEAREST_CITIES``
     - 4
     - nearest cities
   * - ``EARTHQUAKE_NAME``
     - 5
     - earthquake name
   * - ``REGION_NAME``
     - 6
     - region name

Used by:

* :func:`EventDescription.type`

.. _api-python-datamodel-eventtype:

**EventType**

.. list-table::
   :header-rows: 1

   * - ID
     - Numeric value
     - String value
   * - ``NOT_EXISTING``
     - 0
     - not existing
   * - ``NOT_LOCATABLE``
     - 1
     - not locatable
   * - ``OUTSIDE_OF_NETWORK_INTEREST``
     - 2
     - outside of network interest
   * - ``EARTHQUAKE``
     - 3
     - earthquake
   * - ``INDUCED_EARTHQUAKE``
     - 4
     - induced earthquake
   * - ``QUARRY_BLAST``
     - 5
     - quarry blast
   * - ``EXPLOSION``
     - 6
     - explosion
   * - ``CHEMICAL_EXPLOSION``
     - 7
     - chemical explosion
   * - ``NUCLEAR_EXPLOSION``
     - 8
     - nuclear explosion
   * - ``LANDSLIDE``
     - 9
     - landslide
   * - ``ROCKSLIDE``
     - 10
     - rockslide
   * - ``SNOW_AVALANCHE``
     - 11
     - snow avalanche
   * - ``DEBRIS_AVALANCHE``
     - 12
     - debris avalanche
   * - ``MINE_COLLAPSE``
     - 13
     - mine collapse
   * - ``BUILDING_COLLAPSE``
     - 14
     - building collapse
   * - ``VOLCANIC_ERUPTION``
     - 15
     - volcanic eruption
   * - ``METEOR_IMPACT``
     - 16
     - meteor impact
   * - ``PLANE_CRASH``
     - 17
     - plane crash
   * - ``SONIC_BOOM``
     - 18
     - sonic boom
   * - ``DUPLICATE``
     - 19
     - duplicate
   * - ``OTHER_EVENT``
     - 20
     - other
   * - ``NOT_REPORTED``
     - 21
     - not reported
   * - ``ANTHROPOGENIC_EVENT``
     - 22
     - anthropogenic event
   * - ``COLLAPSE``
     - 23
     - collapse
   * - ``CAVITY_COLLAPSE``
     - 24
     - cavity collapse
   * - ``ACCIDENTAL_EXPLOSION``
     - 25
     - accidental explosion
   * - ``CONTROLLED_EXPLOSION``
     - 26
     - controlled explosion
   * - ``EXPERIMENTAL_EXPLOSION``
     - 27
     - experimental explosion
   * - ``INDUSTRIAL_EXPLOSION``
     - 28
     - industrial explosion
   * - ``MINING_EXPLOSION``
     - 29
     - mining explosion
   * - ``ROAD_CUT``
     - 30
     - road cut
   * - ``BLASTING_LEVEE``
     - 31
     - blasting levee
   * - ``INDUCED_OR_TRIGGERED_EVENT``
     - 32
     - induced or triggered event
   * - ``ROCK_BURST``
     - 33
     - rock burst
   * - ``RESERVOIR_LOADING``
     - 34
     - reservoir loading
   * - ``FLUID_INJECTION``
     - 35
     - fluid injection
   * - ``FLUID_EXTRACTION``
     - 36
     - fluid extraction
   * - ``CRASH``
     - 37
     - crash
   * - ``TRAIN_CRASH``
     - 38
     - train crash
   * - ``BOAT_CRASH``
     - 39
     - boat crash
   * - ``ATMOSPHERIC_EVENT``
     - 40
     - atmospheric event
   * - ``SONIC_BLAST``
     - 41
     - sonic blast
   * - ``ACOUSTIC_NOISE``
     - 42
     - acoustic noise
   * - ``THUNDER``
     - 43
     - thunder
   * - ``AVALANCHE``
     - 44
     - avalanche
   * - ``HYDROACOUSTIC_EVENT``
     - 45
     - hydroacoustic event
   * - ``ICE_QUAKE``
     - 46
     - ice quake
   * - ``SLIDE``
     - 47
     - slide
   * - ``METEORITE``
     - 48
     - meteorite
   * - ``CALVING``
     - 49
     - calving
   * - ``FROST_QUAKE``
     - 50
     - frost quake
   * - ``TREMOR_PULSE``
     - 51
     - tremor pulse
   * - ``SUBMARINE_LANDSLIDE``
     - 52
     - submarine landslide
   * - ``ROCKET_LAUNCH``
     - 53
     - rocket launch
   * - ``ROCKET``
     - 54
     - rocket
   * - ``ROCKET_IMPACT``
     - 55
     - rocket impact
   * - ``ARTILLERY_STRIKE``
     - 56
     - artillery strike
   * - ``BOMB_DETONATION``
     - 57
     - bomb detonation
   * - ``MOVING_AIRCRAFT``
     - 58
     - moving aircraft
   * - ``ATMOSPHERIC_METEOR_EXPLOSION``
     - 59
     - atmospheric meteor explosion

Used by:

* :func:`Event.type`

.. _api-python-datamodel-eventtypecertainty:

**EventTypeCertainty**

.. list-table::
   :header-rows: 1

   * - ID
     - Numeric value
     - String value
   * - ``KNOWN``
     - 0
     - known
   * - ``SUSPECTED``
     - 1
     - suspected
   * - ``DAMAGING``
     - 2
     - damaging
   * - ``FELT``
     - 3
     - felt

Used by:

* :func:`Event.typeCertainty`

.. _api-python-datamodel-momenttensormethod:

**MomentTensorMethod**

.. list-table::
   :header-rows: 1

   * - ID
     - Numeric value
     - String value
   * - ``CMT_0``
     - 0
     - CMT - general moment tensor
   * - ``CMT_1``
     - 1
     - CMT - moment tensor with zero trace
   * - ``CMT_2``
     - 2
     - CMT - double-couple source
   * - ``TELESEISMIC``
     - 3
     - teleseismic
   * - ``REGIONAL``
     - 4
     - regional

Used by:

* :func:`MomentTensor.method`

.. _api-python-datamodel-momenttensorstatus:

**MomentTensorStatus**

.. list-table::
   :header-rows: 1

   * - ID
     - Numeric value
     - String value
   * - ``CMT_S``
     - 0
     - standard CMT solution
   * - ``CMT_Q``
     - 1
     - quick CMT solution

Used by:

* :func:`MomentTensor.status`

.. _api-python-datamodel-origindepthtype:

**OriginDepthType**

.. list-table::
   :header-rows: 1

   * - ID
     - Numeric value
     - String value
   * - ``FROM_LOCATION``
     - 0
     - from location
   * - ``FROM_MOMENT_TENSOR_INVERSION``
     - 1
     - from moment tensor inversion
   * - ``BROAD_BAND_P_WAVEFORMS``
     - 2
     - from modeling of broad-band P waveforms
   * - ``CONSTRAINED_BY_DEPTH_PHASES``
     - 3
     - constrained by depth phases
   * - ``CONSTRAINED_BY_DIRECT_PHASES``
     - 4
     - constrained by direct phases
   * - ``OPERATOR_ASSIGNED``
     - 5
     - operator assigned
   * - ``OTHER_ORIGIN_DEPTH``
     - 6
     - other

Used by:

* :func:`Origin.depthType`

.. _api-python-datamodel-origintype:

**OriginType**

.. list-table::
   :header-rows: 1

   * - ID
     - Numeric value
     - String value
   * - ``HYPOCENTER``
     - 0
     - hypocenter
   * - ``CENTROID``
     - 1
     - centroid
   * - ``AMPLITUDE``
     - 2
     - amplitude
   * - ``MACROSEISMIC``
     - 3
     - macroseismic
   * - ``RUPTURE_START``
     - 4
     - rupture start
   * - ``RUPTURE_END``
     - 5
     - rupture end

Used by:

* :func:`Origin.type`

.. _api-python-datamodel-originuncertaintydescription:

**OriginUncertaintyDescription**

.. list-table::
   :header-rows: 1

   * - ID
     - Numeric value
     - String value
   * - ``HORIZONTAL``
     - 0
     - horizontal uncertainty
   * - ``ELLIPSE``
     - 1
     - uncertainty ellipse
   * - ``ELLIPSOID``
     - 2
     - confidence ellipsoid
   * - ``PDF``
     - 3
     - probability density function

Used by:

* :func:`OriginUncertainty.preferredDescription`

.. _api-python-datamodel-pickonset:

**PickOnset**

.. list-table::
   :header-rows: 1

   * - ID
     - Numeric value
     - String value
   * - ``EMERGENT``
     - 0
     - emergent
   * - ``IMPULSIVE``
     - 1
     - impulsive
   * - ``QUESTIONABLE``
     - 2
     - questionable

Used by:

* :func:`Pick.onset`

.. _api-python-datamodel-pickpolarity:

**PickPolarity**

.. list-table::
   :header-rows: 1

   * - ID
     - Numeric value
     - String value
   * - ``POSITIVE``
     - 0
     - positive
   * - ``NEGATIVE``
     - 1
     - negative
   * - ``UNDECIDABLE``
     - 2
     - undecidable

Used by:

* :func:`Pick.polarity`

.. _api-python-datamodel-sourcetimefunctiontype:

**SourceTimeFunctionType**

.. list-table::
   :header-rows: 1

   * - ID
     - Numeric value
     - String value
   * - ``BOX_CAR``
     - 0
     - box car
   * - ``TRIANGLE``
     - 1
     - triangle
   * - ``TRAPEZOID``
     - 2
     - trapezoid
   * - ``UNKNOWN_FUNCTION``
     - 3
     - unknown

Used by:

* :func:`SourceTimeFunction.type`

.. _api-python-datamodel-stationgrouptype:

**StationGroupType**

.. list-table::
   :header-rows: 1

   * - ID
     - Numeric value
     - String value
   * - ``DEPLOYMENT``
     - 0
     - deployment
   * - ``ARRAY``
     - 1
     - array

Used by:

* :func:`StationGroup.type`


Reference
---------

.. _api-python-datamodel-object:

Object
............................................................

.. py:class:: Object

   .. py:method:: parent()

      :rtype: PublicObject

      Returns the :ref:`PublicObject <api-python-datamodel-publicobject>`
      parent object is available, None otherwise.

   .. py:method:: setParent(parent)

      :param parent: A PublicObject.
      :rtype: A Boolean flag indicating success with True, False otherwise.

      Sets the parent to :ref:`PublicObject <api-python-datamodel-publicobject>`.
      This is an internal method and should not be called from applications.
      Instead a class should be derived from Object which calls
      this method internally when children are being added or removed.

   .. py:method:: update()

      Creates an update notifier for this object ignoring its children. If an
      attribute of an object is changed this methods needs to be called
      manually since attribute changes are not tracked automatically by the
      notifier framework. Only hierarchy modifications such as add and remove
      child objects.

   .. py:method:: assign(other)

      :param other: A Object.
      :rtype: A Boolean flag indicating success with True, False otherwise.

      Assign the metadata of 'other' to 'this' without others children.
      Returns True, if 'this' and 'other' are of same type, False otherwise.

   .. py:method:: clone()

      :rtype: A Object.

      Clones an object. If the clonee is a
      :ref:`PublicObject <api-python-datamodel-publicobject>`
      it is not registered in the global instance pool but receives exactly the
      same publicID like 'this'.

   .. py:method:: attachTo(parent)

      :rtype: A Boolean flag indicating success with True, False otherwise.

      Adds the object to a parent. If it has already a parent or is of
      wrong type, False is returned.

   .. py:method:: detachFrom(parent)

      :rtype: A Boolean flag indicating success with True, False otherwise.

      Removes the object from a parent. If it has another or no parent,
      False is returned.

   .. py:method:: detach()

      :rtype: A Boolean flag indicating success with True, False otherwise.

      Removes the object from its parent object if a parent is set.

   .. py:method:: accept(visitor)

      :param visitor: A visitor.


.. _api-python-datamodel-publicobject:

PublicObject
............................................................

.. py:class:: PublicObject

   Inherits :ref:`Object <api-python-datamodel-object>`.

   .. py:method:: setPublicID(id)

   Sets the publicID of the object.

   .. py:method:: publicID()

   Returns the publicID of the object.


.. _api-python-datamodel-notifier:

Notifier
........

.. py:class:: Notifier(parentID, operation, object)

   Class to represent a change in the object tree. A notifier takes a parentID,
   an operation to apply and a child object. The child object is without children.

   .. py:staticmethod:: Enable()

      Enables the notifier pool. If enabled, notifiers are automatically created
      if the object tree is being changed.

   .. py:staticmethod:: Enable()

      Disables the notifier pool.

   .. py:staticmethod:: SetEnabled(enable)

      Sets the state of the notifier pool.

   .. py:staticmethod:: IsEnabled()

      Returns the notification pool state. The default is TRUE.

   .. py:staticmethod:: SetCheckEnabled(enable)

      Enables/disables checking previous inserted notifiers
      when a new notifiers is about to be queued. When
      enabled, and OP_ADD and OP_UPDATE of the same object
      results in only one OP_ADD notifier.

   .. py:staticmethod:: IsCheckEnabled()

      Returns the current 'check' state.


   .. py:staticmethod:: GetMessage(allNotifier = True)

      :param allNotifier: Defines whether to return one message including all
                          notifiers or one message including one notifier.
      :rtype: A NotifierMessage object if there is one. If each notifier is
              being send by its own message, this method should be called
              until it returns None.

      Returns a message holding all notifications since the
      last call. All stored notifications will be removed from
      the notification pool.

   .. py:staticmethod:: Size()

      :rtype: Integer value.

      Returns the size of the notifier objects currently stored.

   .. py:staticmethod:: Clear()

      Clears all buffered notifiers.

   .. py:staticmethod:: Create(parentID, operation, object)

      :param parentID: The publicID of the parent object that is target of the operation.
      :param operation: The operation applied to the parent object.
      :param object: The object that is the operation's "operand".
      :rtype: The Notifier object.

      Creates a notifier object managed by the global notifier pool.
      If the notifier pool is disabled no notifier instance will
      be created and None is being returned.

   .. py:staticmethod:: Create(parent, operation, object)

      :param parent The parent object that is target of the operation.
      :param operation: The operation applied to the parent object.
      :param object: The object that is the operation's "operand".
      :rtype: The Notifier object.

      Creates a notifier object managed by the global notifier pool.
      If the notifier pool is disabled no notifier instance will
      be created and None is being returned.

   .. py:method:: apply()

      :rtype: A flag indicating success with True, False otherwise.

      Applies the notifier to the local object tree.

   .. py:method: setParentID(parentID)

      Setter of parentID.

   .. py:method: parentID()

      Getter of parentID.

   .. py:method: setOperation(operation)

      Setter of operation.

   .. py:method: operation()

      Getter of operation.

   .. py:method: setObject(object)

      Setter of object.

   .. py:method: object()

      Getter of object.



.. _api-python-datamodel-access:

Access
............................................................

.. py:class:: Access

   Inherits :ref:`Object <api-python-datamodel-object>`.

   This type describes an ArcLink access rule

   **Parents**:

   - ``routing`` -- :ref:`Routing <api-python-datamodel-routing>`

   **Attributes**:

   - ``networkCode`` -- string
   - ``stationCode`` -- string
   - ``locationCode`` -- string
   - ``streamCode`` -- string
   - ``user`` -- string
   - ``start`` -- seiscomp.core.Time
   - ``end`` -- seiscomp.core.Time (optional)

   **Methods**:

   .. py:staticmethod:: Cast(obj)

      :param obj: The object to be casted.
      :rtype: An object of type Access if the cast was successful,
              None otherwise.

      Cast an arbitrary object to Access if the internal wrapped
      representation is an Access object. The cast is important if
      instances of type :ref:`Object <api-python-datamodel-object>`
      are passed to methods which need access to the real type.



   .. py:method:: equal(other)

      :param other: Another object of type Access to compare this
                    instance to
      :rtype: A Boolean value indicating True if both objects are equal or
              False otherwise.

      Compares two objects without its child objects. Both objects are compared
      by value.

   .. py:method:: index()

      :rtype: The object's index of type AccessIndex.

       Returns the objects index which is also used for the database as unique
       constraint.

   .. py:method:: equalIndex(lhs)

      :param lhs: :ref:`Access <api-python-datamodel-access>`
      :rtype: A Boolean value indicating True if both indexes are equal or
              False otherwise.

   .. py:method:: setNetworkCode(networkCode)

      :param networkCode: string

      Network code

   .. py:method:: networkCode()

      :rtype: string

   .. py:method:: setStationCode(stationCode)

      :param stationCode: string

      Station code \(empty for any station\)

   .. py:method:: stationCode()

      :rtype: string

   .. py:method:: setLocationCode(locationCode)

      :param locationCode: string

      Location code \(empty for any location\)

   .. py:method:: locationCode()

      :rtype: string

   .. py:method:: setStreamCode(streamCode)

      :param streamCode: string

      Stream \(Channel\) code \(empty for any stream\)

   .. py:method:: streamCode()

      :rtype: string

   .. py:method:: setUser(user)

      :param user: string

      Username \(e\-mail\) or part of it \(must match the end\)

   .. py:method:: user()

      :rtype: string

   .. py:method:: setStart(start)

      :param start: seiscomp.core.Time

      Start of validity

   .. py:method:: start()

      :rtype: seiscomp.core.Time

   .. py:method:: setEnd(end)

      :param end: seiscomp.core.Time

      End of validity

   .. py:method:: end()

      :rtype: seiscomp.core.Time

      .. note::

         As this attribute is optional, this method throws a ValueError if
         the value of the attribute is not set.

   .. py:method:: routing()

      :rtype: Routing

      Returns the parent Routing if available. Returns None
      if the parent is not a Routing. This is a convenience wrapper
      for parent().

   .. py:method:: assign(other)

      This method implements the :ref:`Object <api-python-datamodel-object>` interface.

   .. py:method:: attachTo(parent)

      This method implements the :ref:`Object <api-python-datamodel-object>` interface.

   .. py:method:: detachFrom(parent)

      This method implements the :ref:`Object <api-python-datamodel-object>` interface.

   .. py:method:: detach()

      This method implements the :ref:`Object <api-python-datamodel-object>` interface.

   .. py:method:: clone()

      :rtype: A cloned Access.

      Returns a new instance that is a clone of the current instance. Child
      objects are being ignored.


   .. py:method:: accept(visitor)

      :param visitor: A visitor.

      This method implements the :ref:`PublicObject <api-python-datamodel-publicobject>` interface.

.. _api-python-datamodel-amplitude:

Amplitude
............................................................

.. py:class:: Amplitude

   Inherits :ref:`PublicObject <api-python-datamodel-publicobject>`.

   This class represents a quantification of the waveform anomaly, usually
   a single amplitude measurement or a measurement of the visible signal
   duration for duration magnitudes.

   **Parents**:

   - ``eventParameters`` -- :ref:`EventParameters <api-python-datamodel-eventparameters>`

   **Children**:

   - ``comment`` -- :ref:`Comment <api-python-datamodel-comment>`

   **Attributes**:

   - ``publicID``: string
   - ``type`` -- string
   - ``amplitude`` -- :ref:`RealQuantity <api-python-datamodel-realquantity>` (optional)
   - ``timeWindow`` -- :ref:`TimeWindow <api-python-datamodel-timewindow>` (optional)
   - ``period`` -- :ref:`RealQuantity <api-python-datamodel-realquantity>` (optional)
   - ``snr`` -- float (optional)
   - ``unit`` -- string
   - ``pickID`` -- string
   - ``waveformID`` -- :ref:`WaveformStreamID <api-python-datamodel-waveformstreamid>` (optional)
   - ``filterID`` -- string
   - ``methodID`` -- string
   - ``scalingTime`` -- :ref:`TimeQuantity <api-python-datamodel-timequantity>` (optional)
   - ``magnitudeHint`` -- string
   - ``evaluationMode`` -- :ref:`EvaluationMode <api-python-datamodel-evaluationmode>` (optional)
   - ``creationInfo`` -- :ref:`CreationInfo <api-python-datamodel-creationinfo>` (optional)

   **Referenced by**:

   - :func:`AmplitudeReference.amplitudeID`
   - :func:`StationMagnitude.amplitudeID`

   **Methods**:

   .. py:staticmethod:: Cast(obj)

      :param obj: The object to be casted.
      :rtype: An object of type Amplitude if the cast was successful,
              None otherwise.

      Cast an arbitrary object to Amplitude if the internal wrapped
      representation is an Amplitude object. The cast is important if
      instances of type :ref:`Object <api-python-datamodel-object>`
      are passed to methods which need access to the real type.



   .. py:staticmethod:: Create()

      :rtype: A new object of type Amplitude.

      Creates and registers (if enabled) a Amplitude instance. The
      publicID is auto-generated.

   .. py:staticmethod:: Create(publicID)

      :rtype: A new object of type Amplitude.

      Creates and registers (if enabled) a Amplitude instance with
      passed publicID.

   .. py:method:: equal(other)

      :param other: Another object of type Amplitude to compare this
                    instance to
      :rtype: A Boolean value indicating True if both objects are equal or
              False otherwise.

      Compares two objects without its child objects. Both objects are compared
      by value.

   .. py:method:: setType(type)

      :param type: string

      String that describes the type of amplitude using the nomenclature
      from Storchak et al. \(2003\). Possible values include unspecified
      amplitude reading \(A\), amplitude reading for local magnitude \(ML\),
      amplitude reading for body wave magnitude \(MB\), amplitude reading
      for surface wave magnitude \(MS\), and time of visible end of record
      for duration magnitude \(MD\). It has a maximum length of 16 characters.

   .. py:method:: type()

      :rtype: string

   .. py:method:: setAmplitude(amplitude)

      :param amplitude: :ref:`RealQuantity <api-python-datamodel-realquantity>`

      Measured amplitude value for the given waveformID. Note that this
      attribute can describe different physical quantities, depending on
      the type of the amplitude. These can be, e.g., displacement, velocity,
      or a period. If the only amplitude information is a period, it has
      to specified here, not in the period attribute. The latter can be used
      if the amplitude measurement contains information on, e.g.,
      displacement and an additional period. Since the physical quantity
      described by this attribute is not fixed, the unit of measurement
      cannot be defined in advance. However, the quantity has to be
      specified in SI base units. The enumeration given in attribute unit
      provides the most likely units that could be needed here.
      For clarity, using the optional unit attribute is highly encouraged.

   .. py:method:: amplitude()

      :rtype: :ref:`RealQuantity <api-python-datamodel-realquantity>`

      .. note::

         As this attribute is optional, this method throws a ValueError if
         the value of the attribute is not set.

   .. py:method:: setTimeWindow(timeWindow)

      :param timeWindow: :ref:`TimeWindow <api-python-datamodel-timewindow>`

      Description of the time window used for amplitude measurement.
      Recommended for duration magnitudes.

   .. py:method:: timeWindow()

      :rtype: :ref:`TimeWindow <api-python-datamodel-timewindow>`

      .. note::

         As this attribute is optional, this method throws a ValueError if
         the value of the attribute is not set.

   .. py:method:: setPeriod(period)

      :param period: :ref:`RealQuantity <api-python-datamodel-realquantity>`

      Dominant period in the timeWindow in case of amplitude measurements.
      Not used for duration magnitude. The unit is seconds.

   .. py:method:: period()

      :rtype: :ref:`RealQuantity <api-python-datamodel-realquantity>`

      .. note::

         As this attribute is optional, this method throws a ValueError if
         the value of the attribute is not set.

   .. py:method:: setSnr(snr)

      :param snr: float

      Signal\-to\-noise ratio of the spectrogram at the location the amplitude was
      measured.

   .. py:method:: snr()

      :rtype: float

      .. note::

         As this attribute is optional, this method throws a ValueError if
         the value of the attribute is not set.

   .. py:method:: setUnit(unit)

      :param unit: string

      This attribute provides the most likely measurement units for the
      physical quantity described in the amplitude attribute.
      Possible values are specified as combinations of SI base units.

   .. py:method:: unit()

      :rtype: string

   .. py:method:: setPickID(pickID)

      :param pickID: string

      Refers to the publicID of an associated Pick object.

   .. py:method:: pickID()

      :rtype: string

   .. py:method:: setWaveformID(waveformID)

      :param waveformID: :ref:`WaveformStreamID <api-python-datamodel-waveformstreamid>`

      Identifies the waveform stream on which the amplitude was measured.

   .. py:method:: waveformID()

      :rtype: :ref:`WaveformStreamID <api-python-datamodel-waveformstreamid>`

      .. note::

         As this attribute is optional, this method throws a ValueError if
         the value of the attribute is not set.

   .. py:method:: setFilterID(filterID)

      :param filterID: string

      Identifies the filter or filter setup used for filtering the waveform stream
      referenced by waveformID.

   .. py:method:: filterID()

      :rtype: string

   .. py:method:: setMethodID(methodID)

      :param methodID: string

   .. py:method:: methodID()

      :rtype: string

   .. py:method:: setScalingTime(scalingTime)

      :param scalingTime: :ref:`TimeQuantity <api-python-datamodel-timequantity>`

      Scaling time for amplitude measurement.

   .. py:method:: scalingTime()

      :rtype: :ref:`TimeQuantity <api-python-datamodel-timequantity>`

      .. note::

         As this attribute is optional, this method throws a ValueError if
         the value of the attribute is not set.

   .. py:method:: setMagnitudeHint(magnitudeHint)

      :param magnitudeHint: string

      Type of magnitude the amplitude measurement is used for. For valid
      values see class Magnitude. String value with a maximum length of
      16 characters.

   .. py:method:: magnitudeHint()

      :rtype: string

   .. py:method:: setEvaluationMode(evaluationMode)

      :param evaluationMode: EvaluationMode

      Evaluation mode of Amplitude.

   .. py:method:: evaluationMode()

      :rtype: EvaluationMode

      .. note::

         As this attribute is optional, this method throws a ValueError if
         the value of the attribute is not set.

   .. py:method:: setCreationInfo(creationInfo)

      :param creationInfo: :ref:`CreationInfo <api-python-datamodel-creationinfo>`

      CreationInfo for the Amplitude object.

   .. py:method:: creationInfo()

      :rtype: :ref:`CreationInfo <api-python-datamodel-creationinfo>`

      .. note::

         As this attribute is optional, this method throws a ValueError if
         the value of the attribute is not set.

   .. py:method:: add(comment)

      :param comment: Object of type :ref:`Comment <api-python-datamodel-comment>`
      :rtype: A Boolean value indicating success with True, False otherwise.

      Adds a Comment object to Amplitude. The object is not
      copied but managed by this instance. Any change to the passed object
      will also change the child.

   .. py:method:: remove(comment)

      :param comment: Object of type :ref:`Comment <api-python-datamodel-comment>`
      :rtype: A Boolean value indicating success with True, False otherwise.

      Removes a previously added Comment object from Amplitude.

   .. py:method:: removeComment(idx)

      :param idx: An integer index of the object to be removed.
      :rtype: A Boolean value indicating success with True, False otherwise.

   .. py:method:: removeComment(commentIndex);

      :param commentIndex: The index of the object to be removed of type CommentIndex.
      :rtype: A Boolean value indicating success with True, False otherwise.

   .. py:method:: commentCount()

      :rtype: integer value indicating the number of child objects.

      Returns the number of Comment child objects.

   .. py:method:: comment(idx)

      :param idx: An integer index of the object to be returned.
      :rtype: Object of type :ref:`Comment <api-python-datamodel-comment>`.

      Returns the Comment at index idx.

   .. py:method:: comment(commentIndex)

      :param commentIndex: The index of the object to be removed of type CommentIndex.
      :rtype: Object of type :ref:`Comment <api-python-datamodel-comment>`.

      Returns the Comment at given index. The indexes of all child objects
      are compared by value which makes this function slower than the direct
      integer index look-up.

   .. py:method:: eventParameters()

      :rtype: EventParameters

      Returns the parent EventParameters if available. Returns None
      if the parent is not a EventParameters. This is a convenience wrapper
      for parent().

   .. py:method:: assign(other)

      This method implements the :ref:`Object <api-python-datamodel-object>` interface.

   .. py:method:: attachTo(parent)

      This method implements the :ref:`Object <api-python-datamodel-object>` interface.

   .. py:method:: detachFrom(parent)

      This method implements the :ref:`Object <api-python-datamodel-object>` interface.

   .. py:method:: detach()

      This method implements the :ref:`Object <api-python-datamodel-object>` interface.

   .. py:method:: clone()

      :rtype: A cloned Amplitude.

      Returns a new instance that is a clone of the current instance. Child
      objects are being ignored.


   .. py:method:: updateChild(ref)

      :param ref: A child object derived from class Object.
      :rtype: A Boolean flag indicating success with True, False otherwise

      This method takes the passed reference object and searches for a child
      with the same publicID (if derived from :ref:`PublicObject <api-python-datamodel-publicobject>`)
      or the same index (if derived from :ref:`Object <api-python-datamodel-object>`).
      The the child was found the reference objects attributes are copied to
      the child object. Children of child are being ignored during this operation.
      This method implements the :ref:`PublicObject <api-python-datamodel-publicobject>` interface.


   .. py:method:: accept(visitor)

      :param visitor: A visitor.

      This method implements the :ref:`PublicObject <api-python-datamodel-publicobject>` interface.

.. _api-python-datamodel-amplitudereference:

AmplitudeReference
............................................................

.. py:class:: AmplitudeReference

   Inherits :ref:`Object <api-python-datamodel-object>`.


   **Parents**:

   - ``reading`` -- :ref:`Reading <api-python-datamodel-reading>`

   **Attributes**:

   - ``amplitudeID`` -- string

   **Methods**:

   .. py:staticmethod:: Cast(obj)

      :param obj: The object to be casted.
      :rtype: An object of type AmplitudeReference if the cast was successful,
              None otherwise.

      Cast an arbitrary object to AmplitudeReference if the internal wrapped
      representation is an AmplitudeReference object. The cast is important if
      instances of type :ref:`Object <api-python-datamodel-object>`
      are passed to methods which need access to the real type.



   .. py:method:: equal(other)

      :param other: Another object of type AmplitudeReference to compare this
                    instance to
      :rtype: A Boolean value indicating True if both objects are equal or
              False otherwise.

      Compares two objects without its child objects. Both objects are compared
      by value.

   .. py:method:: index()

      :rtype: The object's index of type AmplitudeReferenceIndex.

       Returns the objects index which is also used for the database as unique
       constraint.

   .. py:method:: equalIndex(lhs)

      :param lhs: :ref:`AmplitudeReference <api-python-datamodel-amplitudereference>`
      :rtype: A Boolean value indicating True if both indexes are equal or
              False otherwise.

   .. py:method:: setAmplitudeID(amplitudeID)

      :param amplitudeID: string

   .. py:method:: amplitudeID()

      :rtype: string

   .. py:method:: reading()

      :rtype: Reading

      Returns the parent Reading if available. Returns None
      if the parent is not a Reading. This is a convenience wrapper
      for parent().

   .. py:method:: assign(other)

      This method implements the :ref:`Object <api-python-datamodel-object>` interface.

   .. py:method:: attachTo(parent)

      This method implements the :ref:`Object <api-python-datamodel-object>` interface.

   .. py:method:: detachFrom(parent)

      This method implements the :ref:`Object <api-python-datamodel-object>` interface.

   .. py:method:: detach()

      This method implements the :ref:`Object <api-python-datamodel-object>` interface.

   .. py:method:: clone()

      :rtype: A cloned AmplitudeReference.

      Returns a new instance that is a clone of the current instance. Child
      objects are being ignored.


   .. py:method:: accept(visitor)

      :param visitor: A visitor.

      This method implements the :ref:`PublicObject <api-python-datamodel-publicobject>` interface.

.. _api-python-datamodel-arclinklog:

ArclinkLog
............................................................

.. py:class:: ArclinkLog

   Inherits :ref:`PublicObject <api-python-datamodel-publicobject>`.


   **Children**:

   - ``arclinkRequest`` -- :ref:`ArclinkRequest <api-python-datamodel-arclinkrequest>`
   - ``arclinkUser`` -- :ref:`ArclinkUser <api-python-datamodel-arclinkuser>`

   **Attributes**:

   - ``publicID``: string

   **Methods**:

   .. py:staticmethod:: Cast(obj)

      :param obj: The object to be casted.
      :rtype: An object of type ArclinkLog if the cast was successful,
              None otherwise.

      Cast an arbitrary object to ArclinkLog if the internal wrapped
      representation is an ArclinkLog object. The cast is important if
      instances of type :ref:`Object <api-python-datamodel-object>`
      are passed to methods which need access to the real type.



   .. py:method:: equal(other)

      :param other: Another object of type ArclinkLog to compare this
                    instance to
      :rtype: A Boolean value indicating True if both objects are equal or
              False otherwise.

      Compares two objects without its child objects. Both objects are compared
      by value.

   .. py:method:: add(arclinkRequest)

      :param arclinkRequest: Object of type :ref:`ArclinkRequest <api-python-datamodel-arclinkrequest>`
      :rtype: A Boolean value indicating success with True, False otherwise.

      Adds a ArclinkRequest object to ArclinkLog. The object is not
      copied but managed by this instance. Any change to the passed object
      will also change the child.

   .. py:method:: add(arclinkUser)

      :param arclinkUser: Object of type :ref:`ArclinkUser <api-python-datamodel-arclinkuser>`
      :rtype: A Boolean value indicating success with True, False otherwise.

      Adds a ArclinkUser object to ArclinkLog. The object is not
      copied but managed by this instance. Any change to the passed object
      will also change the child.

   .. py:method:: remove(arclinkRequest)

      :param arclinkRequest: Object of type :ref:`ArclinkRequest <api-python-datamodel-arclinkrequest>`
      :rtype: A Boolean value indicating success with True, False otherwise.

      Removes a previously added ArclinkRequest object from ArclinkLog.

   .. py:method:: remove(arclinkUser)

      :param arclinkUser: Object of type :ref:`ArclinkUser <api-python-datamodel-arclinkuser>`
      :rtype: A Boolean value indicating success with True, False otherwise.

      Removes a previously added ArclinkUser object from ArclinkLog.

   .. py:method:: removeArclinkRequest(idx)

      :param idx: An integer index of the object to be removed.
      :rtype: A Boolean value indicating success with True, False otherwise.

   .. py:method:: removeArclinkRequest(arclinkRequestIndex);

      :param arclinkRequestIndex: The index of the object to be removed of type ArclinkRequestIndex.
      :rtype: A Boolean value indicating success with True, False otherwise.

   .. py:method:: removeArclinkUser(idx)

      :param idx: An integer index of the object to be removed.
      :rtype: A Boolean value indicating success with True, False otherwise.

   .. py:method:: removeArclinkUser(arclinkUserIndex);

      :param arclinkUserIndex: The index of the object to be removed of type ArclinkUserIndex.
      :rtype: A Boolean value indicating success with True, False otherwise.

   .. py:method:: arclinkRequestCount()

      :rtype: integer value indicating the number of child objects.

      Returns the number of ArclinkRequest child objects.

   .. py:method:: arclinkUserCount()

      :rtype: integer value indicating the number of child objects.

      Returns the number of ArclinkUser child objects.

   .. py:method:: arclinkRequest(idx)

      :param idx: An integer index of the object to be returned.
      :rtype: Object of type :ref:`ArclinkRequest <api-python-datamodel-arclinkrequest>`.

      Returns the ArclinkRequest at index idx.

   .. py:method:: arclinkRequest(arclinkRequestIndex)

      :param arclinkRequestIndex: The index of the object to be removed of type ArclinkRequestIndex.
      :rtype: Object of type :ref:`ArclinkRequest <api-python-datamodel-arclinkrequest>`.

      Returns the ArclinkRequest at given index. The indexes of all child objects
      are compared by value which makes this function slower than the direct
      integer index look-up.

   .. py:method:: arclinkUser(idx)

      :param idx: An integer index of the object to be returned.
      :rtype: Object of type :ref:`ArclinkUser <api-python-datamodel-arclinkuser>`.

      Returns the ArclinkUser at index idx.

   .. py:method:: arclinkUser(arclinkUserIndex)

      :param arclinkUserIndex: The index of the object to be removed of type ArclinkUserIndex.
      :rtype: Object of type :ref:`ArclinkUser <api-python-datamodel-arclinkuser>`.

      Returns the ArclinkUser at given index. The indexes of all child objects
      are compared by value which makes this function slower than the direct
      integer index look-up.

   .. py:method:: findArclinkRequest(publicID)

      :param publicID: The publicID of the object to find.
      :rtype: Object of type :ref:`ArclinkRequest <api-python-datamodel-arclinkrequest>`.

      Returns the child object with a certain publicID, None otherwise.

   .. py:method:: findArclinkUser(publicID)

      :param publicID: The publicID of the object to find.
      :rtype: Object of type :ref:`ArclinkUser <api-python-datamodel-arclinkuser>`.

      Returns the child object with a certain publicID, None otherwise.

   .. py:method:: assign(other)

      This method implements the :ref:`Object <api-python-datamodel-object>` interface.

   .. py:method:: attachTo(parent)

      This method implements the :ref:`Object <api-python-datamodel-object>` interface.

   .. py:method:: detachFrom(parent)

      This method implements the :ref:`Object <api-python-datamodel-object>` interface.

   .. py:method:: detach()

      This method implements the :ref:`Object <api-python-datamodel-object>` interface.

   .. py:method:: clone()

      :rtype: A cloned ArclinkLog.

      Returns a new instance that is a clone of the current instance. Child
      objects are being ignored.


   .. py:method:: updateChild(ref)

      :param ref: A child object derived from class Object.
      :rtype: A Boolean flag indicating success with True, False otherwise

      This method takes the passed reference object and searches for a child
      with the same publicID (if derived from :ref:`PublicObject <api-python-datamodel-publicobject>`)
      or the same index (if derived from :ref:`Object <api-python-datamodel-object>`).
      The the child was found the reference objects attributes are copied to
      the child object. Children of child are being ignored during this operation.
      This method implements the :ref:`PublicObject <api-python-datamodel-publicobject>` interface.


   .. py:method:: accept(visitor)

      :param visitor: A visitor.

      This method implements the :ref:`PublicObject <api-python-datamodel-publicobject>` interface.

.. _api-python-datamodel-arclinkrequest:

ArclinkRequest
............................................................

.. py:class:: ArclinkRequest

   Inherits :ref:`PublicObject <api-python-datamodel-publicobject>`.


   **Parents**:

   - ``arclinkLog`` -- :ref:`ArclinkLog <api-python-datamodel-arclinklog>`

   **Children**:

   - ``arclinkStatusLine`` -- :ref:`ArclinkStatusLine <api-python-datamodel-arclinkstatusline>`
   - ``arclinkRequestLine`` -- :ref:`ArclinkRequestLine <api-python-datamodel-arclinkrequestline>`

   **Attributes**:

   - ``publicID``: string
   - ``requestID`` -- string
   - ``userID`` -- string
   - ``userIP`` -- string
   - ``clientID`` -- string
   - ``clientIP`` -- string
   - ``type`` -- string
   - ``created`` -- seiscomp.core.Time
   - ``status`` -- string
   - ``message`` -- string
   - ``label`` -- string
   - ``header`` -- string
   - ``summary`` -- :ref:`ArclinkRequestSummary <api-python-datamodel-arclinkrequestsummary>` (optional)

   **Methods**:

   .. py:staticmethod:: Cast(obj)

      :param obj: The object to be casted.
      :rtype: An object of type ArclinkRequest if the cast was successful,
              None otherwise.

      Cast an arbitrary object to ArclinkRequest if the internal wrapped
      representation is an ArclinkRequest object. The cast is important if
      instances of type :ref:`Object <api-python-datamodel-object>`
      are passed to methods which need access to the real type.



   .. py:staticmethod:: Create()

      :rtype: A new object of type ArclinkRequest.

      Creates and registers (if enabled) a ArclinkRequest instance. The
      publicID is auto-generated.

   .. py:staticmethod:: Create(publicID)

      :rtype: A new object of type ArclinkRequest.

      Creates and registers (if enabled) a ArclinkRequest instance with
      passed publicID.

   .. py:method:: equal(other)

      :param other: Another object of type ArclinkRequest to compare this
                    instance to
      :rtype: A Boolean value indicating True if both objects are equal or
              False otherwise.

      Compares two objects without its child objects. Both objects are compared
      by value.

   .. py:method:: index()

      :rtype: The object's index of type ArclinkRequestIndex.

       Returns the objects index which is also used for the database as unique
       constraint.

   .. py:method:: equalIndex(lhs)

      :param lhs: :ref:`ArclinkRequest <api-python-datamodel-arclinkrequest>`
      :rtype: A Boolean value indicating True if both indexes are equal or
              False otherwise.

   .. py:method:: setRequestID(requestID)

      :param requestID: string

   .. py:method:: requestID()

      :rtype: string

   .. py:method:: setUserID(userID)

      :param userID: string

   .. py:method:: userID()

      :rtype: string

   .. py:method:: setUserIP(userIP)

      :param userIP: string

   .. py:method:: userIP()

      :rtype: string

   .. py:method:: setClientID(clientID)

      :param clientID: string

   .. py:method:: clientID()

      :rtype: string

   .. py:method:: setClientIP(clientIP)

      :param clientIP: string

   .. py:method:: clientIP()

      :rtype: string

   .. py:method:: setType(type)

      :param type: string

   .. py:method:: type()

      :rtype: string

   .. py:method:: setCreated(created)

      :param created: seiscomp.core.Time

   .. py:method:: created()

      :rtype: seiscomp.core.Time

   .. py:method:: setStatus(status)

      :param status: string

   .. py:method:: status()

      :rtype: string

   .. py:method:: setMessage(message)

      :param message: string

   .. py:method:: message()

      :rtype: string

   .. py:method:: setLabel(label)

      :param label: string

   .. py:method:: label()

      :rtype: string

   .. py:method:: setHeader(header)

      :param header: string

   .. py:method:: header()

      :rtype: string

   .. py:method:: setSummary(summary)

      :param summary: :ref:`ArclinkRequestSummary <api-python-datamodel-arclinkrequestsummary>`

   .. py:method:: summary()

      :rtype: :ref:`ArclinkRequestSummary <api-python-datamodel-arclinkrequestsummary>`

      .. note::

         As this attribute is optional, this method throws a ValueError if
         the value of the attribute is not set.

   .. py:method:: add(arclinkStatusLine)

      :param arclinkStatusLine: Object of type :ref:`ArclinkStatusLine <api-python-datamodel-arclinkstatusline>`
      :rtype: A Boolean value indicating success with True, False otherwise.

      Adds a ArclinkStatusLine object to ArclinkRequest. The object is not
      copied but managed by this instance. Any change to the passed object
      will also change the child.

   .. py:method:: add(arclinkRequestLine)

      :param arclinkRequestLine: Object of type :ref:`ArclinkRequestLine <api-python-datamodel-arclinkrequestline>`
      :rtype: A Boolean value indicating success with True, False otherwise.

      Adds a ArclinkRequestLine object to ArclinkRequest. The object is not
      copied but managed by this instance. Any change to the passed object
      will also change the child.

   .. py:method:: remove(arclinkStatusLine)

      :param arclinkStatusLine: Object of type :ref:`ArclinkStatusLine <api-python-datamodel-arclinkstatusline>`
      :rtype: A Boolean value indicating success with True, False otherwise.

      Removes a previously added ArclinkStatusLine object from ArclinkRequest.

   .. py:method:: remove(arclinkRequestLine)

      :param arclinkRequestLine: Object of type :ref:`ArclinkRequestLine <api-python-datamodel-arclinkrequestline>`
      :rtype: A Boolean value indicating success with True, False otherwise.

      Removes a previously added ArclinkRequestLine object from ArclinkRequest.

   .. py:method:: removeArclinkStatusLine(idx)

      :param idx: An integer index of the object to be removed.
      :rtype: A Boolean value indicating success with True, False otherwise.

   .. py:method:: removeArclinkStatusLine(arclinkStatusLineIndex);

      :param arclinkStatusLineIndex: The index of the object to be removed of type ArclinkStatusLineIndex.
      :rtype: A Boolean value indicating success with True, False otherwise.

   .. py:method:: removeArclinkRequestLine(idx)

      :param idx: An integer index of the object to be removed.
      :rtype: A Boolean value indicating success with True, False otherwise.

   .. py:method:: removeArclinkRequestLine(arclinkRequestLineIndex);

      :param arclinkRequestLineIndex: The index of the object to be removed of type ArclinkRequestLineIndex.
      :rtype: A Boolean value indicating success with True, False otherwise.

   .. py:method:: arclinkStatusLineCount()

      :rtype: integer value indicating the number of child objects.

      Returns the number of ArclinkStatusLine child objects.

   .. py:method:: arclinkRequestLineCount()

      :rtype: integer value indicating the number of child objects.

      Returns the number of ArclinkRequestLine child objects.

   .. py:method:: arclinkStatusLine(idx)

      :param idx: An integer index of the object to be returned.
      :rtype: Object of type :ref:`ArclinkStatusLine <api-python-datamodel-arclinkstatusline>`.

      Returns the ArclinkStatusLine at index idx.

   .. py:method:: arclinkStatusLine(arclinkStatusLineIndex)

      :param arclinkStatusLineIndex: The index of the object to be removed of type ArclinkStatusLineIndex.
      :rtype: Object of type :ref:`ArclinkStatusLine <api-python-datamodel-arclinkstatusline>`.

      Returns the ArclinkStatusLine at given index. The indexes of all child objects
      are compared by value which makes this function slower than the direct
      integer index look-up.

   .. py:method:: arclinkRequestLine(idx)

      :param idx: An integer index of the object to be returned.
      :rtype: Object of type :ref:`ArclinkRequestLine <api-python-datamodel-arclinkrequestline>`.

      Returns the ArclinkRequestLine at index idx.

   .. py:method:: arclinkRequestLine(arclinkRequestLineIndex)

      :param arclinkRequestLineIndex: The index of the object to be removed of type ArclinkRequestLineIndex.
      :rtype: Object of type :ref:`ArclinkRequestLine <api-python-datamodel-arclinkrequestline>`.

      Returns the ArclinkRequestLine at given index. The indexes of all child objects
      are compared by value which makes this function slower than the direct
      integer index look-up.

   .. py:method:: arclinkLog()

      :rtype: ArclinkLog

      Returns the parent ArclinkLog if available. Returns None
      if the parent is not a ArclinkLog. This is a convenience wrapper
      for parent().

   .. py:method:: assign(other)

      This method implements the :ref:`Object <api-python-datamodel-object>` interface.

   .. py:method:: attachTo(parent)

      This method implements the :ref:`Object <api-python-datamodel-object>` interface.

   .. py:method:: detachFrom(parent)

      This method implements the :ref:`Object <api-python-datamodel-object>` interface.

   .. py:method:: detach()

      This method implements the :ref:`Object <api-python-datamodel-object>` interface.

   .. py:method:: clone()

      :rtype: A cloned ArclinkRequest.

      Returns a new instance that is a clone of the current instance. Child
      objects are being ignored.


   .. py:method:: updateChild(ref)

      :param ref: A child object derived from class Object.
      :rtype: A Boolean flag indicating success with True, False otherwise

      This method takes the passed reference object and searches for a child
      with the same publicID (if derived from :ref:`PublicObject <api-python-datamodel-publicobject>`)
      or the same index (if derived from :ref:`Object <api-python-datamodel-object>`).
      The the child was found the reference objects attributes are copied to
      the child object. Children of child are being ignored during this operation.
      This method implements the :ref:`PublicObject <api-python-datamodel-publicobject>` interface.


   .. py:method:: accept(visitor)

      :param visitor: A visitor.

      This method implements the :ref:`PublicObject <api-python-datamodel-publicobject>` interface.

.. _api-python-datamodel-arclinkrequestline:

ArclinkRequestLine
............................................................

.. py:class:: ArclinkRequestLine

   Inherits :ref:`Object <api-python-datamodel-object>`.


   **Parents**:

   - ``arclinkRequest`` -- :ref:`ArclinkRequest <api-python-datamodel-arclinkrequest>`

   **Attributes**:

   - ``start`` -- seiscomp.core.Time
   - ``end`` -- seiscomp.core.Time
   - ``streamID`` -- :ref:`WaveformStreamID <api-python-datamodel-waveformstreamid>`
   - ``restricted`` -- boolean (optional)
   - ``shared`` -- boolean (optional)
   - ``netClass`` -- string
   - ``constraints`` -- string
   - ``status`` -- :ref:`ArclinkStatusLine <api-python-datamodel-arclinkstatusline>`

   **Methods**:

   .. py:staticmethod:: Cast(obj)

      :param obj: The object to be casted.
      :rtype: An object of type ArclinkRequestLine if the cast was successful,
              None otherwise.

      Cast an arbitrary object to ArclinkRequestLine if the internal wrapped
      representation is an ArclinkRequestLine object. The cast is important if
      instances of type :ref:`Object <api-python-datamodel-object>`
      are passed to methods which need access to the real type.



   .. py:method:: equal(other)

      :param other: Another object of type ArclinkRequestLine to compare this
                    instance to
      :rtype: A Boolean value indicating True if both objects are equal or
              False otherwise.

      Compares two objects without its child objects. Both objects are compared
      by value.

   .. py:method:: index()

      :rtype: The object's index of type ArclinkRequestLineIndex.

       Returns the objects index which is also used for the database as unique
       constraint.

   .. py:method:: equalIndex(lhs)

      :param lhs: :ref:`ArclinkRequestLine <api-python-datamodel-arclinkrequestline>`
      :rtype: A Boolean value indicating True if both indexes are equal or
              False otherwise.

   .. py:method:: setStart(start)

      :param start: seiscomp.core.Time

   .. py:method:: start()

      :rtype: seiscomp.core.Time

   .. py:method:: setEnd(end)

      :param end: seiscomp.core.Time

   .. py:method:: end()

      :rtype: seiscomp.core.Time

   .. py:method:: setStreamID(streamID)

      :param streamID: :ref:`WaveformStreamID <api-python-datamodel-waveformstreamid>`

   .. py:method:: streamID()

      :rtype: :ref:`WaveformStreamID <api-python-datamodel-waveformstreamid>`

   .. py:method:: setRestricted(restricted)

      :param restricted: boolean

   .. py:method:: restricted()

      :rtype: boolean

      .. note::

         As this attribute is optional, this method throws a ValueError if
         the value of the attribute is not set.

   .. py:method:: setShared(shared)

      :param shared: boolean

   .. py:method:: shared()

      :rtype: boolean

      .. note::

         As this attribute is optional, this method throws a ValueError if
         the value of the attribute is not set.

   .. py:method:: setNetClass(netClass)

      :param netClass: string

   .. py:method:: netClass()

      :rtype: string

   .. py:method:: setConstraints(constraints)

      :param constraints: string

   .. py:method:: constraints()

      :rtype: string

   .. py:method:: setStatus(status)

      :param status: :ref:`ArclinkStatusLine <api-python-datamodel-arclinkstatusline>`

   .. py:method:: status()

      :rtype: :ref:`ArclinkStatusLine <api-python-datamodel-arclinkstatusline>`

   .. py:method:: arclinkRequest()

      :rtype: ArclinkRequest

      Returns the parent ArclinkRequest if available. Returns None
      if the parent is not a ArclinkRequest. This is a convenience wrapper
      for parent().

   .. py:method:: assign(other)

      This method implements the :ref:`Object <api-python-datamodel-object>` interface.

   .. py:method:: attachTo(parent)

      This method implements the :ref:`Object <api-python-datamodel-object>` interface.

   .. py:method:: detachFrom(parent)

      This method implements the :ref:`Object <api-python-datamodel-object>` interface.

   .. py:method:: detach()

      This method implements the :ref:`Object <api-python-datamodel-object>` interface.

   .. py:method:: clone()

      :rtype: A cloned ArclinkRequestLine.

      Returns a new instance that is a clone of the current instance. Child
      objects are being ignored.


   .. py:method:: accept(visitor)

      :param visitor: A visitor.

      This method implements the :ref:`PublicObject <api-python-datamodel-publicobject>` interface.

.. _api-python-datamodel-arclinkrequestsummary:

ArclinkRequestSummary
............................................................

.. py:class:: ArclinkRequestSummary

   Inherits :ref:`Object <api-python-datamodel-object>`.


   **Attributes**:

   - ``okLineCount`` -- int
   - ``totalLineCount`` -- int
   - ``averageTimeWindow`` -- int

   **Used by**:

   - :func:`ArclinkRequest.summary`

   **Methods**:

   .. py:staticmethod:: Cast(obj)

      :param obj: The object to be casted.
      :rtype: An object of type ArclinkRequestSummary if the cast was successful,
              None otherwise.

      Cast an arbitrary object to ArclinkRequestSummary if the internal wrapped
      representation is an ArclinkRequestSummary object. The cast is important if
      instances of type :ref:`Object <api-python-datamodel-object>`
      are passed to methods which need access to the real type.



   .. py:method:: equal(other)

      :param other: Another object of type ArclinkRequestSummary to compare this
                    instance to
      :rtype: A Boolean value indicating True if both objects are equal or
              False otherwise.

      Compares two objects without its child objects. Both objects are compared
      by value.

   .. py:method:: setOkLineCount(okLineCount)

      :param okLineCount: int

   .. py:method:: okLineCount()

      :rtype: int

   .. py:method:: setTotalLineCount(totalLineCount)

      :param totalLineCount: int

   .. py:method:: totalLineCount()

      :rtype: int

   .. py:method:: setAverageTimeWindow(averageTimeWindow)

      :param averageTimeWindow: int

   .. py:method:: averageTimeWindow()

      :rtype: int

.. _api-python-datamodel-arclinkstatusline:

ArclinkStatusLine
............................................................

.. py:class:: ArclinkStatusLine

   Inherits :ref:`Object <api-python-datamodel-object>`.


   **Parents**:

   - ``arclinkRequest`` -- :ref:`ArclinkRequest <api-python-datamodel-arclinkrequest>`

   **Attributes**:

   - ``type`` -- string
   - ``status`` -- string
   - ``size`` -- int (optional)
   - ``message`` -- string
   - ``volumeID`` -- string

   **Used by**:

   - :func:`ArclinkRequestLine.status`

   **Methods**:

   .. py:staticmethod:: Cast(obj)

      :param obj: The object to be casted.
      :rtype: An object of type ArclinkStatusLine if the cast was successful,
              None otherwise.

      Cast an arbitrary object to ArclinkStatusLine if the internal wrapped
      representation is an ArclinkStatusLine object. The cast is important if
      instances of type :ref:`Object <api-python-datamodel-object>`
      are passed to methods which need access to the real type.



   .. py:method:: equal(other)

      :param other: Another object of type ArclinkStatusLine to compare this
                    instance to
      :rtype: A Boolean value indicating True if both objects are equal or
              False otherwise.

      Compares two objects without its child objects. Both objects are compared
      by value.

   .. py:method:: index()

      :rtype: The object's index of type ArclinkStatusLineIndex.

       Returns the objects index which is also used for the database as unique
       constraint.

   .. py:method:: equalIndex(lhs)

      :param lhs: :ref:`ArclinkStatusLine <api-python-datamodel-arclinkstatusline>`
      :rtype: A Boolean value indicating True if both indexes are equal or
              False otherwise.

   .. py:method:: setType(type)

      :param type: string

   .. py:method:: type()

      :rtype: string

   .. py:method:: setStatus(status)

      :param status: string

   .. py:method:: status()

      :rtype: string

   .. py:method:: setSize(size)

      :param size: int

   .. py:method:: size()

      :rtype: int

      .. note::

         As this attribute is optional, this method throws a ValueError if
         the value of the attribute is not set.

   .. py:method:: setMessage(message)

      :param message: string

   .. py:method:: message()

      :rtype: string

   .. py:method:: setVolumeID(volumeID)

      :param volumeID: string

   .. py:method:: volumeID()

      :rtype: string

   .. py:method:: arclinkRequest()

      :rtype: ArclinkRequest

      Returns the parent ArclinkRequest if available. Returns None
      if the parent is not a ArclinkRequest. This is a convenience wrapper
      for parent().

   .. py:method:: assign(other)

      This method implements the :ref:`Object <api-python-datamodel-object>` interface.

   .. py:method:: attachTo(parent)

      This method implements the :ref:`Object <api-python-datamodel-object>` interface.

   .. py:method:: detachFrom(parent)

      This method implements the :ref:`Object <api-python-datamodel-object>` interface.

   .. py:method:: detach()

      This method implements the :ref:`Object <api-python-datamodel-object>` interface.

   .. py:method:: clone()

      :rtype: A cloned ArclinkStatusLine.

      Returns a new instance that is a clone of the current instance. Child
      objects are being ignored.


   .. py:method:: accept(visitor)

      :param visitor: A visitor.

      This method implements the :ref:`PublicObject <api-python-datamodel-publicobject>` interface.

.. _api-python-datamodel-arclinkuser:

ArclinkUser
............................................................

.. py:class:: ArclinkUser

   Inherits :ref:`PublicObject <api-python-datamodel-publicobject>`.


   **Parents**:

   - ``arclinkLog`` -- :ref:`ArclinkLog <api-python-datamodel-arclinklog>`

   **Attributes**:

   - ``publicID``: string
   - ``name`` -- string
   - ``email`` -- string
   - ``password`` -- string

   **Methods**:

   .. py:staticmethod:: Cast(obj)

      :param obj: The object to be casted.
      :rtype: An object of type ArclinkUser if the cast was successful,
              None otherwise.

      Cast an arbitrary object to ArclinkUser if the internal wrapped
      representation is an ArclinkUser object. The cast is important if
      instances of type :ref:`Object <api-python-datamodel-object>`
      are passed to methods which need access to the real type.



   .. py:staticmethod:: Create()

      :rtype: A new object of type ArclinkUser.

      Creates and registers (if enabled) a ArclinkUser instance. The
      publicID is auto-generated.

   .. py:staticmethod:: Create(publicID)

      :rtype: A new object of type ArclinkUser.

      Creates and registers (if enabled) a ArclinkUser instance with
      passed publicID.

   .. py:method:: equal(other)

      :param other: Another object of type ArclinkUser to compare this
                    instance to
      :rtype: A Boolean value indicating True if both objects are equal or
              False otherwise.

      Compares two objects without its child objects. Both objects are compared
      by value.

   .. py:method:: index()

      :rtype: The object's index of type ArclinkUserIndex.

       Returns the objects index which is also used for the database as unique
       constraint.

   .. py:method:: equalIndex(lhs)

      :param lhs: :ref:`ArclinkUser <api-python-datamodel-arclinkuser>`
      :rtype: A Boolean value indicating True if both indexes are equal or
              False otherwise.

   .. py:method:: setName(name)

      :param name: string

   .. py:method:: name()

      :rtype: string

   .. py:method:: setEmail(email)

      :param email: string

   .. py:method:: email()

      :rtype: string

   .. py:method:: setPassword(password)

      :param password: string

   .. py:method:: password()

      :rtype: string

   .. py:method:: arclinkLog()

      :rtype: ArclinkLog

      Returns the parent ArclinkLog if available. Returns None
      if the parent is not a ArclinkLog. This is a convenience wrapper
      for parent().

   .. py:method:: assign(other)

      This method implements the :ref:`Object <api-python-datamodel-object>` interface.

   .. py:method:: attachTo(parent)

      This method implements the :ref:`Object <api-python-datamodel-object>` interface.

   .. py:method:: detachFrom(parent)

      This method implements the :ref:`Object <api-python-datamodel-object>` interface.

   .. py:method:: detach()

      This method implements the :ref:`Object <api-python-datamodel-object>` interface.

   .. py:method:: clone()

      :rtype: A cloned ArclinkUser.

      Returns a new instance that is a clone of the current instance. Child
      objects are being ignored.


   .. py:method:: updateChild(ref)

      :param ref: A child object derived from class Object.
      :rtype: A Boolean flag indicating success with True, False otherwise

      This method takes the passed reference object and searches for a child
      with the same publicID (if derived from :ref:`PublicObject <api-python-datamodel-publicobject>`)
      or the same index (if derived from :ref:`Object <api-python-datamodel-object>`).
      The the child was found the reference objects attributes are copied to
      the child object. Children of child are being ignored during this operation.
      This method implements the :ref:`PublicObject <api-python-datamodel-publicobject>` interface.


   .. py:method:: accept(visitor)

      :param visitor: A visitor.

      This method implements the :ref:`PublicObject <api-python-datamodel-publicobject>` interface.

.. _api-python-datamodel-arrival:

Arrival
............................................................

.. py:class:: Arrival

   Inherits :ref:`Object <api-python-datamodel-object>`.

   Successful association of a pick with an origin qualifies this pick as
   an arrival. An arrival thus connects a pick with an origin and provides
   additional attributes that describe this relationship. Usually qualification
   of a pick as an arrival for a given origin is a hypothesis, which is
   based on assumptions about the type of arrival \(phase\) as well as
   observed and \(on the basis of an earth model\) computed arrival times,
   or the residual, respectively. Additional pick attributes like the
   horizontal slowness and backazimuth of the observed wave\-especially if
   derived from array data\-may further constrain the nature of the arrival.

   **Parents**:

   - ``origin`` -- :ref:`Origin <api-python-datamodel-origin>`

   **Attributes**:

   - ``pickID`` -- string
   - ``phase`` -- :ref:`Phase <api-python-datamodel-phase>`
   - ``timeCorrection`` -- float (optional)
   - ``azimuth`` -- float (optional)
   - ``distance`` -- float (optional)
   - ``takeOffAngle`` -- float (optional)
   - ``timeResidual`` -- float (optional)
   - ``horizontalSlownessResidual`` -- float (optional)
   - ``backazimuthResidual`` -- float (optional)
   - ``timeUsed`` -- boolean (optional)
   - ``horizontalSlownessUsed`` -- boolean (optional)
   - ``backazimuthUsed`` -- boolean (optional)
   - ``weight`` -- float (optional)
   - ``earthModelID`` -- string
   - ``preliminary`` -- boolean (optional)
   - ``creationInfo`` -- :ref:`CreationInfo <api-python-datamodel-creationinfo>` (optional)

   **Methods**:

   .. py:staticmethod:: Cast(obj)

      :param obj: The object to be casted.
      :rtype: An object of type Arrival if the cast was successful,
              None otherwise.

      Cast an arbitrary object to Arrival if the internal wrapped
      representation is an Arrival object. The cast is important if
      instances of type :ref:`Object <api-python-datamodel-object>`
      are passed to methods which need access to the real type.



   .. py:method:: equal(other)

      :param other: Another object of type Arrival to compare this
                    instance to
      :rtype: A Boolean value indicating True if both objects are equal or
              False otherwise.

      Compares two objects without its child objects. Both objects are compared
      by value.

   .. py:method:: index()

      :rtype: The object's index of type ArrivalIndex.

       Returns the objects index which is also used for the database as unique
       constraint.

   .. py:method:: equalIndex(lhs)

      :param lhs: :ref:`Arrival <api-python-datamodel-arrival>`
      :rtype: A Boolean value indicating True if both indexes are equal or
              False otherwise.

   .. py:method:: setPickID(pickID)

      :param pickID: string

      Refers to a publicID of a Pick.

   .. py:method:: pickID()

      :rtype: string

   .. py:method:: setPhase(phase)

      :param phase: :ref:`Phase <api-python-datamodel-phase>`

      Phase identification. For possible values, please refer to the description
      of the Phase type.

   .. py:method:: phase()

      :rtype: :ref:`Phase <api-python-datamodel-phase>`

   .. py:method:: setTimeCorrection(timeCorrection)

      :param timeCorrection: float

      Time correction value. Usually, a value characteristic for the station
      at which the pick was detected, sometimes also characteristic for the
      phase type or the slowness in seconds.

   .. py:method:: timeCorrection()

      :rtype: float

      .. note::

         As this attribute is optional, this method throws a ValueError if
         the value of the attribute is not set.

   .. py:method:: setAzimuth(azimuth)

      :param azimuth: float

      Azimuth of station as seen from the epicenter in degrees.

   .. py:method:: azimuth()

      :rtype: float

      .. note::

         As this attribute is optional, this method throws a ValueError if
         the value of the attribute is not set.

   .. py:method:: setDistance(distance)

      :param distance: float

      Epicentral distance in degrees.

   .. py:method:: distance()

      :rtype: float

      .. note::

         As this attribute is optional, this method throws a ValueError if
         the value of the attribute is not set.

   .. py:method:: setTakeOffAngle(takeOffAngle)

      :param takeOffAngle: float

      Angle of emerging ray at the source, measured against the downward
      normal direction in degrees.

   .. py:method:: takeOffAngle()

      :rtype: float

      .. note::

         As this attribute is optional, this method throws a ValueError if
         the value of the attribute is not set.

   .. py:method:: setTimeResidual(timeResidual)

      :param timeResidual: float

      Residual between observed and expected arrival time assuming proper
      phase identification and given the earthModelID of the Origin,
      taking into account the timeCorrection in seconds.

   .. py:method:: timeResidual()

      :rtype: float

      .. note::

         As this attribute is optional, this method throws a ValueError if
         the value of the attribute is not set.

   .. py:method:: setHorizontalSlownessResidual(horizontalSlownessResidual)

      :param horizontalSlownessResidual: float

      Residual of horizontal slowness and the expected slowness given the
      current origin \(refers to attribute horizontalSlowness of class Pick\)
      in s\/deg.

   .. py:method:: horizontalSlownessResidual()

      :rtype: float

      .. note::

         As this attribute is optional, this method throws a ValueError if
         the value of the attribute is not set.

   .. py:method:: setBackazimuthResidual(backazimuthResidual)

      :param backazimuthResidual: float

      Residual of backazimuth and the backazimuth computed for the current
      origin \(refers to attribute backazimuth of class Pick\) in degrees.

   .. py:method:: backazimuthResidual()

      :rtype: float

      .. note::

         As this attribute is optional, this method throws a ValueError if
         the value of the attribute is not set.

   .. py:method:: setTimeUsed(timeUsed)

      :param timeUsed: boolean

   .. py:method:: timeUsed()

      :rtype: boolean

      .. note::

         As this attribute is optional, this method throws a ValueError if
         the value of the attribute is not set.

   .. py:method:: setHorizontalSlownessUsed(horizontalSlownessUsed)

      :param horizontalSlownessUsed: boolean

      Weight of the horizontal slowness for computation of the associated Origin.
      Note that the sum of all weights is not required to be unity.

   .. py:method:: horizontalSlownessUsed()

      :rtype: boolean

      .. note::

         As this attribute is optional, this method throws a ValueError if
         the value of the attribute is not set.

   .. py:method:: setBackazimuthUsed(backazimuthUsed)

      :param backazimuthUsed: boolean

   .. py:method:: backazimuthUsed()

      :rtype: boolean

      .. note::

         As this attribute is optional, this method throws a ValueError if
         the value of the attribute is not set.

   .. py:method:: setWeight(weight)

      :param weight: float

      Weight of the arrival time for computation of the associated Origin.
      Note that the sum of all weights is not required to be unity.

   .. py:method:: weight()

      :rtype: float

      .. note::

         As this attribute is optional, this method throws a ValueError if
         the value of the attribute is not set.

   .. py:method:: setEarthModelID(earthModelID)

      :param earthModelID: string

      Earth model which is used for the association of Arrival to Pick and
      computation of the
      residuals.

   .. py:method:: earthModelID()

      :rtype: string

   .. py:method:: setPreliminary(preliminary)

      :param preliminary: boolean

      Indicates if the arrival is preliminary.

   .. py:method:: preliminary()

      :rtype: boolean

      .. note::

         As this attribute is optional, this method throws a ValueError if
         the value of the attribute is not set.

   .. py:method:: setCreationInfo(creationInfo)

      :param creationInfo: :ref:`CreationInfo <api-python-datamodel-creationinfo>`

      CreationInfo for the Arrival object.

   .. py:method:: creationInfo()

      :rtype: :ref:`CreationInfo <api-python-datamodel-creationinfo>`

      .. note::

         As this attribute is optional, this method throws a ValueError if
         the value of the attribute is not set.

   .. py:method:: origin()

      :rtype: Origin

      Returns the parent Origin if available. Returns None
      if the parent is not a Origin. This is a convenience wrapper
      for parent().

   .. py:method:: assign(other)

      This method implements the :ref:`Object <api-python-datamodel-object>` interface.

   .. py:method:: attachTo(parent)

      This method implements the :ref:`Object <api-python-datamodel-object>` interface.

   .. py:method:: detachFrom(parent)

      This method implements the :ref:`Object <api-python-datamodel-object>` interface.

   .. py:method:: detach()

      This method implements the :ref:`Object <api-python-datamodel-object>` interface.

   .. py:method:: clone()

      :rtype: A cloned Arrival.

      Returns a new instance that is a clone of the current instance. Child
      objects are being ignored.


   .. py:method:: accept(visitor)

      :param visitor: A visitor.

      This method implements the :ref:`PublicObject <api-python-datamodel-publicobject>` interface.

.. _api-python-datamodel-auxdevice:

AuxDevice
............................................................

.. py:class:: AuxDevice

   Inherits :ref:`PublicObject <api-python-datamodel-publicobject>`.

   This type describes an auxilliary device

   **Parents**:

   - ``inventory`` -- :ref:`Inventory <api-python-datamodel-inventory>`

   **Children**:

   - ``auxSource`` -- :ref:`AuxSource <api-python-datamodel-auxsource>`

   **Attributes**:

   - ``publicID``: string
   - ``name`` -- string
   - ``description`` -- string
   - ``model`` -- string
   - ``manufacturer`` -- string
   - ``remark`` -- :ref:`Blob <api-python-datamodel-blob>` (optional)

   **Referenced by**:

   - :func:`AuxStream.device`

   **Methods**:

   .. py:staticmethod:: Cast(obj)

      :param obj: The object to be casted.
      :rtype: An object of type AuxDevice if the cast was successful,
              None otherwise.

      Cast an arbitrary object to AuxDevice if the internal wrapped
      representation is an AuxDevice object. The cast is important if
      instances of type :ref:`Object <api-python-datamodel-object>`
      are passed to methods which need access to the real type.



   .. py:staticmethod:: Create()

      :rtype: A new object of type AuxDevice.

      Creates and registers (if enabled) a AuxDevice instance. The
      publicID is auto-generated.

   .. py:staticmethod:: Create(publicID)

      :rtype: A new object of type AuxDevice.

      Creates and registers (if enabled) a AuxDevice instance with
      passed publicID.

   .. py:method:: equal(other)

      :param other: Another object of type AuxDevice to compare this
                    instance to
      :rtype: A Boolean value indicating True if both objects are equal or
              False otherwise.

      Compares two objects without its child objects. Both objects are compared
      by value.

   .. py:method:: index()

      :rtype: The object's index of type AuxDeviceIndex.

       Returns the objects index which is also used for the database as unique
       constraint.

   .. py:method:: equalIndex(lhs)

      :param lhs: :ref:`AuxDevice <api-python-datamodel-auxdevice>`
      :rtype: A Boolean value indicating True if both indexes are equal or
              False otherwise.

   .. py:method:: setName(name)

      :param name: string

      Unique device name

   .. py:method:: name()

      :rtype: string

   .. py:method:: setDescription(description)

      :param description: string

      Device description

   .. py:method:: description()

      :rtype: string

   .. py:method:: setModel(model)

      :param model: string

      Device model

   .. py:method:: model()

      :rtype: string

   .. py:method:: setManufacturer(manufacturer)

      :param manufacturer: string

      Device manufacturer

   .. py:method:: manufacturer()

      :rtype: string

   .. py:method:: setRemark(remark)

      :param remark: :ref:`Blob <api-python-datamodel-blob>`

   .. py:method:: remark()

      :rtype: :ref:`Blob <api-python-datamodel-blob>`

      .. note::

         As this attribute is optional, this method throws a ValueError if
         the value of the attribute is not set.

   .. py:method:: add(auxSource)

      :param auxSource: Object of type :ref:`AuxSource <api-python-datamodel-auxsource>`
      :rtype: A Boolean value indicating success with True, False otherwise.

      Adds a AuxSource object to AuxDevice. The object is not
      copied but managed by this instance. Any change to the passed object
      will also change the child.

   .. py:method:: remove(auxSource)

      :param auxSource: Object of type :ref:`AuxSource <api-python-datamodel-auxsource>`
      :rtype: A Boolean value indicating success with True, False otherwise.

      Removes a previously added AuxSource object from AuxDevice.

   .. py:method:: removeAuxSource(idx)

      :param idx: An integer index of the object to be removed.
      :rtype: A Boolean value indicating success with True, False otherwise.

   .. py:method:: removeAuxSource(auxSourceIndex);

      :param auxSourceIndex: The index of the object to be removed of type AuxSourceIndex.
      :rtype: A Boolean value indicating success with True, False otherwise.

   .. py:method:: auxSourceCount()

      :rtype: integer value indicating the number of child objects.

      Returns the number of AuxSource child objects.

   .. py:method:: auxSource(idx)

      :param idx: An integer index of the object to be returned.
      :rtype: Object of type :ref:`AuxSource <api-python-datamodel-auxsource>`.

      Returns the AuxSource at index idx.

   .. py:method:: auxSource(auxSourceIndex)

      :param auxSourceIndex: The index of the object to be removed of type AuxSourceIndex.
      :rtype: Object of type :ref:`AuxSource <api-python-datamodel-auxsource>`.

      Returns the AuxSource at given index. The indexes of all child objects
      are compared by value which makes this function slower than the direct
      integer index look-up.

   .. py:method:: inventory()

      :rtype: Inventory

      Returns the parent Inventory if available. Returns None
      if the parent is not a Inventory. This is a convenience wrapper
      for parent().

   .. py:method:: assign(other)

      This method implements the :ref:`Object <api-python-datamodel-object>` interface.

   .. py:method:: attachTo(parent)

      This method implements the :ref:`Object <api-python-datamodel-object>` interface.

   .. py:method:: detachFrom(parent)

      This method implements the :ref:`Object <api-python-datamodel-object>` interface.

   .. py:method:: detach()

      This method implements the :ref:`Object <api-python-datamodel-object>` interface.

   .. py:method:: clone()

      :rtype: A cloned AuxDevice.

      Returns a new instance that is a clone of the current instance. Child
      objects are being ignored.


   .. py:method:: updateChild(ref)

      :param ref: A child object derived from class Object.
      :rtype: A Boolean flag indicating success with True, False otherwise

      This method takes the passed reference object and searches for a child
      with the same publicID (if derived from :ref:`PublicObject <api-python-datamodel-publicobject>`)
      or the same index (if derived from :ref:`Object <api-python-datamodel-object>`).
      The the child was found the reference objects attributes are copied to
      the child object. Children of child are being ignored during this operation.
      This method implements the :ref:`PublicObject <api-python-datamodel-publicobject>` interface.


   .. py:method:: accept(visitor)

      :param visitor: A visitor.

      This method implements the :ref:`PublicObject <api-python-datamodel-publicobject>` interface.

.. _api-python-datamodel-auxsource:

AuxSource
............................................................

.. py:class:: AuxSource

   Inherits :ref:`Object <api-python-datamodel-object>`.

   This type describes a channel of an auxilliary device

   **Parents**:

   - ``auxDevice`` -- :ref:`AuxDevice <api-python-datamodel-auxdevice>`

   **Attributes**:

   - ``name`` -- string
   - ``description`` -- string
   - ``unit`` -- string
   - ``conversion`` -- string
   - ``sampleRateNumerator`` -- int (optional)
   - ``sampleRateDenominator`` -- int (optional)
   - ``remark`` -- :ref:`Blob <api-python-datamodel-blob>` (optional)

   **Methods**:

   .. py:staticmethod:: Cast(obj)

      :param obj: The object to be casted.
      :rtype: An object of type AuxSource if the cast was successful,
              None otherwise.

      Cast an arbitrary object to AuxSource if the internal wrapped
      representation is an AuxSource object. The cast is important if
      instances of type :ref:`Object <api-python-datamodel-object>`
      are passed to methods which need access to the real type.



   .. py:method:: equal(other)

      :param other: Another object of type AuxSource to compare this
                    instance to
      :rtype: A Boolean value indicating True if both objects are equal or
              False otherwise.

      Compares two objects without its child objects. Both objects are compared
      by value.

   .. py:method:: index()

      :rtype: The object's index of type AuxSourceIndex.

       Returns the objects index which is also used for the database as unique
       constraint.

   .. py:method:: equalIndex(lhs)

      :param lhs: :ref:`AuxSource <api-python-datamodel-auxsource>`
      :rtype: A Boolean value indicating True if both indexes are equal or
              False otherwise.

   .. py:method:: setName(name)

      :param name: string

      Referred from network\/station\/auxStream\/\@source

   .. py:method:: name()

      :rtype: string

   .. py:method:: setDescription(description)

      :param description: string

      Description

   .. py:method:: description()

      :rtype: string

   .. py:method:: setUnit(unit)

      :param unit: string

      Unit of mesurement

   .. py:method:: unit()

      :rtype: string

   .. py:method:: setConversion(conversion)

      :param conversion: string

      Conversion formula from counts to unit of measurement

   .. py:method:: conversion()

      :rtype: string

   .. py:method:: setSampleRateNumerator(sampleRateNumerator)

      :param sampleRateNumerator: int

      Output sample rate \(numerator\); referred from
      network\/station\/AuxStream\/\@sampleRateNumerator

   .. py:method:: sampleRateNumerator()

      :rtype: int

      .. note::

         As this attribute is optional, this method throws a ValueError if
         the value of the attribute is not set.

   .. py:method:: setSampleRateDenominator(sampleRateDenominator)

      :param sampleRateDenominator: int

      Output sample rate \(denominator\); referred from
      network\/station\/AuxStream\/\@sampleRateDenominator

   .. py:method:: sampleRateDenominator()

      :rtype: int

      .. note::

         As this attribute is optional, this method throws a ValueError if
         the value of the attribute is not set.

   .. py:method:: setRemark(remark)

      :param remark: :ref:`Blob <api-python-datamodel-blob>`

   .. py:method:: remark()

      :rtype: :ref:`Blob <api-python-datamodel-blob>`

      .. note::

         As this attribute is optional, this method throws a ValueError if
         the value of the attribute is not set.

   .. py:method:: auxDevice()

      :rtype: AuxDevice

      Returns the parent AuxDevice if available. Returns None
      if the parent is not a AuxDevice. This is a convenience wrapper
      for parent().

   .. py:method:: assign(other)

      This method implements the :ref:`Object <api-python-datamodel-object>` interface.

   .. py:method:: attachTo(parent)

      This method implements the :ref:`Object <api-python-datamodel-object>` interface.

   .. py:method:: detachFrom(parent)

      This method implements the :ref:`Object <api-python-datamodel-object>` interface.

   .. py:method:: detach()

      This method implements the :ref:`Object <api-python-datamodel-object>` interface.

   .. py:method:: clone()

      :rtype: A cloned AuxSource.

      Returns a new instance that is a clone of the current instance. Child
      objects are being ignored.


   .. py:method:: accept(visitor)

      :param visitor: A visitor.

      This method implements the :ref:`PublicObject <api-python-datamodel-publicobject>` interface.

.. _api-python-datamodel-auxstream:

AuxStream
............................................................

.. py:class:: AuxStream

   Inherits :ref:`Object <api-python-datamodel-object>`.

   This type describes a stream \(channel\) without defined frequency response

   **Parents**:

   - ``sensorLocation`` -- :ref:`SensorLocation <api-python-datamodel-sensorlocation>`

   **Attributes**:

   - ``code`` -- string
   - ``start`` -- seiscomp.core.Time
   - ``end`` -- seiscomp.core.Time (optional)
   - ``device`` -- string
   - ``deviceSerialNumber`` -- string
   - ``source`` -- string
   - ``format`` -- string
   - ``flags`` -- string
   - ``restricted`` -- boolean (optional)
   - ``shared`` -- boolean (optional)

   **Methods**:

   .. py:staticmethod:: Cast(obj)

      :param obj: The object to be casted.
      :rtype: An object of type AuxStream if the cast was successful,
              None otherwise.

      Cast an arbitrary object to AuxStream if the internal wrapped
      representation is an AuxStream object. The cast is important if
      instances of type :ref:`Object <api-python-datamodel-object>`
      are passed to methods which need access to the real type.



   .. py:method:: equal(other)

      :param other: Another object of type AuxStream to compare this
                    instance to
      :rtype: A Boolean value indicating True if both objects are equal or
              False otherwise.

      Compares two objects without its child objects. Both objects are compared
      by value.

   .. py:method:: index()

      :rtype: The object's index of type AuxStreamIndex.

       Returns the objects index which is also used for the database as unique
       constraint.

   .. py:method:: equalIndex(lhs)

      :param lhs: :ref:`AuxStream <api-python-datamodel-auxstream>`
      :rtype: A Boolean value indicating True if both indexes are equal or
              False otherwise.

   .. py:method:: setCode(code)

      :param code: string

      Stream code \(52.04\)

   .. py:method:: code()

      :rtype: string

   .. py:method:: setStart(start)

      :param start: seiscomp.core.Time

      Start of epoch in ISO datetime format \(52.22\)

   .. py:method:: start()

      :rtype: seiscomp.core.Time

   .. py:method:: setEnd(end)

      :param end: seiscomp.core.Time

      End of epoch \(52.23\)

   .. py:method:: end()

      :rtype: seiscomp.core.Time

      .. note::

         As this attribute is optional, this method throws a ValueError if
         the value of the attribute is not set.

   .. py:method:: setDevice(device)

      :param device: string

      Reference to auxDevice\/\@publicID

   .. py:method:: device()

      :rtype: string

   .. py:method:: setDeviceSerialNumber(deviceSerialNumber)

      :param deviceSerialNumber: string

      Serial number of device

   .. py:method:: deviceSerialNumber()

      :rtype: string

   .. py:method:: setSource(source)

      :param source: string

      Reference to auxSource\/\@name

   .. py:method:: source()

      :rtype: string

   .. py:method:: setFormat(format)

      :param format: string

      Data format, eg.: \"steim1\", \"steim2\", \"mseedN\" \(N \= encoding format
      in blockette 1000\)

   .. py:method:: format()

      :rtype: string

   .. py:method:: setFlags(flags)

      :param flags: string

      Channel flags \(52.21\)

   .. py:method:: flags()

      :rtype: string

   .. py:method:: setRestricted(restricted)

      :param restricted: boolean

      Whether the stream is \"restricted\"

   .. py:method:: restricted()

      :rtype: boolean

      .. note::

         As this attribute is optional, this method throws a ValueError if
         the value of the attribute is not set.

   .. py:method:: setShared(shared)

      :param shared: boolean

      Whether the metadata is synchronized with other datacenters

   .. py:method:: shared()

      :rtype: boolean

      .. note::

         As this attribute is optional, this method throws a ValueError if
         the value of the attribute is not set.

   .. py:method:: sensorLocation()

      :rtype: SensorLocation

      Returns the parent SensorLocation if available. Returns None
      if the parent is not a SensorLocation. This is a convenience wrapper
      for parent().

   .. py:method:: assign(other)

      This method implements the :ref:`Object <api-python-datamodel-object>` interface.

   .. py:method:: attachTo(parent)

      This method implements the :ref:`Object <api-python-datamodel-object>` interface.

   .. py:method:: detachFrom(parent)

      This method implements the :ref:`Object <api-python-datamodel-object>` interface.

   .. py:method:: detach()

      This method implements the :ref:`Object <api-python-datamodel-object>` interface.

   .. py:method:: clone()

      :rtype: A cloned AuxStream.

      Returns a new instance that is a clone of the current instance. Child
      objects are being ignored.


   .. py:method:: accept(visitor)

      :param visitor: A visitor.

      This method implements the :ref:`PublicObject <api-python-datamodel-publicobject>` interface.

.. _api-python-datamodel-axis:

Axis
............................................................

.. py:class:: Axis

   Inherits :ref:`Object <api-python-datamodel-object>`.

   This class describes an eigenvector of a moment tensor expressed in its
   principal\-axes system. It uses the angles azimuth, plunge, and the
   eigenvalue length.

   **Attributes**:

   - ``azimuth`` -- :ref:`RealQuantity <api-python-datamodel-realquantity>`
   - ``plunge`` -- :ref:`RealQuantity <api-python-datamodel-realquantity>`
   - ``length`` -- :ref:`RealQuantity <api-python-datamodel-realquantity>`

   **Used by**:

   - :func:`PrincipalAxes.tAxis`
   - :func:`PrincipalAxes.pAxis`
   - :func:`PrincipalAxes.nAxis`

   **Methods**:

   .. py:staticmethod:: Cast(obj)

      :param obj: The object to be casted.
      :rtype: An object of type Axis if the cast was successful,
              None otherwise.

      Cast an arbitrary object to Axis if the internal wrapped
      representation is an Axis object. The cast is important if
      instances of type :ref:`Object <api-python-datamodel-object>`
      are passed to methods which need access to the real type.



   .. py:method:: equal(other)

      :param other: Another object of type Axis to compare this
                    instance to
      :rtype: A Boolean value indicating True if both objects are equal or
              False otherwise.

      Compares two objects without its child objects. Both objects are compared
      by value.

   .. py:method:: setAzimuth(azimuth)

      :param azimuth: :ref:`RealQuantity <api-python-datamodel-realquantity>`

      Azimuth of eigenvector of moment tensor expressed in principal\-axes system.
      Measured clockwise
      from South\-North direction at epicenter in degrees.

   .. py:method:: azimuth()

      :rtype: :ref:`RealQuantity <api-python-datamodel-realquantity>`

   .. py:method:: setPlunge(plunge)

      :param plunge: :ref:`RealQuantity <api-python-datamodel-realquantity>`

      Plunge of eigenvector of moment tensor expressed in principal\-axes system.
      Measured against downward
      vertical direction at epicenter in degrees.

   .. py:method:: plunge()

      :rtype: :ref:`RealQuantity <api-python-datamodel-realquantity>`

   .. py:method:: setLength(length)

      :param length: :ref:`RealQuantity <api-python-datamodel-realquantity>`

      Eigenvalue of moment tensor expressed in principal\-axes system in Nm.

   .. py:method:: length()

      :rtype: :ref:`RealQuantity <api-python-datamodel-realquantity>`

.. _api-python-datamodel-blob:

Blob
............................................................

.. py:class:: Blob

   Inherits :ref:`Object <api-python-datamodel-object>`.


   **Attributes**:

   - ``content`` -- string

   **Used by**:

   - :func:`AuxDevice.remark`
   - :func:`AuxSource.remark`
   - :func:`Datalogger.remark`
   - :func:`DataloggerCalibration.remark`
   - :func:`Decimation.analogueFilterChain`
   - :func:`Decimation.digitalFilterChain`
   - :func:`Network.remark`
   - :func:`ResponseFAP.remark`
   - :func:`ResponseFIR.remark`
   - :func:`ResponseIIR.remark`
   - :func:`ResponsePAZ.remark`
   - :func:`ResponsePolynomial.remark`
   - :func:`Sensor.remark`
   - :func:`SensorCalibration.remark`
   - :func:`Station.remark`

   **Methods**:

   .. py:staticmethod:: Cast(obj)

      :param obj: The object to be casted.
      :rtype: An object of type Blob if the cast was successful,
              None otherwise.

      Cast an arbitrary object to Blob if the internal wrapped
      representation is an Blob object. The cast is important if
      instances of type :ref:`Object <api-python-datamodel-object>`
      are passed to methods which need access to the real type.



   .. py:method:: equal(other)

      :param other: Another object of type Blob to compare this
                    instance to
      :rtype: A Boolean value indicating True if both objects are equal or
              False otherwise.

      Compares two objects without its child objects. Both objects are compared
      by value.

   .. py:method:: setContent(content)

      :param content: string

   .. py:method:: content()

      :rtype: string

.. _api-python-datamodel-comment:

Comment
............................................................

.. py:class:: Comment

   Inherits :ref:`Object <api-python-datamodel-object>`.

   Comment holds information on comments to a resource as well as author and
   creation time information.

   **Parents**:

   - ``momentTensor`` -- :ref:`MomentTensor <api-python-datamodel-momenttensor>`
   - ``focalMechanism`` -- :ref:`FocalMechanism <api-python-datamodel-focalmechanism>`
   - ``amplitude`` -- :ref:`Amplitude <api-python-datamodel-amplitude>`
   - ``magnitude`` -- :ref:`Magnitude <api-python-datamodel-magnitude>`
   - ``stationMagnitude`` -- :ref:`StationMagnitude <api-python-datamodel-stationmagnitude>`
   - ``pick`` -- :ref:`Pick <api-python-datamodel-pick>`
   - ``event`` -- :ref:`Event <api-python-datamodel-event>`
   - ``origin`` -- :ref:`Origin <api-python-datamodel-origin>`
   - ``parameter`` -- :ref:`Parameter <api-python-datamodel-parameter>`
   - ``parameterSet`` -- :ref:`ParameterSet <api-python-datamodel-parameterset>`
   - ``stream`` -- :ref:`Stream <api-python-datamodel-stream>`
   - ``sensorLocation`` -- :ref:`SensorLocation <api-python-datamodel-sensorlocation>`
   - ``station`` -- :ref:`Station <api-python-datamodel-station>`
   - ``network`` -- :ref:`Network <api-python-datamodel-network>`

   **Attributes**:

   - ``text`` -- string
   - ``id`` -- string
   - ``start`` -- seiscomp.core.Time (optional)
   - ``end`` -- seiscomp.core.Time (optional)
   - ``creationInfo`` -- :ref:`CreationInfo <api-python-datamodel-creationinfo>` (optional)

   **Methods**:

   .. py:staticmethod:: Cast(obj)

      :param obj: The object to be casted.
      :rtype: An object of type Comment if the cast was successful,
              None otherwise.

      Cast an arbitrary object to Comment if the internal wrapped
      representation is an Comment object. The cast is important if
      instances of type :ref:`Object <api-python-datamodel-object>`
      are passed to methods which need access to the real type.



   .. py:method:: equal(other)

      :param other: Another object of type Comment to compare this
                    instance to
      :rtype: A Boolean value indicating True if both objects are equal or
              False otherwise.

      Compares two objects without its child objects. Both objects are compared
      by value.

   .. py:method:: index()

      :rtype: The object's index of type CommentIndex.

       Returns the objects index which is also used for the database as unique
       constraint.

   .. py:method:: equalIndex(lhs)

      :param lhs: :ref:`Comment <api-python-datamodel-comment>`
      :rtype: A Boolean value indicating True if both indexes are equal or
              False otherwise.

   .. py:method:: setText(text)

      :param text: string

      Text of comment.

   .. py:method:: text()

      :rtype: string

   .. py:method:: setId(id)

      :param id: string

      Identifier of comment, possibly in QuakeML RI format.

   .. py:method:: id()

      :rtype: string

   .. py:method:: setStart(start)

      :param start: seiscomp.core.Time

      Start of epoch in ISO datetime format

   .. py:method:: start()

      :rtype: seiscomp.core.Time

      .. note::

         As this attribute is optional, this method throws a ValueError if
         the value of the attribute is not set.

   .. py:method:: setEnd(end)

      :param end: seiscomp.core.Time

      End of epoch \(empty if the comment epoch is open\)

   .. py:method:: end()

      :rtype: seiscomp.core.Time

      .. note::

         As this attribute is optional, this method throws a ValueError if
         the value of the attribute is not set.

   .. py:method:: setCreationInfo(creationInfo)

      :param creationInfo: :ref:`CreationInfo <api-python-datamodel-creationinfo>`

      CreationInfo for the Comment object.

   .. py:method:: creationInfo()

      :rtype: :ref:`CreationInfo <api-python-datamodel-creationinfo>`

      .. note::

         As this attribute is optional, this method throws a ValueError if
         the value of the attribute is not set.

   .. py:method:: momentTensor()

      :rtype: MomentTensor

      Returns the parent MomentTensor if available. Returns None
      if the parent is not a MomentTensor. This is a convenience wrapper
      for parent().

   .. py:method:: focalMechanism()

      :rtype: FocalMechanism

      Returns the parent FocalMechanism if available. Returns None
      if the parent is not a FocalMechanism. This is a convenience wrapper
      for parent().

   .. py:method:: amplitude()

      :rtype: Amplitude

      Returns the parent Amplitude if available. Returns None
      if the parent is not a Amplitude. This is a convenience wrapper
      for parent().

   .. py:method:: magnitude()

      :rtype: Magnitude

      Returns the parent Magnitude if available. Returns None
      if the parent is not a Magnitude. This is a convenience wrapper
      for parent().

   .. py:method:: stationMagnitude()

      :rtype: StationMagnitude

      Returns the parent StationMagnitude if available. Returns None
      if the parent is not a StationMagnitude. This is a convenience wrapper
      for parent().

   .. py:method:: pick()

      :rtype: Pick

      Returns the parent Pick if available. Returns None
      if the parent is not a Pick. This is a convenience wrapper
      for parent().

   .. py:method:: event()

      :rtype: Event

      Returns the parent Event if available. Returns None
      if the parent is not a Event. This is a convenience wrapper
      for parent().

   .. py:method:: origin()

      :rtype: Origin

      Returns the parent Origin if available. Returns None
      if the parent is not a Origin. This is a convenience wrapper
      for parent().

   .. py:method:: parameter()

      :rtype: Parameter

      Returns the parent Parameter if available. Returns None
      if the parent is not a Parameter. This is a convenience wrapper
      for parent().

   .. py:method:: parameterSet()

      :rtype: ParameterSet

      Returns the parent ParameterSet if available. Returns None
      if the parent is not a ParameterSet. This is a convenience wrapper
      for parent().

   .. py:method:: stream()

      :rtype: Stream

      Returns the parent Stream if available. Returns None
      if the parent is not a Stream. This is a convenience wrapper
      for parent().

   .. py:method:: sensorLocation()

      :rtype: SensorLocation

      Returns the parent SensorLocation if available. Returns None
      if the parent is not a SensorLocation. This is a convenience wrapper
      for parent().

   .. py:method:: station()

      :rtype: Station

      Returns the parent Station if available. Returns None
      if the parent is not a Station. This is a convenience wrapper
      for parent().

   .. py:method:: network()

      :rtype: Network

      Returns the parent Network if available. Returns None
      if the parent is not a Network. This is a convenience wrapper
      for parent().

   .. py:method:: assign(other)

      This method implements the :ref:`Object <api-python-datamodel-object>` interface.

   .. py:method:: attachTo(parent)

      This method implements the :ref:`Object <api-python-datamodel-object>` interface.

   .. py:method:: detachFrom(parent)

      This method implements the :ref:`Object <api-python-datamodel-object>` interface.

   .. py:method:: detach()

      This method implements the :ref:`Object <api-python-datamodel-object>` interface.

   .. py:method:: clone()

      :rtype: A cloned Comment.

      Returns a new instance that is a clone of the current instance. Child
      objects are being ignored.


   .. py:method:: accept(visitor)

      :param visitor: A visitor.

      This method implements the :ref:`PublicObject <api-python-datamodel-publicobject>` interface.

.. _api-python-datamodel-complexarray:

ComplexArray
............................................................

.. py:class:: ComplexArray

   Inherits :ref:`Object <api-python-datamodel-object>`.


   **Attributes**:

   - ``content`` -- complex (optional)

   **Used by**:

   - :func:`ResponsePAZ.zeros`
   - :func:`ResponsePAZ.poles`

   **Methods**:

   .. py:staticmethod:: Cast(obj)

      :param obj: The object to be casted.
      :rtype: An object of type ComplexArray if the cast was successful,
              None otherwise.

      Cast an arbitrary object to ComplexArray if the internal wrapped
      representation is an ComplexArray object. The cast is important if
      instances of type :ref:`Object <api-python-datamodel-object>`
      are passed to methods which need access to the real type.



   .. py:method:: equal(other)

      :param other: Another object of type ComplexArray to compare this
                    instance to
      :rtype: A Boolean value indicating True if both objects are equal or
              False otherwise.

      Compares two objects without its child objects. Both objects are compared
      by value.

   .. py:method:: setContent(content)

      :param content: complex

   .. py:method:: content()

      :rtype: complex

      .. note::

         As this attribute is optional, this method throws a ValueError if
         the value of the attribute is not set.

.. _api-python-datamodel-compositetime:

CompositeTime
............................................................

.. py:class:: CompositeTime

   Inherits :ref:`Object <api-python-datamodel-object>`.

   Focal times differ significantly in their precision. While focal times
   of instrumentally located earthquakes are estimated precisely down to
   seconds, historic events have only incomplete time descriptions. Sometimes,
   even contradictory information about the rupture time exist. The
   CompositeTime type allows for such complex descriptions. If the specification
   is given with no greater accuracy than days \(i.e., no time components are
   given\), the date refers to local time. However, if time components are
   given, they have to refer to UTC. As an example, consider a historic
   earthquake in California, e.g., on 28 February 1730, with no time information
   given. Expressed in UTC, this day extends from 1730\-02\-28T08:00:00Z
   until 1730\-03\-01T08:00:00Z. Such a specification would be against intuition.
   Therefore, for date\-time specifications without time components, local
   time is used. In the example, the CompositeTime attributes are simply
   year 1730, month 2, and day 28. In the corresponding time attribute of
   the origin, however, UTC has to be used. If the unknown time components
   are assumed to be zero, the value is 1730\-02\-28T08:00:00Z.

   **Parents**:

   - ``origin`` -- :ref:`Origin <api-python-datamodel-origin>`

   **Attributes**:

   - ``year`` -- :ref:`IntegerQuantity <api-python-datamodel-integerquantity>` (optional)
   - ``month`` -- :ref:`IntegerQuantity <api-python-datamodel-integerquantity>` (optional)
   - ``day`` -- :ref:`IntegerQuantity <api-python-datamodel-integerquantity>` (optional)
   - ``hour`` -- :ref:`IntegerQuantity <api-python-datamodel-integerquantity>` (optional)
   - ``minute`` -- :ref:`IntegerQuantity <api-python-datamodel-integerquantity>` (optional)
   - ``second`` -- :ref:`RealQuantity <api-python-datamodel-realquantity>` (optional)

   **Methods**:

   .. py:staticmethod:: Cast(obj)

      :param obj: The object to be casted.
      :rtype: An object of type CompositeTime if the cast was successful,
              None otherwise.

      Cast an arbitrary object to CompositeTime if the internal wrapped
      representation is an CompositeTime object. The cast is important if
      instances of type :ref:`Object <api-python-datamodel-object>`
      are passed to methods which need access to the real type.



   .. py:method:: equal(other)

      :param other: Another object of type CompositeTime to compare this
                    instance to
      :rtype: A Boolean value indicating True if both objects are equal or
              False otherwise.

      Compares two objects without its child objects. Both objects are compared
      by value.

   .. py:method:: setYear(year)

      :param year: :ref:`IntegerQuantity <api-python-datamodel-integerquantity>`

      Year or range of years of the event's focal time.

   .. py:method:: year()

      :rtype: :ref:`IntegerQuantity <api-python-datamodel-integerquantity>`

      .. note::

         As this attribute is optional, this method throws a ValueError if
         the value of the attribute is not set.

   .. py:method:: setMonth(month)

      :param month: :ref:`IntegerQuantity <api-python-datamodel-integerquantity>`

      Month or range of months of the event's focal time.

   .. py:method:: month()

      :rtype: :ref:`IntegerQuantity <api-python-datamodel-integerquantity>`

      .. note::

         As this attribute is optional, this method throws a ValueError if
         the value of the attribute is not set.

   .. py:method:: setDay(day)

      :param day: :ref:`IntegerQuantity <api-python-datamodel-integerquantity>`

      Day or range of days of the event's focal time.

   .. py:method:: day()

      :rtype: :ref:`IntegerQuantity <api-python-datamodel-integerquantity>`

      .. note::

         As this attribute is optional, this method throws a ValueError if
         the value of the attribute is not set.

   .. py:method:: setHour(hour)

      :param hour: :ref:`IntegerQuantity <api-python-datamodel-integerquantity>`

      Hour or range of hours of the event's focal time.

   .. py:method:: hour()

      :rtype: :ref:`IntegerQuantity <api-python-datamodel-integerquantity>`

      .. note::

         As this attribute is optional, this method throws a ValueError if
         the value of the attribute is not set.

   .. py:method:: setMinute(minute)

      :param minute: :ref:`IntegerQuantity <api-python-datamodel-integerquantity>`

      Minute or range of minutes of the event's focal time.

   .. py:method:: minute()

      :rtype: :ref:`IntegerQuantity <api-python-datamodel-integerquantity>`

      .. note::

         As this attribute is optional, this method throws a ValueError if
         the value of the attribute is not set.

   .. py:method:: setSecond(second)

      :param second: :ref:`RealQuantity <api-python-datamodel-realquantity>`

      Second and fraction of seconds or range of seconds with fraction of the
      event's focal time.

   .. py:method:: second()

      :rtype: :ref:`RealQuantity <api-python-datamodel-realquantity>`

      .. note::

         As this attribute is optional, this method throws a ValueError if
         the value of the attribute is not set.

   .. py:method:: origin()

      :rtype: Origin

      Returns the parent Origin if available. Returns None
      if the parent is not a Origin. This is a convenience wrapper
      for parent().

   .. py:method:: assign(other)

      This method implements the :ref:`Object <api-python-datamodel-object>` interface.

   .. py:method:: attachTo(parent)

      This method implements the :ref:`Object <api-python-datamodel-object>` interface.

   .. py:method:: detachFrom(parent)

      This method implements the :ref:`Object <api-python-datamodel-object>` interface.

   .. py:method:: detach()

      This method implements the :ref:`Object <api-python-datamodel-object>` interface.

   .. py:method:: clone()

      :rtype: A cloned CompositeTime.

      Returns a new instance that is a clone of the current instance. Child
      objects are being ignored.


   .. py:method:: accept(visitor)

      :param visitor: A visitor.

      This method implements the :ref:`PublicObject <api-python-datamodel-publicobject>` interface.

.. _api-python-datamodel-confidenceellipsoid:

ConfidenceEllipsoid
............................................................

.. py:class:: ConfidenceEllipsoid

   Inherits :ref:`Object <api-python-datamodel-object>`.

   This class represents a description of the location uncertainty as a confidence
   ellipsoid with arbitrary orientation in space. The orientation of a rigid
   body in three\-dimensional Euclidean space can be described by three
   parameters. We use the convention of Euler angles, which can be interpreted
   as a composition of three elemental rotations \(i.e., rotations around a single
   axis\).
   In the special case of Euler angles we use here, the angles are referred
   to as Tait\-Bryan \(or Cardan\) angles. These angles may be familiar to
   the reader from their application in flight dynamics, and are referred
   to as heading \(yaw, psi\), elevation \(attitude, pitch, phi\), and bank
   \(roll, theta\).
   For a definition of the angles, see Figure 4. Through the three elemental
   rotations, a Cartesian system \(x, y, z\) centered at the epicenter, with
   the South\-North direction x, the West\-East direction y, and the downward
   vertical direction z, is transferred into a different Cartesian system
   \(X, Y , Z\) centered on the confidence ellipsoid. Here, X denotes the direction
   of the major axis, and Y denotes the direction of the minor axis of the
   ellipsoid. Note that Figure 4 can be interpreted as a hypothetical view
   from the interior of the Earth to the inner face of a shell representing
   Earth's surface. The three Tait\-Bryan rotations are performed as follows:
   \(i\) a rotation about the Z axis with angle psi \(heading, or azimuth\);
   \(ii\) a rotation about the Y axis with angle phi \(elevation, or plunge\);
   and \(iii\) a rotation about the X axis with angle theta \(bank\). Note that in
   the case of Tait\-Bryan angles, the rotations are performed about the
   ellipsoid's axes, not about the axes of the fixed \(x, y, z\) Cartesian system.
   In the following list the correspondence of the attributes of class
   ConfidenceEllipsoid to the respective Tait\-Bryan angles is listed:
   majorAxisPlunge: elevation \(pitch, phi\), majorAxisAzimuth: heading \(yaw,
   psi\), majorAxisRotation: bank \(roll, theta\)

   **Attributes**:

   - ``semiMajorAxisLength`` -- float
   - ``semiMinorAxisLength`` -- float
   - ``semiIntermediateAxisLength`` -- float
   - ``majorAxisPlunge`` -- float
   - ``majorAxisAzimuth`` -- float
   - ``majorAxisRotation`` -- float

   **Used by**:

   - :func:`OriginUncertainty.confidenceEllipsoid`

   **Methods**:

   .. py:staticmethod:: Cast(obj)

      :param obj: The object to be casted.
      :rtype: An object of type ConfidenceEllipsoid if the cast was successful,
              None otherwise.

      Cast an arbitrary object to ConfidenceEllipsoid if the internal wrapped
      representation is an ConfidenceEllipsoid object. The cast is important if
      instances of type :ref:`Object <api-python-datamodel-object>`
      are passed to methods which need access to the real type.



   .. py:method:: equal(other)

      :param other: Another object of type ConfidenceEllipsoid to compare this
                    instance to
      :rtype: A Boolean value indicating True if both objects are equal or
              False otherwise.

      Compares two objects without its child objects. Both objects are compared
      by value.

   .. py:method:: setSemiMajorAxisLength(semiMajorAxisLength)

      :param semiMajorAxisLength: float

      Largest uncertainty, corresponding to the semi\-major axis of the confidence
      ellipsoid in meter.

   .. py:method:: semiMajorAxisLength()

      :rtype: float

   .. py:method:: setSemiMinorAxisLength(semiMinorAxisLength)

      :param semiMinorAxisLength: float

      Smallest uncertainty, corresponding to the semi\-minor axis of the
      confidence ellipsoid in meter.

   .. py:method:: semiMinorAxisLength()

      :rtype: float

   .. py:method:: setSemiIntermediateAxisLength(semiIntermediateAxisLength)

      :param semiIntermediateAxisLength: float

      Uncertainty in direction orthogonal to major and minor axes of the
      confidence ellipsoid in meter.

   .. py:method:: semiIntermediateAxisLength()

      :rtype: float

   .. py:method:: setMajorAxisPlunge(majorAxisPlunge)

      :param majorAxisPlunge: float

      Plunge angle of major axis of confidence ellipsoid. Corresponds to
      Tait\-Bryan angle phi
      in degrees.

   .. py:method:: majorAxisPlunge()

      :rtype: float

   .. py:method:: setMajorAxisAzimuth(majorAxisAzimuth)

      :param majorAxisAzimuth: float

      Azimuth angle of major axis of confidence ellipsoid. Corresponds to
      Tait\-Bryan angle psi
      in degrees.

   .. py:method:: majorAxisAzimuth()

      :rtype: float

   .. py:method:: setMajorAxisRotation(majorAxisRotation)

      :param majorAxisRotation: float

      This angle describes a rotation about the confidence ellipsoid's major axis
      which is required
      to define the direction of the ellipsoid's minor axis. Corresponds to
      Tait\-Bryan angle theta
      in degrees.

   .. py:method:: majorAxisRotation()

      :rtype: float

.. _api-python-datamodel-config:

Config
............................................................

.. py:class:: Config

   Inherits :ref:`PublicObject <api-python-datamodel-publicobject>`.


   **Children**:

   - ``parameterSet`` -- :ref:`ParameterSet <api-python-datamodel-parameterset>`
   - ``configModule`` -- :ref:`ConfigModule <api-python-datamodel-configmodule>`

   **Attributes**:

   - ``publicID``: string

   **Methods**:

   .. py:staticmethod:: Cast(obj)

      :param obj: The object to be casted.
      :rtype: An object of type Config if the cast was successful,
              None otherwise.

      Cast an arbitrary object to Config if the internal wrapped
      representation is an Config object. The cast is important if
      instances of type :ref:`Object <api-python-datamodel-object>`
      are passed to methods which need access to the real type.



   .. py:method:: equal(other)

      :param other: Another object of type Config to compare this
                    instance to
      :rtype: A Boolean value indicating True if both objects are equal or
              False otherwise.

      Compares two objects without its child objects. Both objects are compared
      by value.

   .. py:method:: add(parameterSet)

      :param parameterSet: Object of type :ref:`ParameterSet <api-python-datamodel-parameterset>`
      :rtype: A Boolean value indicating success with True, False otherwise.

      Adds a ParameterSet object to Config. The object is not
      copied but managed by this instance. Any change to the passed object
      will also change the child.

   .. py:method:: add(configModule)

      :param configModule: Object of type :ref:`ConfigModule <api-python-datamodel-configmodule>`
      :rtype: A Boolean value indicating success with True, False otherwise.

      Adds a ConfigModule object to Config. The object is not
      copied but managed by this instance. Any change to the passed object
      will also change the child.

   .. py:method:: remove(parameterSet)

      :param parameterSet: Object of type :ref:`ParameterSet <api-python-datamodel-parameterset>`
      :rtype: A Boolean value indicating success with True, False otherwise.

      Removes a previously added ParameterSet object from Config.

   .. py:method:: remove(configModule)

      :param configModule: Object of type :ref:`ConfigModule <api-python-datamodel-configmodule>`
      :rtype: A Boolean value indicating success with True, False otherwise.

      Removes a previously added ConfigModule object from Config.

   .. py:method:: removeParameterSet(idx)

      :param idx: An integer index of the object to be removed.
      :rtype: A Boolean value indicating success with True, False otherwise.

   .. py:method:: removeConfigModule(idx)

      :param idx: An integer index of the object to be removed.
      :rtype: A Boolean value indicating success with True, False otherwise.

   .. py:method:: parameterSetCount()

      :rtype: integer value indicating the number of child objects.

      Returns the number of ParameterSet child objects.

   .. py:method:: configModuleCount()

      :rtype: integer value indicating the number of child objects.

      Returns the number of ConfigModule child objects.

   .. py:method:: parameterSet(idx)

      :param idx: An integer index of the object to be returned.
      :rtype: Object of type :ref:`ParameterSet <api-python-datamodel-parameterset>`.

      Returns the ParameterSet at index idx.

   .. py:method:: configModule(idx)

      :param idx: An integer index of the object to be returned.
      :rtype: Object of type :ref:`ConfigModule <api-python-datamodel-configmodule>`.

      Returns the ConfigModule at index idx.

   .. py:method:: findParameterSet(publicID)

      :param publicID: The publicID of the object to find.
      :rtype: Object of type :ref:`ParameterSet <api-python-datamodel-parameterset>`.

      Returns the child object with a certain publicID, None otherwise.

   .. py:method:: findConfigModule(publicID)

      :param publicID: The publicID of the object to find.
      :rtype: Object of type :ref:`ConfigModule <api-python-datamodel-configmodule>`.

      Returns the child object with a certain publicID, None otherwise.

   .. py:method:: assign(other)

      This method implements the :ref:`Object <api-python-datamodel-object>` interface.

   .. py:method:: attachTo(parent)

      This method implements the :ref:`Object <api-python-datamodel-object>` interface.

   .. py:method:: detachFrom(parent)

      This method implements the :ref:`Object <api-python-datamodel-object>` interface.

   .. py:method:: detach()

      This method implements the :ref:`Object <api-python-datamodel-object>` interface.

   .. py:method:: clone()

      :rtype: A cloned Config.

      Returns a new instance that is a clone of the current instance. Child
      objects are being ignored.


   .. py:method:: updateChild(ref)

      :param ref: A child object derived from class Object.
      :rtype: A Boolean flag indicating success with True, False otherwise

      This method takes the passed reference object and searches for a child
      with the same publicID (if derived from :ref:`PublicObject <api-python-datamodel-publicobject>`)
      or the same index (if derived from :ref:`Object <api-python-datamodel-object>`).
      The the child was found the reference objects attributes are copied to
      the child object. Children of child are being ignored during this operation.
      This method implements the :ref:`PublicObject <api-python-datamodel-publicobject>` interface.


   .. py:method:: accept(visitor)

      :param visitor: A visitor.

      This method implements the :ref:`PublicObject <api-python-datamodel-publicobject>` interface.

.. _api-python-datamodel-configmodule:

ConfigModule
............................................................

.. py:class:: ConfigModule

   Inherits :ref:`PublicObject <api-python-datamodel-publicobject>`.


   **Parents**:

   - ``config`` -- :ref:`Config <api-python-datamodel-config>`

   **Children**:

   - ``configStation`` -- :ref:`ConfigStation <api-python-datamodel-configstation>`

   **Attributes**:

   - ``publicID``: string
   - ``name`` -- string
   - ``parameterSetID`` -- string
   - ``enabled`` -- boolean

   **Referenced by**:

   - :func:`ParameterSet.moduleID`

   **Methods**:

   .. py:staticmethod:: Cast(obj)

      :param obj: The object to be casted.
      :rtype: An object of type ConfigModule if the cast was successful,
              None otherwise.

      Cast an arbitrary object to ConfigModule if the internal wrapped
      representation is an ConfigModule object. The cast is important if
      instances of type :ref:`Object <api-python-datamodel-object>`
      are passed to methods which need access to the real type.



   .. py:staticmethod:: Create()

      :rtype: A new object of type ConfigModule.

      Creates and registers (if enabled) a ConfigModule instance. The
      publicID is auto-generated.

   .. py:staticmethod:: Create(publicID)

      :rtype: A new object of type ConfigModule.

      Creates and registers (if enabled) a ConfigModule instance with
      passed publicID.

   .. py:method:: equal(other)

      :param other: Another object of type ConfigModule to compare this
                    instance to
      :rtype: A Boolean value indicating True if both objects are equal or
              False otherwise.

      Compares two objects without its child objects. Both objects are compared
      by value.

   .. py:method:: setName(name)

      :param name: string

   .. py:method:: name()

      :rtype: string

   .. py:method:: setParameterSetID(parameterSetID)

      :param parameterSetID: string

   .. py:method:: parameterSetID()

      :rtype: string

   .. py:method:: setEnabled(enabled)

      :param enabled: boolean

   .. py:method:: enabled()

      :rtype: boolean

   .. py:method:: add(configStation)

      :param configStation: Object of type :ref:`ConfigStation <api-python-datamodel-configstation>`
      :rtype: A Boolean value indicating success with True, False otherwise.

      Adds a ConfigStation object to ConfigModule. The object is not
      copied but managed by this instance. Any change to the passed object
      will also change the child.

   .. py:method:: remove(configStation)

      :param configStation: Object of type :ref:`ConfigStation <api-python-datamodel-configstation>`
      :rtype: A Boolean value indicating success with True, False otherwise.

      Removes a previously added ConfigStation object from ConfigModule.

   .. py:method:: removeConfigStation(idx)

      :param idx: An integer index of the object to be removed.
      :rtype: A Boolean value indicating success with True, False otherwise.

   .. py:method:: removeConfigStation(configStationIndex);

      :param configStationIndex: The index of the object to be removed of type ConfigStationIndex.
      :rtype: A Boolean value indicating success with True, False otherwise.

   .. py:method:: configStationCount()

      :rtype: integer value indicating the number of child objects.

      Returns the number of ConfigStation child objects.

   .. py:method:: configStation(idx)

      :param idx: An integer index of the object to be returned.
      :rtype: Object of type :ref:`ConfigStation <api-python-datamodel-configstation>`.

      Returns the ConfigStation at index idx.

   .. py:method:: configStation(configStationIndex)

      :param configStationIndex: The index of the object to be removed of type ConfigStationIndex.
      :rtype: Object of type :ref:`ConfigStation <api-python-datamodel-configstation>`.

      Returns the ConfigStation at given index. The indexes of all child objects
      are compared by value which makes this function slower than the direct
      integer index look-up.

   .. py:method:: findConfigStation(publicID)

      :param publicID: The publicID of the object to find.
      :rtype: Object of type :ref:`ConfigStation <api-python-datamodel-configstation>`.

      Returns the child object with a certain publicID, None otherwise.

   .. py:method:: config()

      :rtype: Config

      Returns the parent Config if available. Returns None
      if the parent is not a Config. This is a convenience wrapper
      for parent().

   .. py:method:: assign(other)

      This method implements the :ref:`Object <api-python-datamodel-object>` interface.

   .. py:method:: attachTo(parent)

      This method implements the :ref:`Object <api-python-datamodel-object>` interface.

   .. py:method:: detachFrom(parent)

      This method implements the :ref:`Object <api-python-datamodel-object>` interface.

   .. py:method:: detach()

      This method implements the :ref:`Object <api-python-datamodel-object>` interface.

   .. py:method:: clone()

      :rtype: A cloned ConfigModule.

      Returns a new instance that is a clone of the current instance. Child
      objects are being ignored.


   .. py:method:: updateChild(ref)

      :param ref: A child object derived from class Object.
      :rtype: A Boolean flag indicating success with True, False otherwise

      This method takes the passed reference object and searches for a child
      with the same publicID (if derived from :ref:`PublicObject <api-python-datamodel-publicobject>`)
      or the same index (if derived from :ref:`Object <api-python-datamodel-object>`).
      The the child was found the reference objects attributes are copied to
      the child object. Children of child are being ignored during this operation.
      This method implements the :ref:`PublicObject <api-python-datamodel-publicobject>` interface.


   .. py:method:: accept(visitor)

      :param visitor: A visitor.

      This method implements the :ref:`PublicObject <api-python-datamodel-publicobject>` interface.

.. _api-python-datamodel-configstation:

ConfigStation
............................................................

.. py:class:: ConfigStation

   Inherits :ref:`PublicObject <api-python-datamodel-publicobject>`.


   **Parents**:

   - ``configModule`` -- :ref:`ConfigModule <api-python-datamodel-configmodule>`

   **Children**:

   - ``setup`` -- :ref:`Setup <api-python-datamodel-setup>`

   **Attributes**:

   - ``publicID``: string
   - ``networkCode`` -- string
   - ``stationCode`` -- string
   - ``enabled`` -- boolean
   - ``creationInfo`` -- :ref:`CreationInfo <api-python-datamodel-creationinfo>` (optional)

   **Methods**:

   .. py:staticmethod:: Cast(obj)

      :param obj: The object to be casted.
      :rtype: An object of type ConfigStation if the cast was successful,
              None otherwise.

      Cast an arbitrary object to ConfigStation if the internal wrapped
      representation is an ConfigStation object. The cast is important if
      instances of type :ref:`Object <api-python-datamodel-object>`
      are passed to methods which need access to the real type.



   .. py:staticmethod:: Create()

      :rtype: A new object of type ConfigStation.

      Creates and registers (if enabled) a ConfigStation instance. The
      publicID is auto-generated.

   .. py:staticmethod:: Create(publicID)

      :rtype: A new object of type ConfigStation.

      Creates and registers (if enabled) a ConfigStation instance with
      passed publicID.

   .. py:method:: equal(other)

      :param other: Another object of type ConfigStation to compare this
                    instance to
      :rtype: A Boolean value indicating True if both objects are equal or
              False otherwise.

      Compares two objects without its child objects. Both objects are compared
      by value.

   .. py:method:: index()

      :rtype: The object's index of type ConfigStationIndex.

       Returns the objects index which is also used for the database as unique
       constraint.

   .. py:method:: equalIndex(lhs)

      :param lhs: :ref:`ConfigStation <api-python-datamodel-configstation>`
      :rtype: A Boolean value indicating True if both indexes are equal or
              False otherwise.

   .. py:method:: setNetworkCode(networkCode)

      :param networkCode: string

   .. py:method:: networkCode()

      :rtype: string

   .. py:method:: setStationCode(stationCode)

      :param stationCode: string

   .. py:method:: stationCode()

      :rtype: string

   .. py:method:: setEnabled(enabled)

      :param enabled: boolean

   .. py:method:: enabled()

      :rtype: boolean

   .. py:method:: setCreationInfo(creationInfo)

      :param creationInfo: :ref:`CreationInfo <api-python-datamodel-creationinfo>`

      CreationInfo for the ConfigStation object.

   .. py:method:: creationInfo()

      :rtype: :ref:`CreationInfo <api-python-datamodel-creationinfo>`

      .. note::

         As this attribute is optional, this method throws a ValueError if
         the value of the attribute is not set.

   .. py:method:: add(setup)

      :param setup: Object of type :ref:`Setup <api-python-datamodel-setup>`
      :rtype: A Boolean value indicating success with True, False otherwise.

      Adds a Setup object to ConfigStation. The object is not
      copied but managed by this instance. Any change to the passed object
      will also change the child.

   .. py:method:: remove(setup)

      :param setup: Object of type :ref:`Setup <api-python-datamodel-setup>`
      :rtype: A Boolean value indicating success with True, False otherwise.

      Removes a previously added Setup object from ConfigStation.

   .. py:method:: removeSetup(idx)

      :param idx: An integer index of the object to be removed.
      :rtype: A Boolean value indicating success with True, False otherwise.

   .. py:method:: removeSetup(setupIndex);

      :param setupIndex: The index of the object to be removed of type SetupIndex.
      :rtype: A Boolean value indicating success with True, False otherwise.

   .. py:method:: setupCount()

      :rtype: integer value indicating the number of child objects.

      Returns the number of Setup child objects.

   .. py:method:: setup(idx)

      :param idx: An integer index of the object to be returned.
      :rtype: Object of type :ref:`Setup <api-python-datamodel-setup>`.

      Returns the Setup at index idx.

   .. py:method:: setup(setupIndex)

      :param setupIndex: The index of the object to be removed of type SetupIndex.
      :rtype: Object of type :ref:`Setup <api-python-datamodel-setup>`.

      Returns the Setup at given index. The indexes of all child objects
      are compared by value which makes this function slower than the direct
      integer index look-up.

   .. py:method:: configModule()

      :rtype: ConfigModule

      Returns the parent ConfigModule if available. Returns None
      if the parent is not a ConfigModule. This is a convenience wrapper
      for parent().

   .. py:method:: assign(other)

      This method implements the :ref:`Object <api-python-datamodel-object>` interface.

   .. py:method:: attachTo(parent)

      This method implements the :ref:`Object <api-python-datamodel-object>` interface.

   .. py:method:: detachFrom(parent)

      This method implements the :ref:`Object <api-python-datamodel-object>` interface.

   .. py:method:: detach()

      This method implements the :ref:`Object <api-python-datamodel-object>` interface.

   .. py:method:: clone()

      :rtype: A cloned ConfigStation.

      Returns a new instance that is a clone of the current instance. Child
      objects are being ignored.


   .. py:method:: updateChild(ref)

      :param ref: A child object derived from class Object.
      :rtype: A Boolean flag indicating success with True, False otherwise

      This method takes the passed reference object and searches for a child
      with the same publicID (if derived from :ref:`PublicObject <api-python-datamodel-publicobject>`)
      or the same index (if derived from :ref:`Object <api-python-datamodel-object>`).
      The the child was found the reference objects attributes are copied to
      the child object. Children of child are being ignored during this operation.
      This method implements the :ref:`PublicObject <api-python-datamodel-publicobject>` interface.


   .. py:method:: accept(visitor)

      :param visitor: A visitor.

      This method implements the :ref:`PublicObject <api-python-datamodel-publicobject>` interface.

.. _api-python-datamodel-creationinfo:

CreationInfo
............................................................

.. py:class:: CreationInfo

   Inherits :ref:`Object <api-python-datamodel-object>`.

   CreationInfo is used to describe creation metadata \(author, version, and
   creation time\) of a resource.

   **Attributes**:

   - ``agencyID`` -- string
   - ``agencyURI`` -- string
   - ``author`` -- string
   - ``authorURI`` -- string
   - ``creationTime`` -- seiscomp.core.Time (optional)
   - ``modificationTime`` -- seiscomp.core.Time (optional)
   - ``version`` -- string

   **Used by**:

   - :func:`Amplitude.creationInfo`
   - :func:`Arrival.creationInfo`
   - :func:`Comment.creationInfo`
   - :func:`ConfigStation.creationInfo`
   - :func:`Event.creationInfo`
   - :func:`FocalMechanism.creationInfo`
   - :func:`Magnitude.creationInfo`
   - :func:`MomentTensor.creationInfo`
   - :func:`Origin.creationInfo`
   - :func:`Pick.creationInfo`
   - :func:`StationMagnitude.creationInfo`

   **Methods**:

   .. py:staticmethod:: Cast(obj)

      :param obj: The object to be casted.
      :rtype: An object of type CreationInfo if the cast was successful,
              None otherwise.

      Cast an arbitrary object to CreationInfo if the internal wrapped
      representation is an CreationInfo object. The cast is important if
      instances of type :ref:`Object <api-python-datamodel-object>`
      are passed to methods which need access to the real type.



   .. py:method:: equal(other)

      :param other: Another object of type CreationInfo to compare this
                    instance to
      :rtype: A Boolean value indicating True if both objects are equal or
              False otherwise.

      Compares two objects without its child objects. Both objects are compared
      by value.

   .. py:method:: setAgencyID(agencyID)

      :param agencyID: string

      Designation of agency that published a resource. The string has a maximum
      length of 64 characters.

   .. py:method:: agencyID()

      :rtype: string

   .. py:method:: setAgencyURI(agencyURI)

      :param agencyURI: string

      RI of the agency that published a resource.

   .. py:method:: agencyURI()

      :rtype: string

   .. py:method:: setAuthor(author)

      :param author: string

      Name describing the author of a resource. The string has a maximum length of
      128 characters.

   .. py:method:: author()

      :rtype: string

   .. py:method:: setAuthorURI(authorURI)

      :param authorURI: string

      RI of the author of a resource.

   .. py:method:: authorURI()

      :rtype: string

   .. py:method:: setCreationTime(creationTime)

      :param creationTime: seiscomp.core.Time

      Time of creation of a resource, in ISO 8601 format. It has to be given in
      UTC.

   .. py:method:: creationTime()

      :rtype: seiscomp.core.Time

      .. note::

         As this attribute is optional, this method throws a ValueError if
         the value of the attribute is not set.

   .. py:method:: setModificationTime(modificationTime)

      :param modificationTime: seiscomp.core.Time

      Time of last modification of a resource, in ISO 8601 format. It has to be
      given in UTC.

   .. py:method:: modificationTime()

      :rtype: seiscomp.core.Time

      .. note::

         As this attribute is optional, this method throws a ValueError if
         the value of the attribute is not set.

   .. py:method:: setVersion(version)

      :param version: string

      Version string of a resource.

   .. py:method:: version()

      :rtype: string

.. _api-python-datamodel-dataattributeextent:

DataAttributeExtent
............................................................

.. py:class:: DataAttributeExtent

   Inherits :ref:`Object <api-python-datamodel-object>`.


   **Parents**:

   - ``dataExtent`` -- :ref:`DataExtent <api-python-datamodel-dataextent>`

   **Attributes**:

   - ``start`` -- seiscomp.core.Time
   - ``end`` -- seiscomp.core.Time
   - ``sampleRate`` -- double
   - ``quality`` -- string
   - ``updated`` -- seiscomp.core.Time
   - ``segmentCount`` -- int

   **Methods**:

   .. py:staticmethod:: Cast(obj)

      :param obj: The object to be casted.
      :rtype: An object of type DataAttributeExtent if the cast was successful,
              None otherwise.

      Cast an arbitrary object to DataAttributeExtent if the internal wrapped
      representation is an DataAttributeExtent object. The cast is important if
      instances of type :ref:`Object <api-python-datamodel-object>`
      are passed to methods which need access to the real type.



   .. py:method:: equal(other)

      :param other: Another object of type DataAttributeExtent to compare this
                    instance to
      :rtype: A Boolean value indicating True if both objects are equal or
              False otherwise.

      Compares two objects without its child objects. Both objects are compared
      by value.

   .. py:method:: index()

      :rtype: The object's index of type DataAttributeExtentIndex.

       Returns the objects index which is also used for the database as unique
       constraint.

   .. py:method:: equalIndex(lhs)

      :param lhs: :ref:`DataAttributeExtent <api-python-datamodel-dataattributeextent>`
      :rtype: A Boolean value indicating True if both indexes are equal or
              False otherwise.

   .. py:method:: setStart(start)

      :param start: seiscomp.core.Time

      Time of first sample of data attribute extent.

   .. py:method:: start()

      :rtype: seiscomp.core.Time

   .. py:method:: setEnd(end)

      :param end: seiscomp.core.Time

      Time after last sample of data attribute extent.

   .. py:method:: end()

      :rtype: seiscomp.core.Time

   .. py:method:: setSampleRate(sampleRate)

      :param sampleRate: double

      Sample rate of the current data attribute extent.

   .. py:method:: sampleRate()

      :rtype: double

   .. py:method:: setQuality(quality)

      :param quality: string

      Quality indicator of current data attribute extent.

   .. py:method:: quality()

      :rtype: string

   .. py:method:: setUpdated(updated)

      :param updated: seiscomp.core.Time

      The time of the last update or creation of this data attribute extent.

   .. py:method:: updated()

      :rtype: seiscomp.core.Time

   .. py:method:: setSegmentCount(segmentCount)

      :param segmentCount: int

      Number of data segments covered by this data attribute extent.

   .. py:method:: segmentCount()

      :rtype: int

   .. py:method:: dataExtent()

      :rtype: DataExtent

      Returns the parent DataExtent if available. Returns None
      if the parent is not a DataExtent. This is a convenience wrapper
      for parent().

   .. py:method:: assign(other)

      This method implements the :ref:`Object <api-python-datamodel-object>` interface.

   .. py:method:: attachTo(parent)

      This method implements the :ref:`Object <api-python-datamodel-object>` interface.

   .. py:method:: detachFrom(parent)

      This method implements the :ref:`Object <api-python-datamodel-object>` interface.

   .. py:method:: detach()

      This method implements the :ref:`Object <api-python-datamodel-object>` interface.

   .. py:method:: clone()

      :rtype: A cloned DataAttributeExtent.

      Returns a new instance that is a clone of the current instance. Child
      objects are being ignored.


   .. py:method:: accept(visitor)

      :param visitor: A visitor.

      This method implements the :ref:`PublicObject <api-python-datamodel-publicobject>` interface.

.. _api-python-datamodel-dataavailability:

DataAvailability
............................................................

.. py:class:: DataAvailability

   Inherits :ref:`PublicObject <api-python-datamodel-publicobject>`.

   This type can hold data availability related objects \(extent and segment\).

   **Children**:

   - ``dataExtent`` -- :ref:`DataExtent <api-python-datamodel-dataextent>`

   **Attributes**:

   - ``publicID``: string

   **Methods**:

   .. py:staticmethod:: Cast(obj)

      :param obj: The object to be casted.
      :rtype: An object of type DataAvailability if the cast was successful,
              None otherwise.

      Cast an arbitrary object to DataAvailability if the internal wrapped
      representation is an DataAvailability object. The cast is important if
      instances of type :ref:`Object <api-python-datamodel-object>`
      are passed to methods which need access to the real type.



   .. py:method:: equal(other)

      :param other: Another object of type DataAvailability to compare this
                    instance to
      :rtype: A Boolean value indicating True if both objects are equal or
              False otherwise.

      Compares two objects without its child objects. Both objects are compared
      by value.

   .. py:method:: add(dataExtent)

      :param dataExtent: Object of type :ref:`DataExtent <api-python-datamodel-dataextent>`
      :rtype: A Boolean value indicating success with True, False otherwise.

      Adds a DataExtent object to DataAvailability. The object is not
      copied but managed by this instance. Any change to the passed object
      will also change the child.

   .. py:method:: remove(dataExtent)

      :param dataExtent: Object of type :ref:`DataExtent <api-python-datamodel-dataextent>`
      :rtype: A Boolean value indicating success with True, False otherwise.

      Removes a previously added DataExtent object from DataAvailability.

   .. py:method:: removeDataExtent(idx)

      :param idx: An integer index of the object to be removed.
      :rtype: A Boolean value indicating success with True, False otherwise.

   .. py:method:: removeDataExtent(dataExtentIndex);

      :param dataExtentIndex: The index of the object to be removed of type DataExtentIndex.
      :rtype: A Boolean value indicating success with True, False otherwise.

   .. py:method:: dataExtentCount()

      :rtype: integer value indicating the number of child objects.

      Returns the number of DataExtent child objects.

   .. py:method:: dataExtent(idx)

      :param idx: An integer index of the object to be returned.
      :rtype: Object of type :ref:`DataExtent <api-python-datamodel-dataextent>`.

      Returns the DataExtent at index idx.

   .. py:method:: dataExtent(dataExtentIndex)

      :param dataExtentIndex: The index of the object to be removed of type DataExtentIndex.
      :rtype: Object of type :ref:`DataExtent <api-python-datamodel-dataextent>`.

      Returns the DataExtent at given index. The indexes of all child objects
      are compared by value which makes this function slower than the direct
      integer index look-up.

   .. py:method:: findDataExtent(publicID)

      :param publicID: The publicID of the object to find.
      :rtype: Object of type :ref:`DataExtent <api-python-datamodel-dataextent>`.

      Returns the child object with a certain publicID, None otherwise.

   .. py:method:: assign(other)

      This method implements the :ref:`Object <api-python-datamodel-object>` interface.

   .. py:method:: attachTo(parent)

      This method implements the :ref:`Object <api-python-datamodel-object>` interface.

   .. py:method:: detachFrom(parent)

      This method implements the :ref:`Object <api-python-datamodel-object>` interface.

   .. py:method:: detach()

      This method implements the :ref:`Object <api-python-datamodel-object>` interface.

   .. py:method:: clone()

      :rtype: A cloned DataAvailability.

      Returns a new instance that is a clone of the current instance. Child
      objects are being ignored.


   .. py:method:: updateChild(ref)

      :param ref: A child object derived from class Object.
      :rtype: A Boolean flag indicating success with True, False otherwise

      This method takes the passed reference object and searches for a child
      with the same publicID (if derived from :ref:`PublicObject <api-python-datamodel-publicobject>`)
      or the same index (if derived from :ref:`Object <api-python-datamodel-object>`).
      The the child was found the reference objects attributes are copied to
      the child object. Children of child are being ignored during this operation.
      This method implements the :ref:`PublicObject <api-python-datamodel-publicobject>` interface.


   .. py:method:: accept(visitor)

      :param visitor: A visitor.

      This method implements the :ref:`PublicObject <api-python-datamodel-publicobject>` interface.

.. _api-python-datamodel-dataextent:

DataExtent
............................................................

.. py:class:: DataExtent

   Inherits :ref:`PublicObject <api-python-datamodel-publicobject>`.


   **Parents**:

   - ``dataAvailability`` -- :ref:`DataAvailability <api-python-datamodel-dataavailability>`

   **Children**:

   - ``dataSegment`` -- :ref:`DataSegment <api-python-datamodel-datasegment>`
   - ``dataAttributeExtent`` -- :ref:`DataAttributeExtent <api-python-datamodel-dataattributeextent>`

   **Attributes**:

   - ``publicID``: string
   - ``waveformID`` -- :ref:`WaveformStreamID <api-python-datamodel-waveformstreamid>`
   - ``start`` -- seiscomp.core.Time
   - ``end`` -- seiscomp.core.Time
   - ``updated`` -- seiscomp.core.Time
   - ``lastScan`` -- seiscomp.core.Time
   - ``segmentOverflow`` -- boolean

   **Methods**:

   .. py:staticmethod:: Cast(obj)

      :param obj: The object to be casted.
      :rtype: An object of type DataExtent if the cast was successful,
              None otherwise.

      Cast an arbitrary object to DataExtent if the internal wrapped
      representation is an DataExtent object. The cast is important if
      instances of type :ref:`Object <api-python-datamodel-object>`
      are passed to methods which need access to the real type.



   .. py:staticmethod:: Create()

      :rtype: A new object of type DataExtent.

      Creates and registers (if enabled) a DataExtent instance. The
      publicID is auto-generated.

   .. py:staticmethod:: Create(publicID)

      :rtype: A new object of type DataExtent.

      Creates and registers (if enabled) a DataExtent instance with
      passed publicID.

   .. py:method:: equal(other)

      :param other: Another object of type DataExtent to compare this
                    instance to
      :rtype: A Boolean value indicating True if both objects are equal or
              False otherwise.

      Compares two objects without its child objects. Both objects are compared
      by value.

   .. py:method:: index()

      :rtype: The object's index of type DataExtentIndex.

       Returns the objects index which is also used for the database as unique
       constraint.

   .. py:method:: equalIndex(lhs)

      :param lhs: :ref:`DataExtent <api-python-datamodel-dataextent>`
      :rtype: A Boolean value indicating True if both indexes are equal or
              False otherwise.

   .. py:method:: setWaveformID(waveformID)

      :param waveformID: :ref:`WaveformStreamID <api-python-datamodel-waveformstreamid>`

   .. py:method:: waveformID()

      :rtype: :ref:`WaveformStreamID <api-python-datamodel-waveformstreamid>`

   .. py:method:: setStart(start)

      :param start: seiscomp.core.Time

      Time of first sample of data available

   .. py:method:: start()

      :rtype: seiscomp.core.Time

   .. py:method:: setEnd(end)

      :param end: seiscomp.core.Time

      Time after last sample of data available

   .. py:method:: end()

      :rtype: seiscomp.core.Time

   .. py:method:: setUpdated(updated)

      :param updated: seiscomp.core.Time

      The time of the last update or creation of this segment

   .. py:method:: updated()

      :rtype: seiscomp.core.Time

   .. py:method:: setLastScan(lastScan)

      :param lastScan: seiscomp.core.Time

      The time of the last waveform archive scan

   .. py:method:: lastScan()

      :rtype: seiscomp.core.Time

   .. py:method:: setSegmentOverflow(segmentOverflow)

      :param segmentOverflow: boolean

      Flags the stream to be to fragmented for processing.

   .. py:method:: segmentOverflow()

      :rtype: boolean

   .. py:method:: add(dataSegment)

      :param dataSegment: Object of type :ref:`DataSegment <api-python-datamodel-datasegment>`
      :rtype: A Boolean value indicating success with True, False otherwise.

      Adds a DataSegment object to DataExtent. The object is not
      copied but managed by this instance. Any change to the passed object
      will also change the child.

   .. py:method:: add(dataAttributeExtent)

      :param dataAttributeExtent: Object of type :ref:`DataAttributeExtent <api-python-datamodel-dataattributeextent>`
      :rtype: A Boolean value indicating success with True, False otherwise.

      Adds a DataAttributeExtent object to DataExtent. The object is not
      copied but managed by this instance. Any change to the passed object
      will also change the child.

   .. py:method:: remove(dataSegment)

      :param dataSegment: Object of type :ref:`DataSegment <api-python-datamodel-datasegment>`
      :rtype: A Boolean value indicating success with True, False otherwise.

      Removes a previously added DataSegment object from DataExtent.

   .. py:method:: remove(dataAttributeExtent)

      :param dataAttributeExtent: Object of type :ref:`DataAttributeExtent <api-python-datamodel-dataattributeextent>`
      :rtype: A Boolean value indicating success with True, False otherwise.

      Removes a previously added DataAttributeExtent object from DataExtent.

   .. py:method:: removeDataSegment(idx)

      :param idx: An integer index of the object to be removed.
      :rtype: A Boolean value indicating success with True, False otherwise.

   .. py:method:: removeDataSegment(dataSegmentIndex);

      :param dataSegmentIndex: The index of the object to be removed of type DataSegmentIndex.
      :rtype: A Boolean value indicating success with True, False otherwise.

   .. py:method:: removeDataAttributeExtent(idx)

      :param idx: An integer index of the object to be removed.
      :rtype: A Boolean value indicating success with True, False otherwise.

   .. py:method:: removeDataAttributeExtent(dataAttributeExtentIndex);

      :param dataAttributeExtentIndex: The index of the object to be removed of type DataAttributeExtentIndex.
      :rtype: A Boolean value indicating success with True, False otherwise.

   .. py:method:: dataSegmentCount()

      :rtype: integer value indicating the number of child objects.

      Returns the number of DataSegment child objects.

   .. py:method:: dataAttributeExtentCount()

      :rtype: integer value indicating the number of child objects.

      Returns the number of DataAttributeExtent child objects.

   .. py:method:: dataSegment(idx)

      :param idx: An integer index of the object to be returned.
      :rtype: Object of type :ref:`DataSegment <api-python-datamodel-datasegment>`.

      Returns the DataSegment at index idx.

   .. py:method:: dataSegment(dataSegmentIndex)

      :param dataSegmentIndex: The index of the object to be removed of type DataSegmentIndex.
      :rtype: Object of type :ref:`DataSegment <api-python-datamodel-datasegment>`.

      Returns the DataSegment at given index. The indexes of all child objects
      are compared by value which makes this function slower than the direct
      integer index look-up.

   .. py:method:: dataAttributeExtent(idx)

      :param idx: An integer index of the object to be returned.
      :rtype: Object of type :ref:`DataAttributeExtent <api-python-datamodel-dataattributeextent>`.

      Returns the DataAttributeExtent at index idx.

   .. py:method:: dataAttributeExtent(dataAttributeExtentIndex)

      :param dataAttributeExtentIndex: The index of the object to be removed of type DataAttributeExtentIndex.
      :rtype: Object of type :ref:`DataAttributeExtent <api-python-datamodel-dataattributeextent>`.

      Returns the DataAttributeExtent at given index. The indexes of all child objects
      are compared by value which makes this function slower than the direct
      integer index look-up.

   .. py:method:: dataAvailability()

      :rtype: DataAvailability

      Returns the parent DataAvailability if available. Returns None
      if the parent is not a DataAvailability. This is a convenience wrapper
      for parent().

   .. py:method:: assign(other)

      This method implements the :ref:`Object <api-python-datamodel-object>` interface.

   .. py:method:: attachTo(parent)

      This method implements the :ref:`Object <api-python-datamodel-object>` interface.

   .. py:method:: detachFrom(parent)

      This method implements the :ref:`Object <api-python-datamodel-object>` interface.

   .. py:method:: detach()

      This method implements the :ref:`Object <api-python-datamodel-object>` interface.

   .. py:method:: clone()

      :rtype: A cloned DataExtent.

      Returns a new instance that is a clone of the current instance. Child
      objects are being ignored.


   .. py:method:: updateChild(ref)

      :param ref: A child object derived from class Object.
      :rtype: A Boolean flag indicating success with True, False otherwise

      This method takes the passed reference object and searches for a child
      with the same publicID (if derived from :ref:`PublicObject <api-python-datamodel-publicobject>`)
      or the same index (if derived from :ref:`Object <api-python-datamodel-object>`).
      The the child was found the reference objects attributes are copied to
      the child object. Children of child are being ignored during this operation.
      This method implements the :ref:`PublicObject <api-python-datamodel-publicobject>` interface.


   .. py:method:: accept(visitor)

      :param visitor: A visitor.

      This method implements the :ref:`PublicObject <api-python-datamodel-publicobject>` interface.

.. _api-python-datamodel-datasegment:

DataSegment
............................................................

.. py:class:: DataSegment

   Inherits :ref:`Object <api-python-datamodel-object>`.


   **Parents**:

   - ``dataExtent`` -- :ref:`DataExtent <api-python-datamodel-dataextent>`

   **Attributes**:

   - ``start`` -- seiscomp.core.Time
   - ``end`` -- seiscomp.core.Time
   - ``updated`` -- seiscomp.core.Time
   - ``sampleRate`` -- double
   - ``quality`` -- string
   - ``outOfOrder`` -- boolean

   **Methods**:

   .. py:staticmethod:: Cast(obj)

      :param obj: The object to be casted.
      :rtype: An object of type DataSegment if the cast was successful,
              None otherwise.

      Cast an arbitrary object to DataSegment if the internal wrapped
      representation is an DataSegment object. The cast is important if
      instances of type :ref:`Object <api-python-datamodel-object>`
      are passed to methods which need access to the real type.



   .. py:method:: equal(other)

      :param other: Another object of type DataSegment to compare this
                    instance to
      :rtype: A Boolean value indicating True if both objects are equal or
              False otherwise.

      Compares two objects without its child objects. Both objects are compared
      by value.

   .. py:method:: index()

      :rtype: The object's index of type DataSegmentIndex.

       Returns the objects index which is also used for the database as unique
       constraint.

   .. py:method:: equalIndex(lhs)

      :param lhs: :ref:`DataSegment <api-python-datamodel-datasegment>`
      :rtype: A Boolean value indicating True if both indexes are equal or
              False otherwise.

   .. py:method:: setStart(start)

      :param start: seiscomp.core.Time

      Time of first sample of data segment.

   .. py:method:: start()

      :rtype: seiscomp.core.Time

   .. py:method:: setEnd(end)

      :param end: seiscomp.core.Time

      Time after last sample of data segment.

   .. py:method:: end()

      :rtype: seiscomp.core.Time

   .. py:method:: setUpdated(updated)

      :param updated: seiscomp.core.Time

      The time of the last update or creation of this data segment.

   .. py:method:: updated()

      :rtype: seiscomp.core.Time

   .. py:method:: setSampleRate(sampleRate)

      :param sampleRate: double

      Sample rate of the current data segment.

   .. py:method:: sampleRate()

      :rtype: double

   .. py:method:: setQuality(quality)

      :param quality: string

      Quality indicator of current data segment.

   .. py:method:: quality()

      :rtype: string

   .. py:method:: setOutOfOrder(outOfOrder)

      :param outOfOrder: boolean

      Whether this segment is an out\-of\-order segment or not.

   .. py:method:: outOfOrder()

      :rtype: boolean

   .. py:method:: dataExtent()

      :rtype: DataExtent

      Returns the parent DataExtent if available. Returns None
      if the parent is not a DataExtent. This is a convenience wrapper
      for parent().

   .. py:method:: assign(other)

      This method implements the :ref:`Object <api-python-datamodel-object>` interface.

   .. py:method:: attachTo(parent)

      This method implements the :ref:`Object <api-python-datamodel-object>` interface.

   .. py:method:: detachFrom(parent)

      This method implements the :ref:`Object <api-python-datamodel-object>` interface.

   .. py:method:: detach()

      This method implements the :ref:`Object <api-python-datamodel-object>` interface.

   .. py:method:: clone()

      :rtype: A cloned DataSegment.

      Returns a new instance that is a clone of the current instance. Child
      objects are being ignored.


   .. py:method:: accept(visitor)

      :param visitor: A visitor.

      This method implements the :ref:`PublicObject <api-python-datamodel-publicobject>` interface.

.. _api-python-datamodel-dataused:

DataUsed
............................................................

.. py:class:: DataUsed

   Inherits :ref:`Object <api-python-datamodel-object>`.

   The DataUsed class describes the type of data that has been used for a
   moment\-tensor inversion.

   **Parents**:

   - ``momentTensor`` -- :ref:`MomentTensor <api-python-datamodel-momenttensor>`

   **Attributes**:

   - ``waveType`` -- :ref:`DataUsedWaveType <api-python-datamodel-datausedwavetype>`
   - ``stationCount`` -- int
   - ``componentCount`` -- int
   - ``shortestPeriod`` -- float (optional)

   **Methods**:

   .. py:staticmethod:: Cast(obj)

      :param obj: The object to be casted.
      :rtype: An object of type DataUsed if the cast was successful,
              None otherwise.

      Cast an arbitrary object to DataUsed if the internal wrapped
      representation is an DataUsed object. The cast is important if
      instances of type :ref:`Object <api-python-datamodel-object>`
      are passed to methods which need access to the real type.



   .. py:method:: equal(other)

      :param other: Another object of type DataUsed to compare this
                    instance to
      :rtype: A Boolean value indicating True if both objects are equal or
              False otherwise.

      Compares two objects without its child objects. Both objects are compared
      by value.

   .. py:method:: setWaveType(waveType)

      :param waveType: DataUsedWaveType

      Type of waveform data.

   .. py:method:: waveType()

      :rtype: DataUsedWaveType

   .. py:method:: setStationCount(stationCount)

      :param stationCount: int

      Number of stations that have contributed data of the type given in waveType.

   .. py:method:: stationCount()

      :rtype: int

   .. py:method:: setComponentCount(componentCount)

      :param componentCount: int

      Number of data components of the type given in waveType.

   .. py:method:: componentCount()

      :rtype: int

   .. py:method:: setShortestPeriod(shortestPeriod)

      :param shortestPeriod: float

      Shortest period present in data in seconds.

   .. py:method:: shortestPeriod()

      :rtype: float

      .. note::

         As this attribute is optional, this method throws a ValueError if
         the value of the attribute is not set.

   .. py:method:: momentTensor()

      :rtype: MomentTensor

      Returns the parent MomentTensor if available. Returns None
      if the parent is not a MomentTensor. This is a convenience wrapper
      for parent().

   .. py:method:: assign(other)

      This method implements the :ref:`Object <api-python-datamodel-object>` interface.

   .. py:method:: attachTo(parent)

      This method implements the :ref:`Object <api-python-datamodel-object>` interface.

   .. py:method:: detachFrom(parent)

      This method implements the :ref:`Object <api-python-datamodel-object>` interface.

   .. py:method:: detach()

      This method implements the :ref:`Object <api-python-datamodel-object>` interface.

   .. py:method:: clone()

      :rtype: A cloned DataUsed.

      Returns a new instance that is a clone of the current instance. Child
      objects are being ignored.


   .. py:method:: accept(visitor)

      :param visitor: A visitor.

      This method implements the :ref:`PublicObject <api-python-datamodel-publicobject>` interface.

.. _api-python-datamodel-datalogger:

Datalogger
............................................................

.. py:class:: Datalogger

   Inherits :ref:`PublicObject <api-python-datamodel-publicobject>`.

   This type describes a datalogger \(digitizer and recorder\)

   **Parents**:

   - ``inventory`` -- :ref:`Inventory <api-python-datamodel-inventory>`

   **Children**:

   - ``dataloggerCalibration`` -- :ref:`DataloggerCalibration <api-python-datamodel-dataloggercalibration>`
   - ``decimation`` -- :ref:`Decimation <api-python-datamodel-decimation>`

   **Attributes**:

   - ``publicID``: string
   - ``name`` -- string
   - ``description`` -- string
   - ``digitizerModel`` -- string
   - ``digitizerManufacturer`` -- string
   - ``recorderModel`` -- string
   - ``recorderManufacturer`` -- string
   - ``clockModel`` -- string
   - ``clockManufacturer`` -- string
   - ``clockType`` -- string
   - ``gain`` -- float (optional)
   - ``maxClockDrift`` -- float (optional)
   - ``remark`` -- :ref:`Blob <api-python-datamodel-blob>` (optional)

   **Referenced by**:

   - :func:`Stream.datalogger`

   **Methods**:

   .. py:staticmethod:: Cast(obj)

      :param obj: The object to be casted.
      :rtype: An object of type Datalogger if the cast was successful,
              None otherwise.

      Cast an arbitrary object to Datalogger if the internal wrapped
      representation is an Datalogger object. The cast is important if
      instances of type :ref:`Object <api-python-datamodel-object>`
      are passed to methods which need access to the real type.



   .. py:staticmethod:: Create()

      :rtype: A new object of type Datalogger.

      Creates and registers (if enabled) a Datalogger instance. The
      publicID is auto-generated.

   .. py:staticmethod:: Create(publicID)

      :rtype: A new object of type Datalogger.

      Creates and registers (if enabled) a Datalogger instance with
      passed publicID.

   .. py:method:: equal(other)

      :param other: Another object of type Datalogger to compare this
                    instance to
      :rtype: A Boolean value indicating True if both objects are equal or
              False otherwise.

      Compares two objects without its child objects. Both objects are compared
      by value.

   .. py:method:: index()

      :rtype: The object's index of type DataloggerIndex.

       Returns the objects index which is also used for the database as unique
       constraint.

   .. py:method:: equalIndex(lhs)

      :param lhs: :ref:`Datalogger <api-python-datamodel-datalogger>`
      :rtype: A Boolean value indicating True if both indexes are equal or
              False otherwise.

   .. py:method:: setName(name)

      :param name: string

      Unique datalogger name

   .. py:method:: name()

      :rtype: string

   .. py:method:: setDescription(description)

      :param description: string

      Datalogger description

   .. py:method:: description()

      :rtype: string

   .. py:method:: setDigitizerModel(digitizerModel)

      :param digitizerModel: string

      Digitizer model

   .. py:method:: digitizerModel()

      :rtype: string

   .. py:method:: setDigitizerManufacturer(digitizerManufacturer)

      :param digitizerManufacturer: string

      Digitizer manufacturer

   .. py:method:: digitizerManufacturer()

      :rtype: string

   .. py:method:: setRecorderModel(recorderModel)

      :param recorderModel: string

      Recorder model

   .. py:method:: recorderModel()

      :rtype: string

   .. py:method:: setRecorderManufacturer(recorderManufacturer)

      :param recorderManufacturer: string

      Recorder manufacturer

   .. py:method:: recorderManufacturer()

      :rtype: string

   .. py:method:: setClockModel(clockModel)

      :param clockModel: string

      Clock model \(mostly unused\)

   .. py:method:: clockModel()

      :rtype: string

   .. py:method:: setClockManufacturer(clockManufacturer)

      :param clockManufacturer: string

      Clock manufacturer \(mostly unused\)

   .. py:method:: clockManufacturer()

      :rtype: string

   .. py:method:: setClockType(clockType)

      :param clockType: string

      Clock type \(mostly unused\)

   .. py:method:: clockType()

      :rtype: string

   .. py:method:: setGain(gain)

      :param gain: float

      Sensitivity of digitizer, counts\/V \(48.05\/58.04\)

   .. py:method:: gain()

      :rtype: float

      .. note::

         As this attribute is optional, this method throws a ValueError if
         the value of the attribute is not set.

   .. py:method:: setMaxClockDrift(maxClockDrift)

      :param maxClockDrift: float

      Max clock drift, seconds\/second \(not identical to 52.19, which is
      seconds\/sample\)

   .. py:method:: maxClockDrift()

      :rtype: float

      .. note::

         As this attribute is optional, this method throws a ValueError if
         the value of the attribute is not set.

   .. py:method:: setRemark(remark)

      :param remark: :ref:`Blob <api-python-datamodel-blob>`

   .. py:method:: remark()

      :rtype: :ref:`Blob <api-python-datamodel-blob>`

      .. note::

         As this attribute is optional, this method throws a ValueError if
         the value of the attribute is not set.

   .. py:method:: add(dataloggerCalibration)

      :param dataloggerCalibration: Object of type :ref:`DataloggerCalibration <api-python-datamodel-dataloggercalibration>`
      :rtype: A Boolean value indicating success with True, False otherwise.

      Adds a DataloggerCalibration object to Datalogger. The object is not
      copied but managed by this instance. Any change to the passed object
      will also change the child.

   .. py:method:: add(decimation)

      :param decimation: Object of type :ref:`Decimation <api-python-datamodel-decimation>`
      :rtype: A Boolean value indicating success with True, False otherwise.

      Adds a Decimation object to Datalogger. The object is not
      copied but managed by this instance. Any change to the passed object
      will also change the child.

   .. py:method:: remove(dataloggerCalibration)

      :param dataloggerCalibration: Object of type :ref:`DataloggerCalibration <api-python-datamodel-dataloggercalibration>`
      :rtype: A Boolean value indicating success with True, False otherwise.

      Removes a previously added DataloggerCalibration object from Datalogger.

   .. py:method:: remove(decimation)

      :param decimation: Object of type :ref:`Decimation <api-python-datamodel-decimation>`
      :rtype: A Boolean value indicating success with True, False otherwise.

      Removes a previously added Decimation object from Datalogger.

   .. py:method:: removeDataloggerCalibration(idx)

      :param idx: An integer index of the object to be removed.
      :rtype: A Boolean value indicating success with True, False otherwise.

   .. py:method:: removeDataloggerCalibration(dataloggerCalibrationIndex);

      :param dataloggerCalibrationIndex: The index of the object to be removed of type DataloggerCalibrationIndex.
      :rtype: A Boolean value indicating success with True, False otherwise.

   .. py:method:: removeDecimation(idx)

      :param idx: An integer index of the object to be removed.
      :rtype: A Boolean value indicating success with True, False otherwise.

   .. py:method:: removeDecimation(decimationIndex);

      :param decimationIndex: The index of the object to be removed of type DecimationIndex.
      :rtype: A Boolean value indicating success with True, False otherwise.

   .. py:method:: dataloggerCalibrationCount()

      :rtype: integer value indicating the number of child objects.

      Returns the number of DataloggerCalibration child objects.

   .. py:method:: decimationCount()

      :rtype: integer value indicating the number of child objects.

      Returns the number of Decimation child objects.

   .. py:method:: dataloggerCalibration(idx)

      :param idx: An integer index of the object to be returned.
      :rtype: Object of type :ref:`DataloggerCalibration <api-python-datamodel-dataloggercalibration>`.

      Returns the DataloggerCalibration at index idx.

   .. py:method:: dataloggerCalibration(dataloggerCalibrationIndex)

      :param dataloggerCalibrationIndex: The index of the object to be removed of type DataloggerCalibrationIndex.
      :rtype: Object of type :ref:`DataloggerCalibration <api-python-datamodel-dataloggercalibration>`.

      Returns the DataloggerCalibration at given index. The indexes of all child objects
      are compared by value which makes this function slower than the direct
      integer index look-up.

   .. py:method:: decimation(idx)

      :param idx: An integer index of the object to be returned.
      :rtype: Object of type :ref:`Decimation <api-python-datamodel-decimation>`.

      Returns the Decimation at index idx.

   .. py:method:: decimation(decimationIndex)

      :param decimationIndex: The index of the object to be removed of type DecimationIndex.
      :rtype: Object of type :ref:`Decimation <api-python-datamodel-decimation>`.

      Returns the Decimation at given index. The indexes of all child objects
      are compared by value which makes this function slower than the direct
      integer index look-up.

   .. py:method:: inventory()

      :rtype: Inventory

      Returns the parent Inventory if available. Returns None
      if the parent is not a Inventory. This is a convenience wrapper
      for parent().

   .. py:method:: assign(other)

      This method implements the :ref:`Object <api-python-datamodel-object>` interface.

   .. py:method:: attachTo(parent)

      This method implements the :ref:`Object <api-python-datamodel-object>` interface.

   .. py:method:: detachFrom(parent)

      This method implements the :ref:`Object <api-python-datamodel-object>` interface.

   .. py:method:: detach()

      This method implements the :ref:`Object <api-python-datamodel-object>` interface.

   .. py:method:: clone()

      :rtype: A cloned Datalogger.

      Returns a new instance that is a clone of the current instance. Child
      objects are being ignored.


   .. py:method:: updateChild(ref)

      :param ref: A child object derived from class Object.
      :rtype: A Boolean flag indicating success with True, False otherwise

      This method takes the passed reference object and searches for a child
      with the same publicID (if derived from :ref:`PublicObject <api-python-datamodel-publicobject>`)
      or the same index (if derived from :ref:`Object <api-python-datamodel-object>`).
      The the child was found the reference objects attributes are copied to
      the child object. Children of child are being ignored during this operation.
      This method implements the :ref:`PublicObject <api-python-datamodel-publicobject>` interface.


   .. py:method:: accept(visitor)

      :param visitor: A visitor.

      This method implements the :ref:`PublicObject <api-python-datamodel-publicobject>` interface.

.. _api-python-datamodel-dataloggercalibration:

DataloggerCalibration
............................................................

.. py:class:: DataloggerCalibration

   Inherits :ref:`Object <api-python-datamodel-object>`.

   This type describes a datalogger calibration

   **Parents**:

   - ``datalogger`` -- :ref:`Datalogger <api-python-datamodel-datalogger>`

   **Attributes**:

   - ``serialNumber`` -- string
   - ``channel`` -- int
   - ``start`` -- seiscomp.core.Time
   - ``end`` -- seiscomp.core.Time (optional)
   - ``gain`` -- float (optional)
   - ``gainFrequency`` -- float (optional)
   - ``remark`` -- :ref:`Blob <api-python-datamodel-blob>` (optional)

   **Methods**:

   .. py:staticmethod:: Cast(obj)

      :param obj: The object to be casted.
      :rtype: An object of type DataloggerCalibration if the cast was successful,
              None otherwise.

      Cast an arbitrary object to DataloggerCalibration if the internal wrapped
      representation is an DataloggerCalibration object. The cast is important if
      instances of type :ref:`Object <api-python-datamodel-object>`
      are passed to methods which need access to the real type.



   .. py:method:: equal(other)

      :param other: Another object of type DataloggerCalibration to compare this
                    instance to
      :rtype: A Boolean value indicating True if both objects are equal or
              False otherwise.

      Compares two objects without its child objects. Both objects are compared
      by value.

   .. py:method:: index()

      :rtype: The object's index of type DataloggerCalibrationIndex.

       Returns the objects index which is also used for the database as unique
       constraint.

   .. py:method:: equalIndex(lhs)

      :param lhs: :ref:`DataloggerCalibration <api-python-datamodel-dataloggercalibration>`
      :rtype: A Boolean value indicating True if both indexes are equal or
              False otherwise.

   .. py:method:: setSerialNumber(serialNumber)

      :param serialNumber: string

      Referred from network\/station\/Stream\/\@dataloggerSerialNumber

   .. py:method:: serialNumber()

      :rtype: string

   .. py:method:: setChannel(channel)

      :param channel: int

      Referred from network\/station\/Stream\/\@dataloggerChannel

   .. py:method:: channel()

      :rtype: int

   .. py:method:: setStart(start)

      :param start: seiscomp.core.Time

      Start of validity

   .. py:method:: start()

      :rtype: seiscomp.core.Time

   .. py:method:: setEnd(end)

      :param end: seiscomp.core.Time

      End of validity

   .. py:method:: end()

      :rtype: seiscomp.core.Time

      .. note::

         As this attribute is optional, this method throws a ValueError if
         the value of the attribute is not set.

   .. py:method:: setGain(gain)

      :param gain: float

      Overrides nominal gain of calibrated datalogger \(48.05\/58.04\)

   .. py:method:: gain()

      :rtype: float

      .. note::

         As this attribute is optional, this method throws a ValueError if
         the value of the attribute is not set.

   .. py:method:: setGainFrequency(gainFrequency)

      :param gainFrequency: float

      Gain frequency \(48.06\/58.05\)

   .. py:method:: gainFrequency()

      :rtype: float

      .. note::

         As this attribute is optional, this method throws a ValueError if
         the value of the attribute is not set.

   .. py:method:: setRemark(remark)

      :param remark: :ref:`Blob <api-python-datamodel-blob>`

   .. py:method:: remark()

      :rtype: :ref:`Blob <api-python-datamodel-blob>`

      .. note::

         As this attribute is optional, this method throws a ValueError if
         the value of the attribute is not set.

   .. py:method:: datalogger()

      :rtype: Datalogger

      Returns the parent Datalogger if available. Returns None
      if the parent is not a Datalogger. This is a convenience wrapper
      for parent().

   .. py:method:: assign(other)

      This method implements the :ref:`Object <api-python-datamodel-object>` interface.

   .. py:method:: attachTo(parent)

      This method implements the :ref:`Object <api-python-datamodel-object>` interface.

   .. py:method:: detachFrom(parent)

      This method implements the :ref:`Object <api-python-datamodel-object>` interface.

   .. py:method:: detach()

      This method implements the :ref:`Object <api-python-datamodel-object>` interface.

   .. py:method:: clone()

      :rtype: A cloned DataloggerCalibration.

      Returns a new instance that is a clone of the current instance. Child
      objects are being ignored.


   .. py:method:: accept(visitor)

      :param visitor: A visitor.

      This method implements the :ref:`PublicObject <api-python-datamodel-publicobject>` interface.

.. _api-python-datamodel-decimation:

Decimation
............................................................

.. py:class:: Decimation

   Inherits :ref:`Object <api-python-datamodel-object>`.

   This type describes a decimation to a certain sample rate

   **Parents**:

   - ``datalogger`` -- :ref:`Datalogger <api-python-datamodel-datalogger>`

   **Attributes**:

   - ``sampleRateNumerator`` -- int
   - ``sampleRateDenominator`` -- int
   - ``analogueFilterChain`` -- :ref:`Blob <api-python-datamodel-blob>` (optional)
   - ``digitalFilterChain`` -- :ref:`Blob <api-python-datamodel-blob>` (optional)

   **Methods**:

   .. py:staticmethod:: Cast(obj)

      :param obj: The object to be casted.
      :rtype: An object of type Decimation if the cast was successful,
              None otherwise.

      Cast an arbitrary object to Decimation if the internal wrapped
      representation is an Decimation object. The cast is important if
      instances of type :ref:`Object <api-python-datamodel-object>`
      are passed to methods which need access to the real type.



   .. py:method:: equal(other)

      :param other: Another object of type Decimation to compare this
                    instance to
      :rtype: A Boolean value indicating True if both objects are equal or
              False otherwise.

      Compares two objects without its child objects. Both objects are compared
      by value.

   .. py:method:: index()

      :rtype: The object's index of type DecimationIndex.

       Returns the objects index which is also used for the database as unique
       constraint.

   .. py:method:: equalIndex(lhs)

      :param lhs: :ref:`Decimation <api-python-datamodel-decimation>`
      :rtype: A Boolean value indicating True if both indexes are equal or
              False otherwise.

   .. py:method:: setSampleRateNumerator(sampleRateNumerator)

      :param sampleRateNumerator: int

      Output sample rate \(numerator\); referred from
      network\/station\/Stream\/\@sampleRateNumerator

   .. py:method:: sampleRateNumerator()

      :rtype: int

   .. py:method:: setSampleRateDenominator(sampleRateDenominator)

      :param sampleRateDenominator: int

      Output sample rate \(denominator\); referred from
      network\/station\/Stream\/\@sampleRateDenominator

   .. py:method:: sampleRateDenominator()

      :rtype: int

   .. py:method:: setAnalogueFilterChain(analogueFilterChain)

      :param analogueFilterChain: :ref:`Blob <api-python-datamodel-blob>`

      Specifies analogue filters between seismometer and digitizer. Each element
      \(separated by space\) references responsePAZ\/\@publicID

   .. py:method:: analogueFilterChain()

      :rtype: :ref:`Blob <api-python-datamodel-blob>`

      .. note::

         As this attribute is optional, this method throws a ValueError if
         the value of the attribute is not set.

   .. py:method:: setDigitalFilterChain(digitalFilterChain)

      :param digitalFilterChain: :ref:`Blob <api-python-datamodel-blob>`

      Specifies digital filters \(decimation, gain removal\). Each element
      \(separated by space\) references responsePAZ\@publicID or
      responseFIR\/\@publicID

   .. py:method:: digitalFilterChain()

      :rtype: :ref:`Blob <api-python-datamodel-blob>`

      .. note::

         As this attribute is optional, this method throws a ValueError if
         the value of the attribute is not set.

   .. py:method:: datalogger()

      :rtype: Datalogger

      Returns the parent Datalogger if available. Returns None
      if the parent is not a Datalogger. This is a convenience wrapper
      for parent().

   .. py:method:: assign(other)

      This method implements the :ref:`Object <api-python-datamodel-object>` interface.

   .. py:method:: attachTo(parent)

      This method implements the :ref:`Object <api-python-datamodel-object>` interface.

   .. py:method:: detachFrom(parent)

      This method implements the :ref:`Object <api-python-datamodel-object>` interface.

   .. py:method:: detach()

      This method implements the :ref:`Object <api-python-datamodel-object>` interface.

   .. py:method:: clone()

      :rtype: A cloned Decimation.

      Returns a new instance that is a clone of the current instance. Child
      objects are being ignored.


   .. py:method:: accept(visitor)

      :param visitor: A visitor.

      This method implements the :ref:`PublicObject <api-python-datamodel-publicobject>` interface.

.. _api-python-datamodel-event:

Event
............................................................

.. py:class:: Event

   Inherits :ref:`PublicObject <api-python-datamodel-publicobject>`.

   The class Event describes a seismic event which does not necessarily need
   to be a tectonic earthquake. An event is usually associated with one or
   more origins, which contain information about focal time and geographical
   location of the event. Multiple origins can cover automatic and manual
   locations, a set of location from different agencies, locations generated
   with different location programs and earth models, etc. Furthermore, an event
   is usually associated with one or more magnitudes, and with one or more focal
   mechanism determinations.

   **Parents**:

   - ``eventParameters`` -- :ref:`EventParameters <api-python-datamodel-eventparameters>`

   **Children**:

   - ``eventDescription`` -- :ref:`EventDescription <api-python-datamodel-eventdescription>`
   - ``comment`` -- :ref:`Comment <api-python-datamodel-comment>`
   - ``originReference`` -- :ref:`OriginReference <api-python-datamodel-originreference>`
   - ``focalMechanismReference`` -- :ref:`FocalMechanismReference <api-python-datamodel-focalmechanismreference>`

   **Attributes**:

   - ``publicID``: string
   - ``preferredOriginID`` -- string
   - ``preferredMagnitudeID`` -- string
   - ``preferredFocalMechanismID`` -- string
   - ``type`` -- :ref:`EventType <api-python-datamodel-eventtype>` (optional)
   - ``typeCertainty`` -- :ref:`EventTypeCertainty <api-python-datamodel-eventtypecertainty>` (optional)
   - ``creationInfo`` -- :ref:`CreationInfo <api-python-datamodel-creationinfo>` (optional)

   **Methods**:

   .. py:staticmethod:: Cast(obj)

      :param obj: The object to be casted.
      :rtype: An object of type Event if the cast was successful,
              None otherwise.

      Cast an arbitrary object to Event if the internal wrapped
      representation is an Event object. The cast is important if
      instances of type :ref:`Object <api-python-datamodel-object>`
      are passed to methods which need access to the real type.



   .. py:staticmethod:: Create()

      :rtype: A new object of type Event.

      Creates and registers (if enabled) a Event instance. The
      publicID is auto-generated.

   .. py:staticmethod:: Create(publicID)

      :rtype: A new object of type Event.

      Creates and registers (if enabled) a Event instance with
      passed publicID.

   .. py:method:: equal(other)

      :param other: Another object of type Event to compare this
                    instance to
      :rtype: A Boolean value indicating True if both objects are equal or
              False otherwise.

      Compares two objects without its child objects. Both objects are compared
      by value.

   .. py:method:: setPreferredOriginID(preferredOriginID)

      :param preferredOriginID: string

      Refers to the publicID of the preferred Origin object.

   .. py:method:: preferredOriginID()

      :rtype: string

   .. py:method:: setPreferredMagnitudeID(preferredMagnitudeID)

      :param preferredMagnitudeID: string

      Refers to the publicID of the preferred Magnitude object.

   .. py:method:: preferredMagnitudeID()

      :rtype: string

   .. py:method:: setPreferredFocalMechanismID(preferredFocalMechanismID)

      :param preferredFocalMechanismID: string

      Refers to the publicID of the preferred FocalMechanism object.

   .. py:method:: preferredFocalMechanismID()

      :rtype: string

   .. py:method:: setType(type)

      :param type: EventType

      Describes the type of an event \(Storchak et al. 2012\).

   .. py:method:: type()

      :rtype: EventType

      .. note::

         As this attribute is optional, this method throws a ValueError if
         the value of the attribute is not set.

   .. py:method:: setTypeCertainty(typeCertainty)

      :param typeCertainty: EventTypeCertainty

      Denotes how certain the information on event type is \(Storchak et al.
      2012\).

   .. py:method:: typeCertainty()

      :rtype: EventTypeCertainty

      .. note::

         As this attribute is optional, this method throws a ValueError if
         the value of the attribute is not set.

   .. py:method:: setCreationInfo(creationInfo)

      :param creationInfo: :ref:`CreationInfo <api-python-datamodel-creationinfo>`

      CreationInfo for the Event object.

   .. py:method:: creationInfo()

      :rtype: :ref:`CreationInfo <api-python-datamodel-creationinfo>`

      .. note::

         As this attribute is optional, this method throws a ValueError if
         the value of the attribute is not set.

   .. py:method:: add(eventDescription)

      :param eventDescription: Object of type :ref:`EventDescription <api-python-datamodel-eventdescription>`
      :rtype: A Boolean value indicating success with True, False otherwise.

      Adds a EventDescription object to Event. The object is not
      copied but managed by this instance. Any change to the passed object
      will also change the child.

   .. py:method:: add(comment)

      :param comment: Object of type :ref:`Comment <api-python-datamodel-comment>`
      :rtype: A Boolean value indicating success with True, False otherwise.

      Adds a Comment object to Event. The object is not
      copied but managed by this instance. Any change to the passed object
      will also change the child.

   .. py:method:: add(originReference)

      :param originReference: Object of type :ref:`OriginReference <api-python-datamodel-originreference>`
      :rtype: A Boolean value indicating success with True, False otherwise.

      Adds a OriginReference object to Event. The object is not
      copied but managed by this instance. Any change to the passed object
      will also change the child.

   .. py:method:: add(focalMechanismReference)

      :param focalMechanismReference: Object of type :ref:`FocalMechanismReference <api-python-datamodel-focalmechanismreference>`
      :rtype: A Boolean value indicating success with True, False otherwise.

      Adds a FocalMechanismReference object to Event. The object is not
      copied but managed by this instance. Any change to the passed object
      will also change the child.

   .. py:method:: remove(eventDescription)

      :param eventDescription: Object of type :ref:`EventDescription <api-python-datamodel-eventdescription>`
      :rtype: A Boolean value indicating success with True, False otherwise.

      Removes a previously added EventDescription object from Event.

   .. py:method:: remove(comment)

      :param comment: Object of type :ref:`Comment <api-python-datamodel-comment>`
      :rtype: A Boolean value indicating success with True, False otherwise.

      Removes a previously added Comment object from Event.

   .. py:method:: remove(originReference)

      :param originReference: Object of type :ref:`OriginReference <api-python-datamodel-originreference>`
      :rtype: A Boolean value indicating success with True, False otherwise.

      Removes a previously added OriginReference object from Event.

   .. py:method:: remove(focalMechanismReference)

      :param focalMechanismReference: Object of type :ref:`FocalMechanismReference <api-python-datamodel-focalmechanismreference>`
      :rtype: A Boolean value indicating success with True, False otherwise.

      Removes a previously added FocalMechanismReference object from Event.

   .. py:method:: removeEventDescription(idx)

      :param idx: An integer index of the object to be removed.
      :rtype: A Boolean value indicating success with True, False otherwise.

   .. py:method:: removeEventDescription(eventDescriptionIndex);

      :param eventDescriptionIndex: The index of the object to be removed of type EventDescriptionIndex.
      :rtype: A Boolean value indicating success with True, False otherwise.

   .. py:method:: removeComment(idx)

      :param idx: An integer index of the object to be removed.
      :rtype: A Boolean value indicating success with True, False otherwise.

   .. py:method:: removeComment(commentIndex);

      :param commentIndex: The index of the object to be removed of type CommentIndex.
      :rtype: A Boolean value indicating success with True, False otherwise.

   .. py:method:: removeOriginReference(idx)

      :param idx: An integer index of the object to be removed.
      :rtype: A Boolean value indicating success with True, False otherwise.

   .. py:method:: removeOriginReference(originReferenceIndex);

      :param originReferenceIndex: The index of the object to be removed of type OriginReferenceIndex.
      :rtype: A Boolean value indicating success with True, False otherwise.

   .. py:method:: removeFocalMechanismReference(idx)

      :param idx: An integer index of the object to be removed.
      :rtype: A Boolean value indicating success with True, False otherwise.

   .. py:method:: removeFocalMechanismReference(focalMechanismReferenceIndex);

      :param focalMechanismReferenceIndex: The index of the object to be removed of type FocalMechanismReferenceIndex.
      :rtype: A Boolean value indicating success with True, False otherwise.

   .. py:method:: eventDescriptionCount()

      :rtype: integer value indicating the number of child objects.

      Returns the number of EventDescription child objects.

   .. py:method:: commentCount()

      :rtype: integer value indicating the number of child objects.

      Returns the number of Comment child objects.

   .. py:method:: originReferenceCount()

      :rtype: integer value indicating the number of child objects.

      Returns the number of OriginReference child objects.

   .. py:method:: focalMechanismReferenceCount()

      :rtype: integer value indicating the number of child objects.

      Returns the number of FocalMechanismReference child objects.

   .. py:method:: eventDescription(idx)

      :param idx: An integer index of the object to be returned.
      :rtype: Object of type :ref:`EventDescription <api-python-datamodel-eventdescription>`.

      Returns the EventDescription at index idx.

   .. py:method:: eventDescription(eventDescriptionIndex)

      :param eventDescriptionIndex: The index of the object to be removed of type EventDescriptionIndex.
      :rtype: Object of type :ref:`EventDescription <api-python-datamodel-eventdescription>`.

      Returns the EventDescription at given index. The indexes of all child objects
      are compared by value which makes this function slower than the direct
      integer index look-up.

   .. py:method:: comment(idx)

      :param idx: An integer index of the object to be returned.
      :rtype: Object of type :ref:`Comment <api-python-datamodel-comment>`.

      Returns the Comment at index idx.

   .. py:method:: comment(commentIndex)

      :param commentIndex: The index of the object to be removed of type CommentIndex.
      :rtype: Object of type :ref:`Comment <api-python-datamodel-comment>`.

      Returns the Comment at given index. The indexes of all child objects
      are compared by value which makes this function slower than the direct
      integer index look-up.

   .. py:method:: originReference(idx)

      :param idx: An integer index of the object to be returned.
      :rtype: Object of type :ref:`OriginReference <api-python-datamodel-originreference>`.

      Returns the OriginReference at index idx.

   .. py:method:: originReference(originReferenceIndex)

      :param originReferenceIndex: The index of the object to be removed of type OriginReferenceIndex.
      :rtype: Object of type :ref:`OriginReference <api-python-datamodel-originreference>`.

      Returns the OriginReference at given index. The indexes of all child objects
      are compared by value which makes this function slower than the direct
      integer index look-up.

   .. py:method:: focalMechanismReference(idx)

      :param idx: An integer index of the object to be returned.
      :rtype: Object of type :ref:`FocalMechanismReference <api-python-datamodel-focalmechanismreference>`.

      Returns the FocalMechanismReference at index idx.

   .. py:method:: focalMechanismReference(focalMechanismReferenceIndex)

      :param focalMechanismReferenceIndex: The index of the object to be removed of type FocalMechanismReferenceIndex.
      :rtype: Object of type :ref:`FocalMechanismReference <api-python-datamodel-focalmechanismreference>`.

      Returns the FocalMechanismReference at given index. The indexes of all child objects
      are compared by value which makes this function slower than the direct
      integer index look-up.

   .. py:method:: eventParameters()

      :rtype: EventParameters

      Returns the parent EventParameters if available. Returns None
      if the parent is not a EventParameters. This is a convenience wrapper
      for parent().

   .. py:method:: assign(other)

      This method implements the :ref:`Object <api-python-datamodel-object>` interface.

   .. py:method:: attachTo(parent)

      This method implements the :ref:`Object <api-python-datamodel-object>` interface.

   .. py:method:: detachFrom(parent)

      This method implements the :ref:`Object <api-python-datamodel-object>` interface.

   .. py:method:: detach()

      This method implements the :ref:`Object <api-python-datamodel-object>` interface.

   .. py:method:: clone()

      :rtype: A cloned Event.

      Returns a new instance that is a clone of the current instance. Child
      objects are being ignored.


   .. py:method:: updateChild(ref)

      :param ref: A child object derived from class Object.
      :rtype: A Boolean flag indicating success with True, False otherwise

      This method takes the passed reference object and searches for a child
      with the same publicID (if derived from :ref:`PublicObject <api-python-datamodel-publicobject>`)
      or the same index (if derived from :ref:`Object <api-python-datamodel-object>`).
      The the child was found the reference objects attributes are copied to
      the child object. Children of child are being ignored during this operation.
      This method implements the :ref:`PublicObject <api-python-datamodel-publicobject>` interface.


   .. py:method:: accept(visitor)

      :param visitor: A visitor.

      This method implements the :ref:`PublicObject <api-python-datamodel-publicobject>` interface.

.. _api-python-datamodel-eventdescription:

EventDescription
............................................................

.. py:class:: EventDescription

   Inherits :ref:`Object <api-python-datamodel-object>`.

   Free\-form string with additional event description. This can be a
   well\-known name, like 1906 San Francisco Earthquake. A number of
   categories can be given in type.

   **Parents**:

   - ``event`` -- :ref:`Event <api-python-datamodel-event>`

   **Attributes**:

   - ``text`` -- string
   - ``type`` -- :ref:`EventDescriptionType <api-python-datamodel-eventdescriptiontype>`

   **Methods**:

   .. py:staticmethod:: Cast(obj)

      :param obj: The object to be casted.
      :rtype: An object of type EventDescription if the cast was successful,
              None otherwise.

      Cast an arbitrary object to EventDescription if the internal wrapped
      representation is an EventDescription object. The cast is important if
      instances of type :ref:`Object <api-python-datamodel-object>`
      are passed to methods which need access to the real type.



   .. py:method:: equal(other)

      :param other: Another object of type EventDescription to compare this
                    instance to
      :rtype: A Boolean value indicating True if both objects are equal or
              False otherwise.

      Compares two objects without its child objects. Both objects are compared
      by value.

   .. py:method:: index()

      :rtype: The object's index of type EventDescriptionIndex.

       Returns the objects index which is also used for the database as unique
       constraint.

   .. py:method:: equalIndex(lhs)

      :param lhs: :ref:`EventDescription <api-python-datamodel-eventdescription>`
      :rtype: A Boolean value indicating True if both indexes are equal or
              False otherwise.

   .. py:method:: setText(text)

      :param text: string

      Free\-form text with earthquake description.

   .. py:method:: text()

      :rtype: string

   .. py:method:: setType(type)

      :param type: EventDescriptionType

      Category of earthquake description.

   .. py:method:: type()

      :rtype: EventDescriptionType

   .. py:method:: event()

      :rtype: Event

      Returns the parent Event if available. Returns None
      if the parent is not a Event. This is a convenience wrapper
      for parent().

   .. py:method:: assign(other)

      This method implements the :ref:`Object <api-python-datamodel-object>` interface.

   .. py:method:: attachTo(parent)

      This method implements the :ref:`Object <api-python-datamodel-object>` interface.

   .. py:method:: detachFrom(parent)

      This method implements the :ref:`Object <api-python-datamodel-object>` interface.

   .. py:method:: detach()

      This method implements the :ref:`Object <api-python-datamodel-object>` interface.

   .. py:method:: clone()

      :rtype: A cloned EventDescription.

      Returns a new instance that is a clone of the current instance. Child
      objects are being ignored.


   .. py:method:: accept(visitor)

      :param visitor: A visitor.

      This method implements the :ref:`PublicObject <api-python-datamodel-publicobject>` interface.

.. _api-python-datamodel-eventparameters:

EventParameters
............................................................

.. py:class:: EventParameters

   Inherits :ref:`PublicObject <api-python-datamodel-publicobject>`.

   This type can hold objects of type Event, Origin, Magnitude, StationMagnitude,
   FocalMechanism, Reading, Amplitude, and Pick.

   **Children**:

   - ``pick`` -- :ref:`Pick <api-python-datamodel-pick>`
   - ``amplitude`` -- :ref:`Amplitude <api-python-datamodel-amplitude>`
   - ``reading`` -- :ref:`Reading <api-python-datamodel-reading>`
   - ``origin`` -- :ref:`Origin <api-python-datamodel-origin>`
   - ``focalMechanism`` -- :ref:`FocalMechanism <api-python-datamodel-focalmechanism>`
   - ``event`` -- :ref:`Event <api-python-datamodel-event>`

   **Attributes**:

   - ``publicID``: string

   **Methods**:

   .. py:staticmethod:: Cast(obj)

      :param obj: The object to be casted.
      :rtype: An object of type EventParameters if the cast was successful,
              None otherwise.

      Cast an arbitrary object to EventParameters if the internal wrapped
      representation is an EventParameters object. The cast is important if
      instances of type :ref:`Object <api-python-datamodel-object>`
      are passed to methods which need access to the real type.



   .. py:method:: equal(other)

      :param other: Another object of type EventParameters to compare this
                    instance to
      :rtype: A Boolean value indicating True if both objects are equal or
              False otherwise.

      Compares two objects without its child objects. Both objects are compared
      by value.

   .. py:method:: add(pick)

      :param pick: Object of type :ref:`Pick <api-python-datamodel-pick>`
      :rtype: A Boolean value indicating success with True, False otherwise.

      Adds a Pick object to EventParameters. The object is not
      copied but managed by this instance. Any change to the passed object
      will also change the child.

   .. py:method:: add(amplitude)

      :param amplitude: Object of type :ref:`Amplitude <api-python-datamodel-amplitude>`
      :rtype: A Boolean value indicating success with True, False otherwise.

      Adds a Amplitude object to EventParameters. The object is not
      copied but managed by this instance. Any change to the passed object
      will also change the child.

   .. py:method:: add(reading)

      :param reading: Object of type :ref:`Reading <api-python-datamodel-reading>`
      :rtype: A Boolean value indicating success with True, False otherwise.

      Adds a Reading object to EventParameters. The object is not
      copied but managed by this instance. Any change to the passed object
      will also change the child.

   .. py:method:: add(origin)

      :param origin: Object of type :ref:`Origin <api-python-datamodel-origin>`
      :rtype: A Boolean value indicating success with True, False otherwise.

      Adds a Origin object to EventParameters. The object is not
      copied but managed by this instance. Any change to the passed object
      will also change the child.

   .. py:method:: add(focalMechanism)

      :param focalMechanism: Object of type :ref:`FocalMechanism <api-python-datamodel-focalmechanism>`
      :rtype: A Boolean value indicating success with True, False otherwise.

      Adds a FocalMechanism object to EventParameters. The object is not
      copied but managed by this instance. Any change to the passed object
      will also change the child.

   .. py:method:: add(event)

      :param event: Object of type :ref:`Event <api-python-datamodel-event>`
      :rtype: A Boolean value indicating success with True, False otherwise.

      Adds a Event object to EventParameters. The object is not
      copied but managed by this instance. Any change to the passed object
      will also change the child.

   .. py:method:: remove(pick)

      :param pick: Object of type :ref:`Pick <api-python-datamodel-pick>`
      :rtype: A Boolean value indicating success with True, False otherwise.

      Removes a previously added Pick object from EventParameters.

   .. py:method:: remove(amplitude)

      :param amplitude: Object of type :ref:`Amplitude <api-python-datamodel-amplitude>`
      :rtype: A Boolean value indicating success with True, False otherwise.

      Removes a previously added Amplitude object from EventParameters.

   .. py:method:: remove(reading)

      :param reading: Object of type :ref:`Reading <api-python-datamodel-reading>`
      :rtype: A Boolean value indicating success with True, False otherwise.

      Removes a previously added Reading object from EventParameters.

   .. py:method:: remove(origin)

      :param origin: Object of type :ref:`Origin <api-python-datamodel-origin>`
      :rtype: A Boolean value indicating success with True, False otherwise.

      Removes a previously added Origin object from EventParameters.

   .. py:method:: remove(focalMechanism)

      :param focalMechanism: Object of type :ref:`FocalMechanism <api-python-datamodel-focalmechanism>`
      :rtype: A Boolean value indicating success with True, False otherwise.

      Removes a previously added FocalMechanism object from EventParameters.

   .. py:method:: remove(event)

      :param event: Object of type :ref:`Event <api-python-datamodel-event>`
      :rtype: A Boolean value indicating success with True, False otherwise.

      Removes a previously added Event object from EventParameters.

   .. py:method:: removePick(idx)

      :param idx: An integer index of the object to be removed.
      :rtype: A Boolean value indicating success with True, False otherwise.

   .. py:method:: removeAmplitude(idx)

      :param idx: An integer index of the object to be removed.
      :rtype: A Boolean value indicating success with True, False otherwise.

   .. py:method:: removeReading(idx)

      :param idx: An integer index of the object to be removed.
      :rtype: A Boolean value indicating success with True, False otherwise.

   .. py:method:: removeOrigin(idx)

      :param idx: An integer index of the object to be removed.
      :rtype: A Boolean value indicating success with True, False otherwise.

   .. py:method:: removeFocalMechanism(idx)

      :param idx: An integer index of the object to be removed.
      :rtype: A Boolean value indicating success with True, False otherwise.

   .. py:method:: removeEvent(idx)

      :param idx: An integer index of the object to be removed.
      :rtype: A Boolean value indicating success with True, False otherwise.

   .. py:method:: pickCount()

      :rtype: integer value indicating the number of child objects.

      Returns the number of Pick child objects.

   .. py:method:: amplitudeCount()

      :rtype: integer value indicating the number of child objects.

      Returns the number of Amplitude child objects.

   .. py:method:: readingCount()

      :rtype: integer value indicating the number of child objects.

      Returns the number of Reading child objects.

   .. py:method:: originCount()

      :rtype: integer value indicating the number of child objects.

      Returns the number of Origin child objects.

   .. py:method:: focalMechanismCount()

      :rtype: integer value indicating the number of child objects.

      Returns the number of FocalMechanism child objects.

   .. py:method:: eventCount()

      :rtype: integer value indicating the number of child objects.

      Returns the number of Event child objects.

   .. py:method:: pick(idx)

      :param idx: An integer index of the object to be returned.
      :rtype: Object of type :ref:`Pick <api-python-datamodel-pick>`.

      Returns the Pick at index idx.

   .. py:method:: amplitude(idx)

      :param idx: An integer index of the object to be returned.
      :rtype: Object of type :ref:`Amplitude <api-python-datamodel-amplitude>`.

      Returns the Amplitude at index idx.

   .. py:method:: reading(idx)

      :param idx: An integer index of the object to be returned.
      :rtype: Object of type :ref:`Reading <api-python-datamodel-reading>`.

      Returns the Reading at index idx.

   .. py:method:: origin(idx)

      :param idx: An integer index of the object to be returned.
      :rtype: Object of type :ref:`Origin <api-python-datamodel-origin>`.

      Returns the Origin at index idx.

   .. py:method:: focalMechanism(idx)

      :param idx: An integer index of the object to be returned.
      :rtype: Object of type :ref:`FocalMechanism <api-python-datamodel-focalmechanism>`.

      Returns the FocalMechanism at index idx.

   .. py:method:: event(idx)

      :param idx: An integer index of the object to be returned.
      :rtype: Object of type :ref:`Event <api-python-datamodel-event>`.

      Returns the Event at index idx.

   .. py:method:: findPick(publicID)

      :param publicID: The publicID of the object to find.
      :rtype: Object of type :ref:`Pick <api-python-datamodel-pick>`.

      Returns the child object with a certain publicID, None otherwise.

   .. py:method:: findAmplitude(publicID)

      :param publicID: The publicID of the object to find.
      :rtype: Object of type :ref:`Amplitude <api-python-datamodel-amplitude>`.

      Returns the child object with a certain publicID, None otherwise.

   .. py:method:: findReading(publicID)

      :param publicID: The publicID of the object to find.
      :rtype: Object of type :ref:`Reading <api-python-datamodel-reading>`.

      Returns the child object with a certain publicID, None otherwise.

   .. py:method:: findOrigin(publicID)

      :param publicID: The publicID of the object to find.
      :rtype: Object of type :ref:`Origin <api-python-datamodel-origin>`.

      Returns the child object with a certain publicID, None otherwise.

   .. py:method:: findFocalMechanism(publicID)

      :param publicID: The publicID of the object to find.
      :rtype: Object of type :ref:`FocalMechanism <api-python-datamodel-focalmechanism>`.

      Returns the child object with a certain publicID, None otherwise.

   .. py:method:: findEvent(publicID)

      :param publicID: The publicID of the object to find.
      :rtype: Object of type :ref:`Event <api-python-datamodel-event>`.

      Returns the child object with a certain publicID, None otherwise.

   .. py:method:: assign(other)

      This method implements the :ref:`Object <api-python-datamodel-object>` interface.

   .. py:method:: attachTo(parent)

      This method implements the :ref:`Object <api-python-datamodel-object>` interface.

   .. py:method:: detachFrom(parent)

      This method implements the :ref:`Object <api-python-datamodel-object>` interface.

   .. py:method:: detach()

      This method implements the :ref:`Object <api-python-datamodel-object>` interface.

   .. py:method:: clone()

      :rtype: A cloned EventParameters.

      Returns a new instance that is a clone of the current instance. Child
      objects are being ignored.


   .. py:method:: updateChild(ref)

      :param ref: A child object derived from class Object.
      :rtype: A Boolean flag indicating success with True, False otherwise

      This method takes the passed reference object and searches for a child
      with the same publicID (if derived from :ref:`PublicObject <api-python-datamodel-publicobject>`)
      or the same index (if derived from :ref:`Object <api-python-datamodel-object>`).
      The the child was found the reference objects attributes are copied to
      the child object. Children of child are being ignored during this operation.
      This method implements the :ref:`PublicObject <api-python-datamodel-publicobject>` interface.


   .. py:method:: accept(visitor)

      :param visitor: A visitor.

      This method implements the :ref:`PublicObject <api-python-datamodel-publicobject>` interface.

.. _api-python-datamodel-focalmechanism:

FocalMechanism
............................................................

.. py:class:: FocalMechanism

   Inherits :ref:`PublicObject <api-python-datamodel-publicobject>`.

   This class describes the focal mechanism of an event. It includes different
   descriptions like nodal planes, principal axes, and a moment tensor.
   The moment tensor description is provided by objects of the class
   MomentTensor which can be specified as child elements of FocalMechanism.

   **Parents**:

   - ``eventParameters`` -- :ref:`EventParameters <api-python-datamodel-eventparameters>`

   **Children**:

   - ``comment`` -- :ref:`Comment <api-python-datamodel-comment>`
   - ``momentTensor`` -- :ref:`MomentTensor <api-python-datamodel-momenttensor>`

   **Attributes**:

   - ``publicID``: string
   - ``triggeringOriginID`` -- string
   - ``nodalPlanes`` -- :ref:`NodalPlanes <api-python-datamodel-nodalplanes>` (optional)
   - ``principalAxes`` -- :ref:`PrincipalAxes <api-python-datamodel-principalaxes>` (optional)
   - ``azimuthalGap`` -- float (optional)
   - ``stationPolarityCount`` -- int (optional)
   - ``misfit`` -- float (optional)
   - ``stationDistributionRatio`` -- float (optional)
   - ``methodID`` -- string
   - ``evaluationMode`` -- :ref:`EvaluationMode <api-python-datamodel-evaluationmode>` (optional)
   - ``evaluationStatus`` -- :ref:`EvaluationStatus <api-python-datamodel-evaluationstatus>` (optional)
   - ``creationInfo`` -- :ref:`CreationInfo <api-python-datamodel-creationinfo>` (optional)

   **Referenced by**:

   - :func:`Event.preferredFocalMechanismID`
   - :func:`FocalMechanismReference.focalMechanismID`

   **Methods**:

   .. py:staticmethod:: Cast(obj)

      :param obj: The object to be casted.
      :rtype: An object of type FocalMechanism if the cast was successful,
              None otherwise.

      Cast an arbitrary object to FocalMechanism if the internal wrapped
      representation is an FocalMechanism object. The cast is important if
      instances of type :ref:`Object <api-python-datamodel-object>`
      are passed to methods which need access to the real type.



   .. py:staticmethod:: Create()

      :rtype: A new object of type FocalMechanism.

      Creates and registers (if enabled) a FocalMechanism instance. The
      publicID is auto-generated.

   .. py:staticmethod:: Create(publicID)

      :rtype: A new object of type FocalMechanism.

      Creates and registers (if enabled) a FocalMechanism instance with
      passed publicID.

   .. py:method:: equal(other)

      :param other: Another object of type FocalMechanism to compare this
                    instance to
      :rtype: A Boolean value indicating True if both objects are equal or
              False otherwise.

      Compares two objects without its child objects. Both objects are compared
      by value.

   .. py:method:: setTriggeringOriginID(triggeringOriginID)

      :param triggeringOriginID: string

      Refers to the publicID of the triggering origin.

   .. py:method:: triggeringOriginID()

      :rtype: string

   .. py:method:: setNodalPlanes(nodalPlanes)

      :param nodalPlanes: :ref:`NodalPlanes <api-python-datamodel-nodalplanes>`

      Nodal planes of the focal mechanism.

   .. py:method:: nodalPlanes()

      :rtype: :ref:`NodalPlanes <api-python-datamodel-nodalplanes>`

      .. note::

         As this attribute is optional, this method throws a ValueError if
         the value of the attribute is not set.

   .. py:method:: setPrincipalAxes(principalAxes)

      :param principalAxes: :ref:`PrincipalAxes <api-python-datamodel-principalaxes>`

      Principal axes of the focal mechanism.

   .. py:method:: principalAxes()

      :rtype: :ref:`PrincipalAxes <api-python-datamodel-principalaxes>`

      .. note::

         As this attribute is optional, this method throws a ValueError if
         the value of the attribute is not set.

   .. py:method:: setAzimuthalGap(azimuthalGap)

      :param azimuthalGap: float

      Largest azimuthal gap in distribution of stations used for determination
      of focal mechanism in degrees.

   .. py:method:: azimuthalGap()

      :rtype: float

      .. note::

         As this attribute is optional, this method throws a ValueError if
         the value of the attribute is not set.

   .. py:method:: setStationPolarityCount(stationPolarityCount)

      :param stationPolarityCount: int

      Number of station polarities used for determination of focal mechanism.

   .. py:method:: stationPolarityCount()

      :rtype: int

      .. note::

         As this attribute is optional, this method throws a ValueError if
         the value of the attribute is not set.

   .. py:method:: setMisfit(misfit)

      :param misfit: float

      Fraction of misfit polarities in a first\-motion focal mechanism
      determination.
      Decimal fraction between 0 and 1.

   .. py:method:: misfit()

      :rtype: float

      .. note::

         As this attribute is optional, this method throws a ValueError if
         the value of the attribute is not set.

   .. py:method:: setStationDistributionRatio(stationDistributionRatio)

      :param stationDistributionRatio: float

      Station distribution ratio \(STDR\) parameter. Indicates how the stations
      are distributed about the focal sphere \(Reasenberg and Oppenheimer 1985\).
      Decimal fraction between 0 and 1.

   .. py:method:: stationDistributionRatio()

      :rtype: float

      .. note::

         As this attribute is optional, this method throws a ValueError if
         the value of the attribute is not set.

   .. py:method:: setMethodID(methodID)

      :param methodID: string

      Resource identifier of the method used for determination of the focal
      mechanism.

   .. py:method:: methodID()

      :rtype: string

   .. py:method:: setEvaluationMode(evaluationMode)

      :param evaluationMode: EvaluationMode

      Evaluation mode of FocalMechanism.

   .. py:method:: evaluationMode()

      :rtype: EvaluationMode

      .. note::

         As this attribute is optional, this method throws a ValueError if
         the value of the attribute is not set.

   .. py:method:: setEvaluationStatus(evaluationStatus)

      :param evaluationStatus: EvaluationStatus

      Evaluation status of FocalMechanism.

   .. py:method:: evaluationStatus()

      :rtype: EvaluationStatus

      .. note::

         As this attribute is optional, this method throws a ValueError if
         the value of the attribute is not set.

   .. py:method:: setCreationInfo(creationInfo)

      :param creationInfo: :ref:`CreationInfo <api-python-datamodel-creationinfo>`

   .. py:method:: creationInfo()

      :rtype: :ref:`CreationInfo <api-python-datamodel-creationinfo>`

      .. note::

         As this attribute is optional, this method throws a ValueError if
         the value of the attribute is not set.

   .. py:method:: add(comment)

      :param comment: Object of type :ref:`Comment <api-python-datamodel-comment>`
      :rtype: A Boolean value indicating success with True, False otherwise.

      Adds a Comment object to FocalMechanism. The object is not
      copied but managed by this instance. Any change to the passed object
      will also change the child.

   .. py:method:: add(momentTensor)

      :param momentTensor: Object of type :ref:`MomentTensor <api-python-datamodel-momenttensor>`
      :rtype: A Boolean value indicating success with True, False otherwise.

      Adds a MomentTensor object to FocalMechanism. The object is not
      copied but managed by this instance. Any change to the passed object
      will also change the child.

   .. py:method:: remove(comment)

      :param comment: Object of type :ref:`Comment <api-python-datamodel-comment>`
      :rtype: A Boolean value indicating success with True, False otherwise.

      Removes a previously added Comment object from FocalMechanism.

   .. py:method:: remove(momentTensor)

      :param momentTensor: Object of type :ref:`MomentTensor <api-python-datamodel-momenttensor>`
      :rtype: A Boolean value indicating success with True, False otherwise.

      Removes a previously added MomentTensor object from FocalMechanism.

   .. py:method:: removeComment(idx)

      :param idx: An integer index of the object to be removed.
      :rtype: A Boolean value indicating success with True, False otherwise.

   .. py:method:: removeComment(commentIndex);

      :param commentIndex: The index of the object to be removed of type CommentIndex.
      :rtype: A Boolean value indicating success with True, False otherwise.

   .. py:method:: removeMomentTensor(idx)

      :param idx: An integer index of the object to be removed.
      :rtype: A Boolean value indicating success with True, False otherwise.

   .. py:method:: commentCount()

      :rtype: integer value indicating the number of child objects.

      Returns the number of Comment child objects.

   .. py:method:: momentTensorCount()

      :rtype: integer value indicating the number of child objects.

      Returns the number of MomentTensor child objects.

   .. py:method:: comment(idx)

      :param idx: An integer index of the object to be returned.
      :rtype: Object of type :ref:`Comment <api-python-datamodel-comment>`.

      Returns the Comment at index idx.

   .. py:method:: comment(commentIndex)

      :param commentIndex: The index of the object to be removed of type CommentIndex.
      :rtype: Object of type :ref:`Comment <api-python-datamodel-comment>`.

      Returns the Comment at given index. The indexes of all child objects
      are compared by value which makes this function slower than the direct
      integer index look-up.

   .. py:method:: momentTensor(idx)

      :param idx: An integer index of the object to be returned.
      :rtype: Object of type :ref:`MomentTensor <api-python-datamodel-momenttensor>`.

      Returns the MomentTensor at index idx.

   .. py:method:: findMomentTensor(publicID)

      :param publicID: The publicID of the object to find.
      :rtype: Object of type :ref:`MomentTensor <api-python-datamodel-momenttensor>`.

      Returns the child object with a certain publicID, None otherwise.

   .. py:method:: eventParameters()

      :rtype: EventParameters

      Returns the parent EventParameters if available. Returns None
      if the parent is not a EventParameters. This is a convenience wrapper
      for parent().

   .. py:method:: assign(other)

      This method implements the :ref:`Object <api-python-datamodel-object>` interface.

   .. py:method:: attachTo(parent)

      This method implements the :ref:`Object <api-python-datamodel-object>` interface.

   .. py:method:: detachFrom(parent)

      This method implements the :ref:`Object <api-python-datamodel-object>` interface.

   .. py:method:: detach()

      This method implements the :ref:`Object <api-python-datamodel-object>` interface.

   .. py:method:: clone()

      :rtype: A cloned FocalMechanism.

      Returns a new instance that is a clone of the current instance. Child
      objects are being ignored.


   .. py:method:: updateChild(ref)

      :param ref: A child object derived from class Object.
      :rtype: A Boolean flag indicating success with True, False otherwise

      This method takes the passed reference object and searches for a child
      with the same publicID (if derived from :ref:`PublicObject <api-python-datamodel-publicobject>`)
      or the same index (if derived from :ref:`Object <api-python-datamodel-object>`).
      The the child was found the reference objects attributes are copied to
      the child object. Children of child are being ignored during this operation.
      This method implements the :ref:`PublicObject <api-python-datamodel-publicobject>` interface.


   .. py:method:: accept(visitor)

      :param visitor: A visitor.

      This method implements the :ref:`PublicObject <api-python-datamodel-publicobject>` interface.

.. _api-python-datamodel-focalmechanismreference:

FocalMechanismReference
............................................................

.. py:class:: FocalMechanismReference

   Inherits :ref:`Object <api-python-datamodel-object>`.


   **Parents**:

   - ``event`` -- :ref:`Event <api-python-datamodel-event>`

   **Attributes**:

   - ``focalMechanismID`` -- string

   **Methods**:

   .. py:staticmethod:: Cast(obj)

      :param obj: The object to be casted.
      :rtype: An object of type FocalMechanismReference if the cast was successful,
              None otherwise.

      Cast an arbitrary object to FocalMechanismReference if the internal wrapped
      representation is an FocalMechanismReference object. The cast is important if
      instances of type :ref:`Object <api-python-datamodel-object>`
      are passed to methods which need access to the real type.



   .. py:method:: equal(other)

      :param other: Another object of type FocalMechanismReference to compare this
                    instance to
      :rtype: A Boolean value indicating True if both objects are equal or
              False otherwise.

      Compares two objects without its child objects. Both objects are compared
      by value.

   .. py:method:: index()

      :rtype: The object's index of type FocalMechanismReferenceIndex.

       Returns the objects index which is also used for the database as unique
       constraint.

   .. py:method:: equalIndex(lhs)

      :param lhs: :ref:`FocalMechanismReference <api-python-datamodel-focalmechanismreference>`
      :rtype: A Boolean value indicating True if both indexes are equal or
              False otherwise.

   .. py:method:: setFocalMechanismID(focalMechanismID)

      :param focalMechanismID: string

   .. py:method:: focalMechanismID()

      :rtype: string

   .. py:method:: event()

      :rtype: Event

      Returns the parent Event if available. Returns None
      if the parent is not a Event. This is a convenience wrapper
      for parent().

   .. py:method:: assign(other)

      This method implements the :ref:`Object <api-python-datamodel-object>` interface.

   .. py:method:: attachTo(parent)

      This method implements the :ref:`Object <api-python-datamodel-object>` interface.

   .. py:method:: detachFrom(parent)

      This method implements the :ref:`Object <api-python-datamodel-object>` interface.

   .. py:method:: detach()

      This method implements the :ref:`Object <api-python-datamodel-object>` interface.

   .. py:method:: clone()

      :rtype: A cloned FocalMechanismReference.

      Returns a new instance that is a clone of the current instance. Child
      objects are being ignored.


   .. py:method:: accept(visitor)

      :param visitor: A visitor.

      This method implements the :ref:`PublicObject <api-python-datamodel-publicobject>` interface.

.. _api-python-datamodel-integerquantity:

IntegerQuantity
............................................................

.. py:class:: IntegerQuantity

   Inherits :ref:`Object <api-python-datamodel-object>`.

   Physical quantities expressed as integers are represented by their
   measured or computed values and optional values for symmetric or upper
   and lower uncertainties. The interpretation of these uncertainties is
   not defined in the standard. They can contain statistically well\-defined
   error measures, but the mechanism can also be used to simply describe a
   possible value range. If the confidence level of the uncertainty is known,
   it can be listed in the optional attribute confidenceLevel.
   Note that uncertainty, upperUncertainty, and lowerUncertainty are given as
   absolute values of the deviation
   from the main value.

   **Attributes**:

   - ``value`` -- int
   - ``uncertainty`` -- int (optional)
   - ``lowerUncertainty`` -- int (optional)
   - ``upperUncertainty`` -- int (optional)
   - ``confidenceLevel`` -- float (optional)

   **Used by**:

   - :func:`CompositeTime.year`
   - :func:`CompositeTime.month`
   - :func:`CompositeTime.day`
   - :func:`CompositeTime.hour`
   - :func:`CompositeTime.minute`

   **Methods**:

   .. py:staticmethod:: Cast(obj)

      :param obj: The object to be casted.
      :rtype: An object of type IntegerQuantity if the cast was successful,
              None otherwise.

      Cast an arbitrary object to IntegerQuantity if the internal wrapped
      representation is an IntegerQuantity object. The cast is important if
      instances of type :ref:`Object <api-python-datamodel-object>`
      are passed to methods which need access to the real type.



   .. py:method:: equal(other)

      :param other: Another object of type IntegerQuantity to compare this
                    instance to
      :rtype: A Boolean value indicating True if both objects are equal or
              False otherwise.

      Compares two objects without its child objects. Both objects are compared
      by value.

   .. py:method:: setValue(value)

      :param value: int

      Value of the quantity. The unit is implicitly defined and depends on the
      context.

   .. py:method:: value()

      :rtype: int

   .. py:method:: setUncertainty(uncertainty)

      :param uncertainty: int

      Uncertainty as the absolute value of symmetric deviation from the main value.

   .. py:method:: uncertainty()

      :rtype: int

      .. note::

         As this attribute is optional, this method throws a ValueError if
         the value of the attribute is not set.

   .. py:method:: setLowerUncertainty(lowerUncertainty)

      :param lowerUncertainty: int

      Uncertainty as the absolute value of deviation from the main value towards
      smaller values.

   .. py:method:: lowerUncertainty()

      :rtype: int

      .. note::

         As this attribute is optional, this method throws a ValueError if
         the value of the attribute is not set.

   .. py:method:: setUpperUncertainty(upperUncertainty)

      :param upperUncertainty: int

      Uncertainty as the absolute value of deviation from the main value towards
      larger values.

   .. py:method:: upperUncertainty()

      :rtype: int

      .. note::

         As this attribute is optional, this method throws a ValueError if
         the value of the attribute is not set.

   .. py:method:: setConfidenceLevel(confidenceLevel)

      :param confidenceLevel: float

      Confidence level of the uncertainty, given in percent.

   .. py:method:: confidenceLevel()

      :rtype: float

      .. note::

         As this attribute is optional, this method throws a ValueError if
         the value of the attribute is not set.

.. _api-python-datamodel-inventory:

Inventory
............................................................

.. py:class:: Inventory

   Inherits :ref:`PublicObject <api-python-datamodel-publicobject>`.


   **Children**:

   - ``stationGroup`` -- :ref:`StationGroup <api-python-datamodel-stationgroup>`
   - ``auxDevice`` -- :ref:`AuxDevice <api-python-datamodel-auxdevice>`
   - ``sensor`` -- :ref:`Sensor <api-python-datamodel-sensor>`
   - ``datalogger`` -- :ref:`Datalogger <api-python-datamodel-datalogger>`
   - ``responsePAZ`` -- :ref:`ResponsePAZ <api-python-datamodel-responsepaz>`
   - ``responseFIR`` -- :ref:`ResponseFIR <api-python-datamodel-responsefir>`
   - ``responseIIR`` -- :ref:`ResponseIIR <api-python-datamodel-responseiir>`
   - ``responsePolynomial`` -- :ref:`ResponsePolynomial <api-python-datamodel-responsepolynomial>`
   - ``responseFAP`` -- :ref:`ResponseFAP <api-python-datamodel-responsefap>`
   - ``network`` -- :ref:`Network <api-python-datamodel-network>`

   **Attributes**:

   - ``publicID``: string

   **Methods**:

   .. py:staticmethod:: Cast(obj)

      :param obj: The object to be casted.
      :rtype: An object of type Inventory if the cast was successful,
              None otherwise.

      Cast an arbitrary object to Inventory if the internal wrapped
      representation is an Inventory object. The cast is important if
      instances of type :ref:`Object <api-python-datamodel-object>`
      are passed to methods which need access to the real type.



   .. py:method:: equal(other)

      :param other: Another object of type Inventory to compare this
                    instance to
      :rtype: A Boolean value indicating True if both objects are equal or
              False otherwise.

      Compares two objects without its child objects. Both objects are compared
      by value.

   .. py:method:: add(stationGroup)

      :param stationGroup: Object of type :ref:`StationGroup <api-python-datamodel-stationgroup>`
      :rtype: A Boolean value indicating success with True, False otherwise.

      Adds a StationGroup object to Inventory. The object is not
      copied but managed by this instance. Any change to the passed object
      will also change the child.

   .. py:method:: add(auxDevice)

      :param auxDevice: Object of type :ref:`AuxDevice <api-python-datamodel-auxdevice>`
      :rtype: A Boolean value indicating success with True, False otherwise.

      Adds a AuxDevice object to Inventory. The object is not
      copied but managed by this instance. Any change to the passed object
      will also change the child.

   .. py:method:: add(sensor)

      :param sensor: Object of type :ref:`Sensor <api-python-datamodel-sensor>`
      :rtype: A Boolean value indicating success with True, False otherwise.

      Adds a Sensor object to Inventory. The object is not
      copied but managed by this instance. Any change to the passed object
      will also change the child.

   .. py:method:: add(datalogger)

      :param datalogger: Object of type :ref:`Datalogger <api-python-datamodel-datalogger>`
      :rtype: A Boolean value indicating success with True, False otherwise.

      Adds a Datalogger object to Inventory. The object is not
      copied but managed by this instance. Any change to the passed object
      will also change the child.

   .. py:method:: add(responsePAZ)

      :param responsePAZ: Object of type :ref:`ResponsePAZ <api-python-datamodel-responsepaz>`
      :rtype: A Boolean value indicating success with True, False otherwise.

      Adds a ResponsePAZ object to Inventory. The object is not
      copied but managed by this instance. Any change to the passed object
      will also change the child.

   .. py:method:: add(responseFIR)

      :param responseFIR: Object of type :ref:`ResponseFIR <api-python-datamodel-responsefir>`
      :rtype: A Boolean value indicating success with True, False otherwise.

      Adds a ResponseFIR object to Inventory. The object is not
      copied but managed by this instance. Any change to the passed object
      will also change the child.

   .. py:method:: add(responseIIR)

      :param responseIIR: Object of type :ref:`ResponseIIR <api-python-datamodel-responseiir>`
      :rtype: A Boolean value indicating success with True, False otherwise.

      Adds a ResponseIIR object to Inventory. The object is not
      copied but managed by this instance. Any change to the passed object
      will also change the child.

   .. py:method:: add(responsePolynomial)

      :param responsePolynomial: Object of type :ref:`ResponsePolynomial <api-python-datamodel-responsepolynomial>`
      :rtype: A Boolean value indicating success with True, False otherwise.

      Adds a ResponsePolynomial object to Inventory. The object is not
      copied but managed by this instance. Any change to the passed object
      will also change the child.

   .. py:method:: add(responseFAP)

      :param responseFAP: Object of type :ref:`ResponseFAP <api-python-datamodel-responsefap>`
      :rtype: A Boolean value indicating success with True, False otherwise.

      Adds a ResponseFAP object to Inventory. The object is not
      copied but managed by this instance. Any change to the passed object
      will also change the child.

   .. py:method:: add(network)

      :param network: Object of type :ref:`Network <api-python-datamodel-network>`
      :rtype: A Boolean value indicating success with True, False otherwise.

      Adds a Network object to Inventory. The object is not
      copied but managed by this instance. Any change to the passed object
      will also change the child.

   .. py:method:: remove(stationGroup)

      :param stationGroup: Object of type :ref:`StationGroup <api-python-datamodel-stationgroup>`
      :rtype: A Boolean value indicating success with True, False otherwise.

      Removes a previously added StationGroup object from Inventory.

   .. py:method:: remove(auxDevice)

      :param auxDevice: Object of type :ref:`AuxDevice <api-python-datamodel-auxdevice>`
      :rtype: A Boolean value indicating success with True, False otherwise.

      Removes a previously added AuxDevice object from Inventory.

   .. py:method:: remove(sensor)

      :param sensor: Object of type :ref:`Sensor <api-python-datamodel-sensor>`
      :rtype: A Boolean value indicating success with True, False otherwise.

      Removes a previously added Sensor object from Inventory.

   .. py:method:: remove(datalogger)

      :param datalogger: Object of type :ref:`Datalogger <api-python-datamodel-datalogger>`
      :rtype: A Boolean value indicating success with True, False otherwise.

      Removes a previously added Datalogger object from Inventory.

   .. py:method:: remove(responsePAZ)

      :param responsePAZ: Object of type :ref:`ResponsePAZ <api-python-datamodel-responsepaz>`
      :rtype: A Boolean value indicating success with True, False otherwise.

      Removes a previously added ResponsePAZ object from Inventory.

   .. py:method:: remove(responseFIR)

      :param responseFIR: Object of type :ref:`ResponseFIR <api-python-datamodel-responsefir>`
      :rtype: A Boolean value indicating success with True, False otherwise.

      Removes a previously added ResponseFIR object from Inventory.

   .. py:method:: remove(responseIIR)

      :param responseIIR: Object of type :ref:`ResponseIIR <api-python-datamodel-responseiir>`
      :rtype: A Boolean value indicating success with True, False otherwise.

      Removes a previously added ResponseIIR object from Inventory.

   .. py:method:: remove(responsePolynomial)

      :param responsePolynomial: Object of type :ref:`ResponsePolynomial <api-python-datamodel-responsepolynomial>`
      :rtype: A Boolean value indicating success with True, False otherwise.

      Removes a previously added ResponsePolynomial object from Inventory.

   .. py:method:: remove(responseFAP)

      :param responseFAP: Object of type :ref:`ResponseFAP <api-python-datamodel-responsefap>`
      :rtype: A Boolean value indicating success with True, False otherwise.

      Removes a previously added ResponseFAP object from Inventory.

   .. py:method:: remove(network)

      :param network: Object of type :ref:`Network <api-python-datamodel-network>`
      :rtype: A Boolean value indicating success with True, False otherwise.

      Removes a previously added Network object from Inventory.

   .. py:method:: removeStationGroup(idx)

      :param idx: An integer index of the object to be removed.
      :rtype: A Boolean value indicating success with True, False otherwise.

   .. py:method:: removeStationGroup(stationGroupIndex);

      :param stationGroupIndex: The index of the object to be removed of type StationGroupIndex.
      :rtype: A Boolean value indicating success with True, False otherwise.

   .. py:method:: removeAuxDevice(idx)

      :param idx: An integer index of the object to be removed.
      :rtype: A Boolean value indicating success with True, False otherwise.

   .. py:method:: removeAuxDevice(auxDeviceIndex);

      :param auxDeviceIndex: The index of the object to be removed of type AuxDeviceIndex.
      :rtype: A Boolean value indicating success with True, False otherwise.

   .. py:method:: removeSensor(idx)

      :param idx: An integer index of the object to be removed.
      :rtype: A Boolean value indicating success with True, False otherwise.

   .. py:method:: removeSensor(sensorIndex);

      :param sensorIndex: The index of the object to be removed of type SensorIndex.
      :rtype: A Boolean value indicating success with True, False otherwise.

   .. py:method:: removeDatalogger(idx)

      :param idx: An integer index of the object to be removed.
      :rtype: A Boolean value indicating success with True, False otherwise.

   .. py:method:: removeDatalogger(dataloggerIndex);

      :param dataloggerIndex: The index of the object to be removed of type DataloggerIndex.
      :rtype: A Boolean value indicating success with True, False otherwise.

   .. py:method:: removeResponsePAZ(idx)

      :param idx: An integer index of the object to be removed.
      :rtype: A Boolean value indicating success with True, False otherwise.

   .. py:method:: removeResponsePAZ(responsePAZIndex);

      :param responsePAZIndex: The index of the object to be removed of type ResponsePAZIndex.
      :rtype: A Boolean value indicating success with True, False otherwise.

   .. py:method:: removeResponseFIR(idx)

      :param idx: An integer index of the object to be removed.
      :rtype: A Boolean value indicating success with True, False otherwise.

   .. py:method:: removeResponseFIR(responseFIRIndex);

      :param responseFIRIndex: The index of the object to be removed of type ResponseFIRIndex.
      :rtype: A Boolean value indicating success with True, False otherwise.

   .. py:method:: removeResponseIIR(idx)

      :param idx: An integer index of the object to be removed.
      :rtype: A Boolean value indicating success with True, False otherwise.

   .. py:method:: removeResponseIIR(responseIIRIndex);

      :param responseIIRIndex: The index of the object to be removed of type ResponseIIRIndex.
      :rtype: A Boolean value indicating success with True, False otherwise.

   .. py:method:: removeResponsePolynomial(idx)

      :param idx: An integer index of the object to be removed.
      :rtype: A Boolean value indicating success with True, False otherwise.

   .. py:method:: removeResponsePolynomial(responsePolynomialIndex);

      :param responsePolynomialIndex: The index of the object to be removed of type ResponsePolynomialIndex.
      :rtype: A Boolean value indicating success with True, False otherwise.

   .. py:method:: removeResponseFAP(idx)

      :param idx: An integer index of the object to be removed.
      :rtype: A Boolean value indicating success with True, False otherwise.

   .. py:method:: removeResponseFAP(responseFAPIndex);

      :param responseFAPIndex: The index of the object to be removed of type ResponseFAPIndex.
      :rtype: A Boolean value indicating success with True, False otherwise.

   .. py:method:: removeNetwork(idx)

      :param idx: An integer index of the object to be removed.
      :rtype: A Boolean value indicating success with True, False otherwise.

   .. py:method:: removeNetwork(networkIndex);

      :param networkIndex: The index of the object to be removed of type NetworkIndex.
      :rtype: A Boolean value indicating success with True, False otherwise.

   .. py:method:: stationGroupCount()

      :rtype: integer value indicating the number of child objects.

      Returns the number of StationGroup child objects.

   .. py:method:: auxDeviceCount()

      :rtype: integer value indicating the number of child objects.

      Returns the number of AuxDevice child objects.

   .. py:method:: sensorCount()

      :rtype: integer value indicating the number of child objects.

      Returns the number of Sensor child objects.

   .. py:method:: dataloggerCount()

      :rtype: integer value indicating the number of child objects.

      Returns the number of Datalogger child objects.

   .. py:method:: responsePAZCount()

      :rtype: integer value indicating the number of child objects.

      Returns the number of ResponsePAZ child objects.

   .. py:method:: responseFIRCount()

      :rtype: integer value indicating the number of child objects.

      Returns the number of ResponseFIR child objects.

   .. py:method:: responseIIRCount()

      :rtype: integer value indicating the number of child objects.

      Returns the number of ResponseIIR child objects.

   .. py:method:: responsePolynomialCount()

      :rtype: integer value indicating the number of child objects.

      Returns the number of ResponsePolynomial child objects.

   .. py:method:: responseFAPCount()

      :rtype: integer value indicating the number of child objects.

      Returns the number of ResponseFAP child objects.

   .. py:method:: networkCount()

      :rtype: integer value indicating the number of child objects.

      Returns the number of Network child objects.

   .. py:method:: stationGroup(idx)

      :param idx: An integer index of the object to be returned.
      :rtype: Object of type :ref:`StationGroup <api-python-datamodel-stationgroup>`.

      Returns the StationGroup at index idx.

   .. py:method:: stationGroup(stationGroupIndex)

      :param stationGroupIndex: The index of the object to be removed of type StationGroupIndex.
      :rtype: Object of type :ref:`StationGroup <api-python-datamodel-stationgroup>`.

      Returns the StationGroup at given index. The indexes of all child objects
      are compared by value which makes this function slower than the direct
      integer index look-up.

   .. py:method:: auxDevice(idx)

      :param idx: An integer index of the object to be returned.
      :rtype: Object of type :ref:`AuxDevice <api-python-datamodel-auxdevice>`.

      Returns the AuxDevice at index idx.

   .. py:method:: auxDevice(auxDeviceIndex)

      :param auxDeviceIndex: The index of the object to be removed of type AuxDeviceIndex.
      :rtype: Object of type :ref:`AuxDevice <api-python-datamodel-auxdevice>`.

      Returns the AuxDevice at given index. The indexes of all child objects
      are compared by value which makes this function slower than the direct
      integer index look-up.

   .. py:method:: sensor(idx)

      :param idx: An integer index of the object to be returned.
      :rtype: Object of type :ref:`Sensor <api-python-datamodel-sensor>`.

      Returns the Sensor at index idx.

   .. py:method:: sensor(sensorIndex)

      :param sensorIndex: The index of the object to be removed of type SensorIndex.
      :rtype: Object of type :ref:`Sensor <api-python-datamodel-sensor>`.

      Returns the Sensor at given index. The indexes of all child objects
      are compared by value which makes this function slower than the direct
      integer index look-up.

   .. py:method:: datalogger(idx)

      :param idx: An integer index of the object to be returned.
      :rtype: Object of type :ref:`Datalogger <api-python-datamodel-datalogger>`.

      Returns the Datalogger at index idx.

   .. py:method:: datalogger(dataloggerIndex)

      :param dataloggerIndex: The index of the object to be removed of type DataloggerIndex.
      :rtype: Object of type :ref:`Datalogger <api-python-datamodel-datalogger>`.

      Returns the Datalogger at given index. The indexes of all child objects
      are compared by value which makes this function slower than the direct
      integer index look-up.

   .. py:method:: responsePAZ(idx)

      :param idx: An integer index of the object to be returned.
      :rtype: Object of type :ref:`ResponsePAZ <api-python-datamodel-responsepaz>`.

      Returns the ResponsePAZ at index idx.

   .. py:method:: responsePAZ(responsePAZIndex)

      :param responsePAZIndex: The index of the object to be removed of type ResponsePAZIndex.
      :rtype: Object of type :ref:`ResponsePAZ <api-python-datamodel-responsepaz>`.

      Returns the ResponsePAZ at given index. The indexes of all child objects
      are compared by value which makes this function slower than the direct
      integer index look-up.

   .. py:method:: responseFIR(idx)

      :param idx: An integer index of the object to be returned.
      :rtype: Object of type :ref:`ResponseFIR <api-python-datamodel-responsefir>`.

      Returns the ResponseFIR at index idx.

   .. py:method:: responseFIR(responseFIRIndex)

      :param responseFIRIndex: The index of the object to be removed of type ResponseFIRIndex.
      :rtype: Object of type :ref:`ResponseFIR <api-python-datamodel-responsefir>`.

      Returns the ResponseFIR at given index. The indexes of all child objects
      are compared by value which makes this function slower than the direct
      integer index look-up.

   .. py:method:: responseIIR(idx)

      :param idx: An integer index of the object to be returned.
      :rtype: Object of type :ref:`ResponseIIR <api-python-datamodel-responseiir>`.

      Returns the ResponseIIR at index idx.

   .. py:method:: responseIIR(responseIIRIndex)

      :param responseIIRIndex: The index of the object to be removed of type ResponseIIRIndex.
      :rtype: Object of type :ref:`ResponseIIR <api-python-datamodel-responseiir>`.

      Returns the ResponseIIR at given index. The indexes of all child objects
      are compared by value which makes this function slower than the direct
      integer index look-up.

   .. py:method:: responsePolynomial(idx)

      :param idx: An integer index of the object to be returned.
      :rtype: Object of type :ref:`ResponsePolynomial <api-python-datamodel-responsepolynomial>`.

      Returns the ResponsePolynomial at index idx.

   .. py:method:: responsePolynomial(responsePolynomialIndex)

      :param responsePolynomialIndex: The index of the object to be removed of type ResponsePolynomialIndex.
      :rtype: Object of type :ref:`ResponsePolynomial <api-python-datamodel-responsepolynomial>`.

      Returns the ResponsePolynomial at given index. The indexes of all child objects
      are compared by value which makes this function slower than the direct
      integer index look-up.

   .. py:method:: responseFAP(idx)

      :param idx: An integer index of the object to be returned.
      :rtype: Object of type :ref:`ResponseFAP <api-python-datamodel-responsefap>`.

      Returns the ResponseFAP at index idx.

   .. py:method:: responseFAP(responseFAPIndex)

      :param responseFAPIndex: The index of the object to be removed of type ResponseFAPIndex.
      :rtype: Object of type :ref:`ResponseFAP <api-python-datamodel-responsefap>`.

      Returns the ResponseFAP at given index. The indexes of all child objects
      are compared by value which makes this function slower than the direct
      integer index look-up.

   .. py:method:: network(idx)

      :param idx: An integer index of the object to be returned.
      :rtype: Object of type :ref:`Network <api-python-datamodel-network>`.

      Returns the Network at index idx.

   .. py:method:: network(networkIndex)

      :param networkIndex: The index of the object to be removed of type NetworkIndex.
      :rtype: Object of type :ref:`Network <api-python-datamodel-network>`.

      Returns the Network at given index. The indexes of all child objects
      are compared by value which makes this function slower than the direct
      integer index look-up.

   .. py:method:: findStationGroup(publicID)

      :param publicID: The publicID of the object to find.
      :rtype: Object of type :ref:`StationGroup <api-python-datamodel-stationgroup>`.

      Returns the child object with a certain publicID, None otherwise.

   .. py:method:: findAuxDevice(publicID)

      :param publicID: The publicID of the object to find.
      :rtype: Object of type :ref:`AuxDevice <api-python-datamodel-auxdevice>`.

      Returns the child object with a certain publicID, None otherwise.

   .. py:method:: findSensor(publicID)

      :param publicID: The publicID of the object to find.
      :rtype: Object of type :ref:`Sensor <api-python-datamodel-sensor>`.

      Returns the child object with a certain publicID, None otherwise.

   .. py:method:: findDatalogger(publicID)

      :param publicID: The publicID of the object to find.
      :rtype: Object of type :ref:`Datalogger <api-python-datamodel-datalogger>`.

      Returns the child object with a certain publicID, None otherwise.

   .. py:method:: findResponsePAZ(publicID)

      :param publicID: The publicID of the object to find.
      :rtype: Object of type :ref:`ResponsePAZ <api-python-datamodel-responsepaz>`.

      Returns the child object with a certain publicID, None otherwise.

   .. py:method:: findResponseFIR(publicID)

      :param publicID: The publicID of the object to find.
      :rtype: Object of type :ref:`ResponseFIR <api-python-datamodel-responsefir>`.

      Returns the child object with a certain publicID, None otherwise.

   .. py:method:: findResponseIIR(publicID)

      :param publicID: The publicID of the object to find.
      :rtype: Object of type :ref:`ResponseIIR <api-python-datamodel-responseiir>`.

      Returns the child object with a certain publicID, None otherwise.

   .. py:method:: findResponsePolynomial(publicID)

      :param publicID: The publicID of the object to find.
      :rtype: Object of type :ref:`ResponsePolynomial <api-python-datamodel-responsepolynomial>`.

      Returns the child object with a certain publicID, None otherwise.

   .. py:method:: findResponseFAP(publicID)

      :param publicID: The publicID of the object to find.
      :rtype: Object of type :ref:`ResponseFAP <api-python-datamodel-responsefap>`.

      Returns the child object with a certain publicID, None otherwise.

   .. py:method:: findNetwork(publicID)

      :param publicID: The publicID of the object to find.
      :rtype: Object of type :ref:`Network <api-python-datamodel-network>`.

      Returns the child object with a certain publicID, None otherwise.

   .. py:method:: assign(other)

      This method implements the :ref:`Object <api-python-datamodel-object>` interface.

   .. py:method:: attachTo(parent)

      This method implements the :ref:`Object <api-python-datamodel-object>` interface.

   .. py:method:: detachFrom(parent)

      This method implements the :ref:`Object <api-python-datamodel-object>` interface.

   .. py:method:: detach()

      This method implements the :ref:`Object <api-python-datamodel-object>` interface.

   .. py:method:: clone()

      :rtype: A cloned Inventory.

      Returns a new instance that is a clone of the current instance. Child
      objects are being ignored.


   .. py:method:: updateChild(ref)

      :param ref: A child object derived from class Object.
      :rtype: A Boolean flag indicating success with True, False otherwise

      This method takes the passed reference object and searches for a child
      with the same publicID (if derived from :ref:`PublicObject <api-python-datamodel-publicobject>`)
      or the same index (if derived from :ref:`Object <api-python-datamodel-object>`).
      The the child was found the reference objects attributes are copied to
      the child object. Children of child are being ignored during this operation.
      This method implements the :ref:`PublicObject <api-python-datamodel-publicobject>` interface.


   .. py:method:: accept(visitor)

      :param visitor: A visitor.

      This method implements the :ref:`PublicObject <api-python-datamodel-publicobject>` interface.

.. _api-python-datamodel-journalentry:

JournalEntry
............................................................

.. py:class:: JournalEntry

   Inherits :ref:`Object <api-python-datamodel-object>`.


   **Parents**:

   - ``journaling`` -- :ref:`Journaling <api-python-datamodel-journaling>`

   **Attributes**:

   - ``created`` -- seiscomp.core.Time (optional)
   - ``objectID`` -- string
   - ``sender`` -- string
   - ``action`` -- string
   - ``parameters`` -- string

   **Methods**:

   .. py:staticmethod:: Cast(obj)

      :param obj: The object to be casted.
      :rtype: An object of type JournalEntry if the cast was successful,
              None otherwise.

      Cast an arbitrary object to JournalEntry if the internal wrapped
      representation is an JournalEntry object. The cast is important if
      instances of type :ref:`Object <api-python-datamodel-object>`
      are passed to methods which need access to the real type.



   .. py:method:: equal(other)

      :param other: Another object of type JournalEntry to compare this
                    instance to
      :rtype: A Boolean value indicating True if both objects are equal or
              False otherwise.

      Compares two objects without its child objects. Both objects are compared
      by value.

   .. py:method:: setCreated(created)

      :param created: seiscomp.core.Time

   .. py:method:: created()

      :rtype: seiscomp.core.Time

      .. note::

         As this attribute is optional, this method throws a ValueError if
         the value of the attribute is not set.

   .. py:method:: setObjectID(objectID)

      :param objectID: string

   .. py:method:: objectID()

      :rtype: string

   .. py:method:: setSender(sender)

      :param sender: string

   .. py:method:: sender()

      :rtype: string

   .. py:method:: setAction(action)

      :param action: string

   .. py:method:: action()

      :rtype: string

   .. py:method:: setParameters(parameters)

      :param parameters: string

   .. py:method:: parameters()

      :rtype: string

   .. py:method:: journaling()

      :rtype: Journaling

      Returns the parent Journaling if available. Returns None
      if the parent is not a Journaling. This is a convenience wrapper
      for parent().

   .. py:method:: assign(other)

      This method implements the :ref:`Object <api-python-datamodel-object>` interface.

   .. py:method:: attachTo(parent)

      This method implements the :ref:`Object <api-python-datamodel-object>` interface.

   .. py:method:: detachFrom(parent)

      This method implements the :ref:`Object <api-python-datamodel-object>` interface.

   .. py:method:: detach()

      This method implements the :ref:`Object <api-python-datamodel-object>` interface.

   .. py:method:: clone()

      :rtype: A cloned JournalEntry.

      Returns a new instance that is a clone of the current instance. Child
      objects are being ignored.


   .. py:method:: accept(visitor)

      :param visitor: A visitor.

      This method implements the :ref:`PublicObject <api-python-datamodel-publicobject>` interface.

.. _api-python-datamodel-journaling:

Journaling
............................................................

.. py:class:: Journaling

   Inherits :ref:`PublicObject <api-python-datamodel-publicobject>`.


   **Children**:

   - ``journalEntry`` -- :ref:`JournalEntry <api-python-datamodel-journalentry>`

   **Attributes**:

   - ``publicID``: string

   **Methods**:

   .. py:staticmethod:: Cast(obj)

      :param obj: The object to be casted.
      :rtype: An object of type Journaling if the cast was successful,
              None otherwise.

      Cast an arbitrary object to Journaling if the internal wrapped
      representation is an Journaling object. The cast is important if
      instances of type :ref:`Object <api-python-datamodel-object>`
      are passed to methods which need access to the real type.



   .. py:method:: equal(other)

      :param other: Another object of type Journaling to compare this
                    instance to
      :rtype: A Boolean value indicating True if both objects are equal or
              False otherwise.

      Compares two objects without its child objects. Both objects are compared
      by value.

   .. py:method:: add(journalEntry)

      :param journalEntry: Object of type :ref:`JournalEntry <api-python-datamodel-journalentry>`
      :rtype: A Boolean value indicating success with True, False otherwise.

      Adds a JournalEntry object to Journaling. The object is not
      copied but managed by this instance. Any change to the passed object
      will also change the child.

   .. py:method:: remove(journalEntry)

      :param journalEntry: Object of type :ref:`JournalEntry <api-python-datamodel-journalentry>`
      :rtype: A Boolean value indicating success with True, False otherwise.

      Removes a previously added JournalEntry object from Journaling.

   .. py:method:: removeJournalEntry(idx)

      :param idx: An integer index of the object to be removed.
      :rtype: A Boolean value indicating success with True, False otherwise.

   .. py:method:: journalEntryCount()

      :rtype: integer value indicating the number of child objects.

      Returns the number of JournalEntry child objects.

   .. py:method:: journalEntry(idx)

      :param idx: An integer index of the object to be returned.
      :rtype: Object of type :ref:`JournalEntry <api-python-datamodel-journalentry>`.

      Returns the JournalEntry at index idx.

   .. py:method:: findJournalEntry(journalEntry)

      :param journalEntry: Reference object of type :ref:`JournalEntry <api-python-datamodel-journalentry>`.
      :rtype: Object of type :ref:`JournalEntry <api-python-datamodel-journalentry>`.

      Returns the child object with equals the passed object, None otherwise.

   .. py:method:: assign(other)

      This method implements the :ref:`Object <api-python-datamodel-object>` interface.

   .. py:method:: attachTo(parent)

      This method implements the :ref:`Object <api-python-datamodel-object>` interface.

   .. py:method:: detachFrom(parent)

      This method implements the :ref:`Object <api-python-datamodel-object>` interface.

   .. py:method:: detach()

      This method implements the :ref:`Object <api-python-datamodel-object>` interface.

   .. py:method:: clone()

      :rtype: A cloned Journaling.

      Returns a new instance that is a clone of the current instance. Child
      objects are being ignored.


   .. py:method:: updateChild(ref)

      :param ref: A child object derived from class Object.
      :rtype: A Boolean flag indicating success with True, False otherwise

      This method takes the passed reference object and searches for a child
      with the same publicID (if derived from :ref:`PublicObject <api-python-datamodel-publicobject>`)
      or the same index (if derived from :ref:`Object <api-python-datamodel-object>`).
      The the child was found the reference objects attributes are copied to
      the child object. Children of child are being ignored during this operation.
      This method implements the :ref:`PublicObject <api-python-datamodel-publicobject>` interface.


   .. py:method:: accept(visitor)

      :param visitor: A visitor.

      This method implements the :ref:`PublicObject <api-python-datamodel-publicobject>` interface.

.. _api-python-datamodel-magnitude:

Magnitude
............................................................

.. py:class:: Magnitude

   Inherits :ref:`PublicObject <api-python-datamodel-publicobject>`.

   Describes a magnitude which can, but does not need to be associated with
   an origin. Association with an origin is expressed with the optional
   attribute originID. It is either a combination of different magnitude
   estimations, or it represents the reported magnitude for the given event.

   **Parents**:

   - ``origin`` -- :ref:`Origin <api-python-datamodel-origin>`

   **Children**:

   - ``comment`` -- :ref:`Comment <api-python-datamodel-comment>`
   - ``stationMagnitudeContribution`` -- :ref:`StationMagnitudeContribution <api-python-datamodel-stationmagnitudecontribution>`

   **Attributes**:

   - ``publicID``: string
   - ``magnitude`` -- :ref:`RealQuantity <api-python-datamodel-realquantity>`
   - ``type`` -- string
   - ``originID`` -- string
   - ``methodID`` -- string
   - ``stationCount`` -- int (optional)
   - ``azimuthalGap`` -- float (optional)
   - ``evaluationStatus`` -- :ref:`EvaluationStatus <api-python-datamodel-evaluationstatus>` (optional)
   - ``creationInfo`` -- :ref:`CreationInfo <api-python-datamodel-creationinfo>` (optional)

   **Referenced by**:

   - :func:`Event.preferredMagnitudeID`
   - :func:`MomentTensor.momentMagnitudeID`
   - :func:`StationMagnitudeContribution.stationMagnitudeID`

   **Methods**:

   .. py:staticmethod:: Cast(obj)

      :param obj: The object to be casted.
      :rtype: An object of type Magnitude if the cast was successful,
              None otherwise.

      Cast an arbitrary object to Magnitude if the internal wrapped
      representation is an Magnitude object. The cast is important if
      instances of type :ref:`Object <api-python-datamodel-object>`
      are passed to methods which need access to the real type.



   .. py:staticmethod:: Create()

      :rtype: A new object of type Magnitude.

      Creates and registers (if enabled) a Magnitude instance. The
      publicID is auto-generated.

   .. py:staticmethod:: Create(publicID)

      :rtype: A new object of type Magnitude.

      Creates and registers (if enabled) a Magnitude instance with
      passed publicID.

   .. py:method:: equal(other)

      :param other: Another object of type Magnitude to compare this
                    instance to
      :rtype: A Boolean value indicating True if both objects are equal or
              False otherwise.

      Compares two objects without its child objects. Both objects are compared
      by value.

   .. py:method:: setMagnitude(magnitude)

      :param magnitude: :ref:`RealQuantity <api-python-datamodel-realquantity>`

      Resulting magnitude value from combining values of type StationMagnitude.
      If no estimations are available, this value can represent the reported
      magnitude.

   .. py:method:: magnitude()

      :rtype: :ref:`RealQuantity <api-python-datamodel-realquantity>`

   .. py:method:: setType(type)

      :param type: string

      Describes the type of magnitude. This is a free\-text field because
      it is impossible to cover all existing magnitude type designations
      with an enumeration. Possible values are unspecified magnitude \(M\),
      local magnitude \(ML\), body wave magnitude \(Mb\),
      surface wave magnitude \(MS\), moment magnitude \(Mw\),
      duration magnitude \(Md\), coda magnitude \(Mc\), MH, Mwp, M50, M100, etc.

   .. py:method:: type()

      :rtype: string

   .. py:method:: setOriginID(originID)

      :param originID: string

      Reference to an origin's publicID if the magnitude has an associated Origin.

   .. py:method:: originID()

      :rtype: string

   .. py:method:: setMethodID(methodID)

      :param methodID: string

      Identifies the method of magnitude estimation. Users should avoid to
      give contradictory information in methodID and type.

   .. py:method:: methodID()

      :rtype: string

   .. py:method:: setStationCount(stationCount)

      :param stationCount: int

      Number of used stations for this magnitude computation.

   .. py:method:: stationCount()

      :rtype: int

      .. note::

         As this attribute is optional, this method throws a ValueError if
         the value of the attribute is not set.

   .. py:method:: setAzimuthalGap(azimuthalGap)

      :param azimuthalGap: float

      Azimuthal gap for this magnitude computation in degrees.

   .. py:method:: azimuthalGap()

      :rtype: float

      .. note::

         As this attribute is optional, this method throws a ValueError if
         the value of the attribute is not set.

   .. py:method:: setEvaluationStatus(evaluationStatus)

      :param evaluationStatus: EvaluationStatus

      Evaluation status of Magnitude.

   .. py:method:: evaluationStatus()

      :rtype: EvaluationStatus

      .. note::

         As this attribute is optional, this method throws a ValueError if
         the value of the attribute is not set.

   .. py:method:: setCreationInfo(creationInfo)

      :param creationInfo: :ref:`CreationInfo <api-python-datamodel-creationinfo>`

      CreationInfo for the Magnitude object.

   .. py:method:: creationInfo()

      :rtype: :ref:`CreationInfo <api-python-datamodel-creationinfo>`

      .. note::

         As this attribute is optional, this method throws a ValueError if
         the value of the attribute is not set.

   .. py:method:: add(comment)

      :param comment: Object of type :ref:`Comment <api-python-datamodel-comment>`
      :rtype: A Boolean value indicating success with True, False otherwise.

      Adds a Comment object to Magnitude. The object is not
      copied but managed by this instance. Any change to the passed object
      will also change the child.

   .. py:method:: add(stationMagnitudeContribution)

      :param stationMagnitudeContribution: Object of type :ref:`StationMagnitudeContribution <api-python-datamodel-stationmagnitudecontribution>`
      :rtype: A Boolean value indicating success with True, False otherwise.

      Adds a StationMagnitudeContribution object to Magnitude. The object is not
      copied but managed by this instance. Any change to the passed object
      will also change the child.

   .. py:method:: remove(comment)

      :param comment: Object of type :ref:`Comment <api-python-datamodel-comment>`
      :rtype: A Boolean value indicating success with True, False otherwise.

      Removes a previously added Comment object from Magnitude.

   .. py:method:: remove(stationMagnitudeContribution)

      :param stationMagnitudeContribution: Object of type :ref:`StationMagnitudeContribution <api-python-datamodel-stationmagnitudecontribution>`
      :rtype: A Boolean value indicating success with True, False otherwise.

      Removes a previously added StationMagnitudeContribution object from Magnitude.

   .. py:method:: removeComment(idx)

      :param idx: An integer index of the object to be removed.
      :rtype: A Boolean value indicating success with True, False otherwise.

   .. py:method:: removeComment(commentIndex);

      :param commentIndex: The index of the object to be removed of type CommentIndex.
      :rtype: A Boolean value indicating success with True, False otherwise.

   .. py:method:: removeStationMagnitudeContribution(idx)

      :param idx: An integer index of the object to be removed.
      :rtype: A Boolean value indicating success with True, False otherwise.

   .. py:method:: removeStationMagnitudeContribution(stationMagnitudeContributionIndex);

      :param stationMagnitudeContributionIndex: The index of the object to be removed of type StationMagnitudeContributionIndex.
      :rtype: A Boolean value indicating success with True, False otherwise.

   .. py:method:: commentCount()

      :rtype: integer value indicating the number of child objects.

      Returns the number of Comment child objects.

   .. py:method:: stationMagnitudeContributionCount()

      :rtype: integer value indicating the number of child objects.

      Returns the number of StationMagnitudeContribution child objects.

   .. py:method:: comment(idx)

      :param idx: An integer index of the object to be returned.
      :rtype: Object of type :ref:`Comment <api-python-datamodel-comment>`.

      Returns the Comment at index idx.

   .. py:method:: comment(commentIndex)

      :param commentIndex: The index of the object to be removed of type CommentIndex.
      :rtype: Object of type :ref:`Comment <api-python-datamodel-comment>`.

      Returns the Comment at given index. The indexes of all child objects
      are compared by value which makes this function slower than the direct
      integer index look-up.

   .. py:method:: stationMagnitudeContribution(idx)

      :param idx: An integer index of the object to be returned.
      :rtype: Object of type :ref:`StationMagnitudeContribution <api-python-datamodel-stationmagnitudecontribution>`.

      Returns the StationMagnitudeContribution at index idx.

   .. py:method:: stationMagnitudeContribution(stationMagnitudeContributionIndex)

      :param stationMagnitudeContributionIndex: The index of the object to be removed of type StationMagnitudeContributionIndex.
      :rtype: Object of type :ref:`StationMagnitudeContribution <api-python-datamodel-stationmagnitudecontribution>`.

      Returns the StationMagnitudeContribution at given index. The indexes of all child objects
      are compared by value which makes this function slower than the direct
      integer index look-up.

   .. py:method:: origin()

      :rtype: Origin

      Returns the parent Origin if available. Returns None
      if the parent is not a Origin. This is a convenience wrapper
      for parent().

   .. py:method:: assign(other)

      This method implements the :ref:`Object <api-python-datamodel-object>` interface.

   .. py:method:: attachTo(parent)

      This method implements the :ref:`Object <api-python-datamodel-object>` interface.

   .. py:method:: detachFrom(parent)

      This method implements the :ref:`Object <api-python-datamodel-object>` interface.

   .. py:method:: detach()

      This method implements the :ref:`Object <api-python-datamodel-object>` interface.

   .. py:method:: clone()

      :rtype: A cloned Magnitude.

      Returns a new instance that is a clone of the current instance. Child
      objects are being ignored.


   .. py:method:: updateChild(ref)

      :param ref: A child object derived from class Object.
      :rtype: A Boolean flag indicating success with True, False otherwise

      This method takes the passed reference object and searches for a child
      with the same publicID (if derived from :ref:`PublicObject <api-python-datamodel-publicobject>`)
      or the same index (if derived from :ref:`Object <api-python-datamodel-object>`).
      The the child was found the reference objects attributes are copied to
      the child object. Children of child are being ignored during this operation.
      This method implements the :ref:`PublicObject <api-python-datamodel-publicobject>` interface.


   .. py:method:: accept(visitor)

      :param visitor: A visitor.

      This method implements the :ref:`PublicObject <api-python-datamodel-publicobject>` interface.

.. _api-python-datamodel-momenttensor:

MomentTensor
............................................................

.. py:class:: MomentTensor

   Inherits :ref:`PublicObject <api-python-datamodel-publicobject>`.

   This class represents a moment tensor solution for an event. It is an
   optional part of a FocalMechanism description.

   **Parents**:

   - ``focalMechanism`` -- :ref:`FocalMechanism <api-python-datamodel-focalmechanism>`

   **Children**:

   - ``comment`` -- :ref:`Comment <api-python-datamodel-comment>`
   - ``dataUsed`` -- :ref:`DataUsed <api-python-datamodel-dataused>`
   - ``momentTensorPhaseSetting`` -- :ref:`MomentTensorPhaseSetting <api-python-datamodel-momenttensorphasesetting>`
   - ``momentTensorStationContribution`` -- :ref:`MomentTensorStationContribution <api-python-datamodel-momenttensorstationcontribution>`

   **Attributes**:

   - ``publicID``: string
   - ``derivedOriginID`` -- string
   - ``momentMagnitudeID`` -- string
   - ``scalarMoment`` -- :ref:`RealQuantity <api-python-datamodel-realquantity>` (optional)
   - ``tensor`` -- :ref:`Tensor <api-python-datamodel-tensor>` (optional)
   - ``variance`` -- float (optional)
   - ``varianceReduction`` -- float (optional)
   - ``doubleCouple`` -- float (optional)
   - ``clvd`` -- float (optional)
   - ``iso`` -- float (optional)
   - ``greensFunctionID`` -- string
   - ``filterID`` -- string
   - ``sourceTimeFunction`` -- :ref:`SourceTimeFunction <api-python-datamodel-sourcetimefunction>` (optional)
   - ``methodID`` -- string
   - ``method`` -- :ref:`MomentTensorMethod <api-python-datamodel-momenttensormethod>` (optional)
   - ``status`` -- :ref:`MomentTensorStatus <api-python-datamodel-momenttensorstatus>` (optional)
   - ``cmtName`` -- string
   - ``cmtVersion`` -- string
   - ``creationInfo`` -- :ref:`CreationInfo <api-python-datamodel-creationinfo>` (optional)

   **Methods**:

   .. py:staticmethod:: Cast(obj)

      :param obj: The object to be casted.
      :rtype: An object of type MomentTensor if the cast was successful,
              None otherwise.

      Cast an arbitrary object to MomentTensor if the internal wrapped
      representation is an MomentTensor object. The cast is important if
      instances of type :ref:`Object <api-python-datamodel-object>`
      are passed to methods which need access to the real type.



   .. py:staticmethod:: Create()

      :rtype: A new object of type MomentTensor.

      Creates and registers (if enabled) a MomentTensor instance. The
      publicID is auto-generated.

   .. py:staticmethod:: Create(publicID)

      :rtype: A new object of type MomentTensor.

      Creates and registers (if enabled) a MomentTensor instance with
      passed publicID.

   .. py:method:: equal(other)

      :param other: Another object of type MomentTensor to compare this
                    instance to
      :rtype: A Boolean value indicating True if both objects are equal or
              False otherwise.

      Compares two objects without its child objects. Both objects are compared
      by value.

   .. py:method:: setDerivedOriginID(derivedOriginID)

      :param derivedOriginID: string

      Refers to the publicID of the Origin derived in the moment tensor inversion.

   .. py:method:: derivedOriginID()

      :rtype: string

   .. py:method:: setMomentMagnitudeID(momentMagnitudeID)

      :param momentMagnitudeID: string

      Refers to the publicID of the Magnitude object which represents the derived
      moment
      magnitude.

   .. py:method:: momentMagnitudeID()

      :rtype: string

   .. py:method:: setScalarMoment(scalarMoment)

      :param scalarMoment: :ref:`RealQuantity <api-python-datamodel-realquantity>`

      Scalar moment as derived in moment tensor inversion in Nm.

   .. py:method:: scalarMoment()

      :rtype: :ref:`RealQuantity <api-python-datamodel-realquantity>`

      .. note::

         As this attribute is optional, this method throws a ValueError if
         the value of the attribute is not set.

   .. py:method:: setTensor(tensor)

      :param tensor: :ref:`Tensor <api-python-datamodel-tensor>`

      Tensor object holding the moment tensor elements.

   .. py:method:: tensor()

      :rtype: :ref:`Tensor <api-python-datamodel-tensor>`

      .. note::

         As this attribute is optional, this method throws a ValueError if
         the value of the attribute is not set.

   .. py:method:: setVariance(variance)

      :param variance: float

      Variance of moment tensor inversion.

   .. py:method:: variance()

      :rtype: float

      .. note::

         As this attribute is optional, this method throws a ValueError if
         the value of the attribute is not set.

   .. py:method:: setVarianceReduction(varianceReduction)

      :param varianceReduction: float

      Variance reduction of moment tensor inversion, given in percent \(Dreger
      2003\). This is a
      goodness\-of\-fit measure.

   .. py:method:: varianceReduction()

      :rtype: float

      .. note::

         As this attribute is optional, this method throws a ValueError if
         the value of the attribute is not set.

   .. py:method:: setDoubleCouple(doubleCouple)

      :param doubleCouple: float

      Double couple parameter obtained from moment tensor inversion \(decimal
      fraction between 0
      and 1\).

   .. py:method:: doubleCouple()

      :rtype: float

      .. note::

         As this attribute is optional, this method throws a ValueError if
         the value of the attribute is not set.

   .. py:method:: setClvd(clvd)

      :param clvd: float

      CLVD \(compensated linear vector dipole\) parameter obtained from moment
      tensor inversion \(decimal
      fraction between 0 and 1\).

   .. py:method:: clvd()

      :rtype: float

      .. note::

         As this attribute is optional, this method throws a ValueError if
         the value of the attribute is not set.

   .. py:method:: setIso(iso)

      :param iso: float

      Isotropic part obtained from moment tensor inversion \(decimal fraction
      between 0 and 1\).

   .. py:method:: iso()

      :rtype: float

      .. note::

         As this attribute is optional, this method throws a ValueError if
         the value of the attribute is not set.

   .. py:method:: setGreensFunctionID(greensFunctionID)

      :param greensFunctionID: string

      Resource identifier of the Green's function used in moment tensor inversion.

   .. py:method:: greensFunctionID()

      :rtype: string

   .. py:method:: setFilterID(filterID)

      :param filterID: string

      Resource identifier of the filter setup used in moment tensor inversion.

   .. py:method:: filterID()

      :rtype: string

   .. py:method:: setSourceTimeFunction(sourceTimeFunction)

      :param sourceTimeFunction: :ref:`SourceTimeFunction <api-python-datamodel-sourcetimefunction>`

      Source time function used in moment\-tensor inversion.

   .. py:method:: sourceTimeFunction()

      :rtype: :ref:`SourceTimeFunction <api-python-datamodel-sourcetimefunction>`

      .. note::

         As this attribute is optional, this method throws a ValueError if
         the value of the attribute is not set.

   .. py:method:: setMethodID(methodID)

      :param methodID: string

      Resource identifier of the method used for moment\-tensor inversion.

   .. py:method:: methodID()

      :rtype: string

   .. py:method:: setMethod(method)

      :param method: MomentTensorMethod

      Moment tensor method used.

   .. py:method:: method()

      :rtype: MomentTensorMethod

      .. note::

         As this attribute is optional, this method throws a ValueError if
         the value of the attribute is not set.

   .. py:method:: setStatus(status)

      :param status: MomentTensorStatus

      Status of moment tensor.

   .. py:method:: status()

      :rtype: MomentTensorStatus

      .. note::

         As this attribute is optional, this method throws a ValueError if
         the value of the attribute is not set.

   .. py:method:: setCmtName(cmtName)

      :param cmtName: string

   .. py:method:: cmtName()

      :rtype: string

   .. py:method:: setCmtVersion(cmtVersion)

      :param cmtVersion: string

   .. py:method:: cmtVersion()

      :rtype: string

   .. py:method:: setCreationInfo(creationInfo)

      :param creationInfo: :ref:`CreationInfo <api-python-datamodel-creationinfo>`

      CreationInfo for the MomentTensor object.

   .. py:method:: creationInfo()

      :rtype: :ref:`CreationInfo <api-python-datamodel-creationinfo>`

      .. note::

         As this attribute is optional, this method throws a ValueError if
         the value of the attribute is not set.

   .. py:method:: add(comment)

      :param comment: Object of type :ref:`Comment <api-python-datamodel-comment>`
      :rtype: A Boolean value indicating success with True, False otherwise.

      Adds a Comment object to MomentTensor. The object is not
      copied but managed by this instance. Any change to the passed object
      will also change the child.

   .. py:method:: add(dataUsed)

      :param dataUsed: Object of type :ref:`DataUsed <api-python-datamodel-dataused>`
      :rtype: A Boolean value indicating success with True, False otherwise.

      Adds a DataUsed object to MomentTensor. The object is not
      copied but managed by this instance. Any change to the passed object
      will also change the child.

   .. py:method:: add(momentTensorPhaseSetting)

      :param momentTensorPhaseSetting: Object of type :ref:`MomentTensorPhaseSetting <api-python-datamodel-momenttensorphasesetting>`
      :rtype: A Boolean value indicating success with True, False otherwise.

      Adds a MomentTensorPhaseSetting object to MomentTensor. The object is not
      copied but managed by this instance. Any change to the passed object
      will also change the child.

   .. py:method:: add(momentTensorStationContribution)

      :param momentTensorStationContribution: Object of type :ref:`MomentTensorStationContribution <api-python-datamodel-momenttensorstationcontribution>`
      :rtype: A Boolean value indicating success with True, False otherwise.

      Adds a MomentTensorStationContribution object to MomentTensor. The object is not
      copied but managed by this instance. Any change to the passed object
      will also change the child.

   .. py:method:: remove(comment)

      :param comment: Object of type :ref:`Comment <api-python-datamodel-comment>`
      :rtype: A Boolean value indicating success with True, False otherwise.

      Removes a previously added Comment object from MomentTensor.

   .. py:method:: remove(dataUsed)

      :param dataUsed: Object of type :ref:`DataUsed <api-python-datamodel-dataused>`
      :rtype: A Boolean value indicating success with True, False otherwise.

      Removes a previously added DataUsed object from MomentTensor.

   .. py:method:: remove(momentTensorPhaseSetting)

      :param momentTensorPhaseSetting: Object of type :ref:`MomentTensorPhaseSetting <api-python-datamodel-momenttensorphasesetting>`
      :rtype: A Boolean value indicating success with True, False otherwise.

      Removes a previously added MomentTensorPhaseSetting object from MomentTensor.

   .. py:method:: remove(momentTensorStationContribution)

      :param momentTensorStationContribution: Object of type :ref:`MomentTensorStationContribution <api-python-datamodel-momenttensorstationcontribution>`
      :rtype: A Boolean value indicating success with True, False otherwise.

      Removes a previously added MomentTensorStationContribution object from MomentTensor.

   .. py:method:: removeComment(idx)

      :param idx: An integer index of the object to be removed.
      :rtype: A Boolean value indicating success with True, False otherwise.

   .. py:method:: removeComment(commentIndex);

      :param commentIndex: The index of the object to be removed of type CommentIndex.
      :rtype: A Boolean value indicating success with True, False otherwise.

   .. py:method:: removeDataUsed(idx)

      :param idx: An integer index of the object to be removed.
      :rtype: A Boolean value indicating success with True, False otherwise.

   .. py:method:: removeMomentTensorPhaseSetting(idx)

      :param idx: An integer index of the object to be removed.
      :rtype: A Boolean value indicating success with True, False otherwise.

   .. py:method:: removeMomentTensorPhaseSetting(momentTensorPhaseSettingIndex);

      :param momentTensorPhaseSettingIndex: The index of the object to be removed of type MomentTensorPhaseSettingIndex.
      :rtype: A Boolean value indicating success with True, False otherwise.

   .. py:method:: removeMomentTensorStationContribution(idx)

      :param idx: An integer index of the object to be removed.
      :rtype: A Boolean value indicating success with True, False otherwise.

   .. py:method:: commentCount()

      :rtype: integer value indicating the number of child objects.

      Returns the number of Comment child objects.

   .. py:method:: dataUsedCount()

      :rtype: integer value indicating the number of child objects.

      Returns the number of DataUsed child objects.

   .. py:method:: momentTensorPhaseSettingCount()

      :rtype: integer value indicating the number of child objects.

      Returns the number of MomentTensorPhaseSetting child objects.

   .. py:method:: momentTensorStationContributionCount()

      :rtype: integer value indicating the number of child objects.

      Returns the number of MomentTensorStationContribution child objects.

   .. py:method:: comment(idx)

      :param idx: An integer index of the object to be returned.
      :rtype: Object of type :ref:`Comment <api-python-datamodel-comment>`.

      Returns the Comment at index idx.

   .. py:method:: comment(commentIndex)

      :param commentIndex: The index of the object to be removed of type CommentIndex.
      :rtype: Object of type :ref:`Comment <api-python-datamodel-comment>`.

      Returns the Comment at given index. The indexes of all child objects
      are compared by value which makes this function slower than the direct
      integer index look-up.

   .. py:method:: dataUsed(idx)

      :param idx: An integer index of the object to be returned.
      :rtype: Object of type :ref:`DataUsed <api-python-datamodel-dataused>`.

      Returns the DataUsed at index idx.

   .. py:method:: momentTensorPhaseSetting(idx)

      :param idx: An integer index of the object to be returned.
      :rtype: Object of type :ref:`MomentTensorPhaseSetting <api-python-datamodel-momenttensorphasesetting>`.

      Returns the MomentTensorPhaseSetting at index idx.

   .. py:method:: momentTensorPhaseSetting(momentTensorPhaseSettingIndex)

      :param momentTensorPhaseSettingIndex: The index of the object to be removed of type MomentTensorPhaseSettingIndex.
      :rtype: Object of type :ref:`MomentTensorPhaseSetting <api-python-datamodel-momenttensorphasesetting>`.

      Returns the MomentTensorPhaseSetting at given index. The indexes of all child objects
      are compared by value which makes this function slower than the direct
      integer index look-up.

   .. py:method:: momentTensorStationContribution(idx)

      :param idx: An integer index of the object to be returned.
      :rtype: Object of type :ref:`MomentTensorStationContribution <api-python-datamodel-momenttensorstationcontribution>`.

      Returns the MomentTensorStationContribution at index idx.

   .. py:method:: findDataUsed(dataUsed)

      :param dataUsed: Reference object of type :ref:`DataUsed <api-python-datamodel-dataused>`.
      :rtype: Object of type :ref:`DataUsed <api-python-datamodel-dataused>`.

      Returns the child object with equals the passed object, None otherwise.

   .. py:method:: findMomentTensorStationContribution(publicID)

      :param publicID: The publicID of the object to find.
      :rtype: Object of type :ref:`MomentTensorStationContribution <api-python-datamodel-momenttensorstationcontribution>`.

      Returns the child object with a certain publicID, None otherwise.

   .. py:method:: focalMechanism()

      :rtype: FocalMechanism

      Returns the parent FocalMechanism if available. Returns None
      if the parent is not a FocalMechanism. This is a convenience wrapper
      for parent().

   .. py:method:: assign(other)

      This method implements the :ref:`Object <api-python-datamodel-object>` interface.

   .. py:method:: attachTo(parent)

      This method implements the :ref:`Object <api-python-datamodel-object>` interface.

   .. py:method:: detachFrom(parent)

      This method implements the :ref:`Object <api-python-datamodel-object>` interface.

   .. py:method:: detach()

      This method implements the :ref:`Object <api-python-datamodel-object>` interface.

   .. py:method:: clone()

      :rtype: A cloned MomentTensor.

      Returns a new instance that is a clone of the current instance. Child
      objects are being ignored.


   .. py:method:: updateChild(ref)

      :param ref: A child object derived from class Object.
      :rtype: A Boolean flag indicating success with True, False otherwise

      This method takes the passed reference object and searches for a child
      with the same publicID (if derived from :ref:`PublicObject <api-python-datamodel-publicobject>`)
      or the same index (if derived from :ref:`Object <api-python-datamodel-object>`).
      The the child was found the reference objects attributes are copied to
      the child object. Children of child are being ignored during this operation.
      This method implements the :ref:`PublicObject <api-python-datamodel-publicobject>` interface.


   .. py:method:: accept(visitor)

      :param visitor: A visitor.

      This method implements the :ref:`PublicObject <api-python-datamodel-publicobject>` interface.

.. _api-python-datamodel-momenttensorcomponentcontribution:

MomentTensorComponentContribution
............................................................

.. py:class:: MomentTensorComponentContribution

   Inherits :ref:`Object <api-python-datamodel-object>`.


   **Parents**:

   - ``momentTensorStationContribution`` -- :ref:`MomentTensorStationContribution <api-python-datamodel-momenttensorstationcontribution>`

   **Attributes**:

   - ``phaseCode`` -- string
   - ``component`` -- int
   - ``active`` -- boolean
   - ``weight`` -- float
   - ``timeShift`` -- float
   - ``dataTimeWindow`` -- float
   - ``misfit`` -- float (optional)
   - ``snr`` -- float (optional)

   **Methods**:

   .. py:staticmethod:: Cast(obj)

      :param obj: The object to be casted.
      :rtype: An object of type MomentTensorComponentContribution if the cast was successful,
              None otherwise.

      Cast an arbitrary object to MomentTensorComponentContribution if the internal wrapped
      representation is an MomentTensorComponentContribution object. The cast is important if
      instances of type :ref:`Object <api-python-datamodel-object>`
      are passed to methods which need access to the real type.



   .. py:method:: equal(other)

      :param other: Another object of type MomentTensorComponentContribution to compare this
                    instance to
      :rtype: A Boolean value indicating True if both objects are equal or
              False otherwise.

      Compares two objects without its child objects. Both objects are compared
      by value.

   .. py:method:: index()

      :rtype: The object's index of type MomentTensorComponentContributionIndex.

       Returns the objects index which is also used for the database as unique
       constraint.

   .. py:method:: equalIndex(lhs)

      :param lhs: :ref:`MomentTensorComponentContribution <api-python-datamodel-momenttensorcomponentcontribution>`
      :rtype: A Boolean value indicating True if both indexes are equal or
              False otherwise.

   .. py:method:: setPhaseCode(phaseCode)

      :param phaseCode: string

   .. py:method:: phaseCode()

      :rtype: string

   .. py:method:: setComponent(component)

      :param component: int

   .. py:method:: component()

      :rtype: int

   .. py:method:: setActive(active)

      :param active: boolean

   .. py:method:: active()

      :rtype: boolean

   .. py:method:: setWeight(weight)

      :param weight: float

   .. py:method:: weight()

      :rtype: float

   .. py:method:: setTimeShift(timeShift)

      :param timeShift: float

   .. py:method:: timeShift()

      :rtype: float

   .. py:method:: setDataTimeWindow(dataTimeWindow)

      :param dataTimeWindow: float

   .. py:method:: dataTimeWindow()

      :rtype: float

   .. py:method:: setMisfit(misfit)

      :param misfit: float

   .. py:method:: misfit()

      :rtype: float

      .. note::

         As this attribute is optional, this method throws a ValueError if
         the value of the attribute is not set.

   .. py:method:: setSnr(snr)

      :param snr: float

   .. py:method:: snr()

      :rtype: float

      .. note::

         As this attribute is optional, this method throws a ValueError if
         the value of the attribute is not set.

   .. py:method:: momentTensorStationContribution()

      :rtype: MomentTensorStationContribution

      Returns the parent MomentTensorStationContribution if available. Returns None
      if the parent is not a MomentTensorStationContribution. This is a convenience wrapper
      for parent().

   .. py:method:: assign(other)

      This method implements the :ref:`Object <api-python-datamodel-object>` interface.

   .. py:method:: attachTo(parent)

      This method implements the :ref:`Object <api-python-datamodel-object>` interface.

   .. py:method:: detachFrom(parent)

      This method implements the :ref:`Object <api-python-datamodel-object>` interface.

   .. py:method:: detach()

      This method implements the :ref:`Object <api-python-datamodel-object>` interface.

   .. py:method:: clone()

      :rtype: A cloned MomentTensorComponentContribution.

      Returns a new instance that is a clone of the current instance. Child
      objects are being ignored.


   .. py:method:: accept(visitor)

      :param visitor: A visitor.

      This method implements the :ref:`PublicObject <api-python-datamodel-publicobject>` interface.

.. _api-python-datamodel-momenttensorphasesetting:

MomentTensorPhaseSetting
............................................................

.. py:class:: MomentTensorPhaseSetting

   Inherits :ref:`Object <api-python-datamodel-object>`.


   **Parents**:

   - ``momentTensor`` -- :ref:`MomentTensor <api-python-datamodel-momenttensor>`

   **Attributes**:

   - ``code`` -- string
   - ``lowerPeriod`` -- float
   - ``upperPeriod`` -- float
   - ``minimumSNR`` -- float (optional)
   - ``maximumTimeShift`` -- float (optional)

   **Methods**:

   .. py:staticmethod:: Cast(obj)

      :param obj: The object to be casted.
      :rtype: An object of type MomentTensorPhaseSetting if the cast was successful,
              None otherwise.

      Cast an arbitrary object to MomentTensorPhaseSetting if the internal wrapped
      representation is an MomentTensorPhaseSetting object. The cast is important if
      instances of type :ref:`Object <api-python-datamodel-object>`
      are passed to methods which need access to the real type.



   .. py:method:: equal(other)

      :param other: Another object of type MomentTensorPhaseSetting to compare this
                    instance to
      :rtype: A Boolean value indicating True if both objects are equal or
              False otherwise.

      Compares two objects without its child objects. Both objects are compared
      by value.

   .. py:method:: index()

      :rtype: The object's index of type MomentTensorPhaseSettingIndex.

       Returns the objects index which is also used for the database as unique
       constraint.

   .. py:method:: equalIndex(lhs)

      :param lhs: :ref:`MomentTensorPhaseSetting <api-python-datamodel-momenttensorphasesetting>`
      :rtype: A Boolean value indicating True if both indexes are equal or
              False otherwise.

   .. py:method:: setCode(code)

      :param code: string

   .. py:method:: code()

      :rtype: string

   .. py:method:: setLowerPeriod(lowerPeriod)

      :param lowerPeriod: float

   .. py:method:: lowerPeriod()

      :rtype: float

   .. py:method:: setUpperPeriod(upperPeriod)

      :param upperPeriod: float

   .. py:method:: upperPeriod()

      :rtype: float

   .. py:method:: setMinimumSNR(minimumSNR)

      :param minimumSNR: float

   .. py:method:: minimumSNR()

      :rtype: float

      .. note::

         As this attribute is optional, this method throws a ValueError if
         the value of the attribute is not set.

   .. py:method:: setMaximumTimeShift(maximumTimeShift)

      :param maximumTimeShift: float

   .. py:method:: maximumTimeShift()

      :rtype: float

      .. note::

         As this attribute is optional, this method throws a ValueError if
         the value of the attribute is not set.

   .. py:method:: momentTensor()

      :rtype: MomentTensor

      Returns the parent MomentTensor if available. Returns None
      if the parent is not a MomentTensor. This is a convenience wrapper
      for parent().

   .. py:method:: assign(other)

      This method implements the :ref:`Object <api-python-datamodel-object>` interface.

   .. py:method:: attachTo(parent)

      This method implements the :ref:`Object <api-python-datamodel-object>` interface.

   .. py:method:: detachFrom(parent)

      This method implements the :ref:`Object <api-python-datamodel-object>` interface.

   .. py:method:: detach()

      This method implements the :ref:`Object <api-python-datamodel-object>` interface.

   .. py:method:: clone()

      :rtype: A cloned MomentTensorPhaseSetting.

      Returns a new instance that is a clone of the current instance. Child
      objects are being ignored.


   .. py:method:: accept(visitor)

      :param visitor: A visitor.

      This method implements the :ref:`PublicObject <api-python-datamodel-publicobject>` interface.

.. _api-python-datamodel-momenttensorstationcontribution:

MomentTensorStationContribution
............................................................

.. py:class:: MomentTensorStationContribution

   Inherits :ref:`PublicObject <api-python-datamodel-publicobject>`.


   **Parents**:

   - ``momentTensor`` -- :ref:`MomentTensor <api-python-datamodel-momenttensor>`

   **Children**:

   - ``momentTensorComponentContribution`` -- :ref:`MomentTensorComponentContribution <api-python-datamodel-momenttensorcomponentcontribution>`

   **Attributes**:

   - ``publicID``: string
   - ``active`` -- boolean
   - ``waveformID`` -- :ref:`WaveformStreamID <api-python-datamodel-waveformstreamid>` (optional)
   - ``weight`` -- float (optional)
   - ``timeShift`` -- float (optional)

   **Methods**:

   .. py:staticmethod:: Cast(obj)

      :param obj: The object to be casted.
      :rtype: An object of type MomentTensorStationContribution if the cast was successful,
              None otherwise.

      Cast an arbitrary object to MomentTensorStationContribution if the internal wrapped
      representation is an MomentTensorStationContribution object. The cast is important if
      instances of type :ref:`Object <api-python-datamodel-object>`
      are passed to methods which need access to the real type.



   .. py:staticmethod:: Create()

      :rtype: A new object of type MomentTensorStationContribution.

      Creates and registers (if enabled) a MomentTensorStationContribution instance. The
      publicID is auto-generated.

   .. py:staticmethod:: Create(publicID)

      :rtype: A new object of type MomentTensorStationContribution.

      Creates and registers (if enabled) a MomentTensorStationContribution instance with
      passed publicID.

   .. py:method:: equal(other)

      :param other: Another object of type MomentTensorStationContribution to compare this
                    instance to
      :rtype: A Boolean value indicating True if both objects are equal or
              False otherwise.

      Compares two objects without its child objects. Both objects are compared
      by value.

   .. py:method:: setActive(active)

      :param active: boolean

   .. py:method:: active()

      :rtype: boolean

   .. py:method:: setWaveformID(waveformID)

      :param waveformID: :ref:`WaveformStreamID <api-python-datamodel-waveformstreamid>`

   .. py:method:: waveformID()

      :rtype: :ref:`WaveformStreamID <api-python-datamodel-waveformstreamid>`

      .. note::

         As this attribute is optional, this method throws a ValueError if
         the value of the attribute is not set.

   .. py:method:: setWeight(weight)

      :param weight: float

   .. py:method:: weight()

      :rtype: float

      .. note::

         As this attribute is optional, this method throws a ValueError if
         the value of the attribute is not set.

   .. py:method:: setTimeShift(timeShift)

      :param timeShift: float

   .. py:method:: timeShift()

      :rtype: float

      .. note::

         As this attribute is optional, this method throws a ValueError if
         the value of the attribute is not set.

   .. py:method:: add(momentTensorComponentContribution)

      :param momentTensorComponentContribution: Object of type :ref:`MomentTensorComponentContribution <api-python-datamodel-momenttensorcomponentcontribution>`
      :rtype: A Boolean value indicating success with True, False otherwise.

      Adds a MomentTensorComponentContribution object to MomentTensorStationContribution. The object is not
      copied but managed by this instance. Any change to the passed object
      will also change the child.

   .. py:method:: remove(momentTensorComponentContribution)

      :param momentTensorComponentContribution: Object of type :ref:`MomentTensorComponentContribution <api-python-datamodel-momenttensorcomponentcontribution>`
      :rtype: A Boolean value indicating success with True, False otherwise.

      Removes a previously added MomentTensorComponentContribution object from MomentTensorStationContribution.

   .. py:method:: removeMomentTensorComponentContribution(idx)

      :param idx: An integer index of the object to be removed.
      :rtype: A Boolean value indicating success with True, False otherwise.

   .. py:method:: removeMomentTensorComponentContribution(momentTensorComponentContributionIndex);

      :param momentTensorComponentContributionIndex: The index of the object to be removed of type MomentTensorComponentContributionIndex.
      :rtype: A Boolean value indicating success with True, False otherwise.

   .. py:method:: momentTensorComponentContributionCount()

      :rtype: integer value indicating the number of child objects.

      Returns the number of MomentTensorComponentContribution child objects.

   .. py:method:: momentTensorComponentContribution(idx)

      :param idx: An integer index of the object to be returned.
      :rtype: Object of type :ref:`MomentTensorComponentContribution <api-python-datamodel-momenttensorcomponentcontribution>`.

      Returns the MomentTensorComponentContribution at index idx.

   .. py:method:: momentTensorComponentContribution(momentTensorComponentContributionIndex)

      :param momentTensorComponentContributionIndex: The index of the object to be removed of type MomentTensorComponentContributionIndex.
      :rtype: Object of type :ref:`MomentTensorComponentContribution <api-python-datamodel-momenttensorcomponentcontribution>`.

      Returns the MomentTensorComponentContribution at given index. The indexes of all child objects
      are compared by value which makes this function slower than the direct
      integer index look-up.

   .. py:method:: momentTensor()

      :rtype: MomentTensor

      Returns the parent MomentTensor if available. Returns None
      if the parent is not a MomentTensor. This is a convenience wrapper
      for parent().

   .. py:method:: assign(other)

      This method implements the :ref:`Object <api-python-datamodel-object>` interface.

   .. py:method:: attachTo(parent)

      This method implements the :ref:`Object <api-python-datamodel-object>` interface.

   .. py:method:: detachFrom(parent)

      This method implements the :ref:`Object <api-python-datamodel-object>` interface.

   .. py:method:: detach()

      This method implements the :ref:`Object <api-python-datamodel-object>` interface.

   .. py:method:: clone()

      :rtype: A cloned MomentTensorStationContribution.

      Returns a new instance that is a clone of the current instance. Child
      objects are being ignored.


   .. py:method:: updateChild(ref)

      :param ref: A child object derived from class Object.
      :rtype: A Boolean flag indicating success with True, False otherwise

      This method takes the passed reference object and searches for a child
      with the same publicID (if derived from :ref:`PublicObject <api-python-datamodel-publicobject>`)
      or the same index (if derived from :ref:`Object <api-python-datamodel-object>`).
      The the child was found the reference objects attributes are copied to
      the child object. Children of child are being ignored during this operation.
      This method implements the :ref:`PublicObject <api-python-datamodel-publicobject>` interface.


   .. py:method:: accept(visitor)

      :param visitor: A visitor.

      This method implements the :ref:`PublicObject <api-python-datamodel-publicobject>` interface.

.. _api-python-datamodel-network:

Network
............................................................

.. py:class:: Network

   Inherits :ref:`PublicObject <api-python-datamodel-publicobject>`.

   This type describes a network of seismic stations

   **Parents**:

   - ``inventory`` -- :ref:`Inventory <api-python-datamodel-inventory>`

   **Children**:

   - ``comment`` -- :ref:`Comment <api-python-datamodel-comment>`
   - ``station`` -- :ref:`Station <api-python-datamodel-station>`

   **Attributes**:

   - ``publicID``: string
   - ``code`` -- string
   - ``start`` -- seiscomp.core.Time
   - ``end`` -- seiscomp.core.Time (optional)
   - ``description`` -- string
   - ``institutions`` -- string
   - ``region`` -- string
   - ``type`` -- string
   - ``netClass`` -- string
   - ``archive`` -- string
   - ``restricted`` -- boolean (optional)
   - ``shared`` -- boolean (optional)
   - ``remark`` -- :ref:`Blob <api-python-datamodel-blob>` (optional)

   **Methods**:

   .. py:staticmethod:: Cast(obj)

      :param obj: The object to be casted.
      :rtype: An object of type Network if the cast was successful,
              None otherwise.

      Cast an arbitrary object to Network if the internal wrapped
      representation is an Network object. The cast is important if
      instances of type :ref:`Object <api-python-datamodel-object>`
      are passed to methods which need access to the real type.



   .. py:staticmethod:: Create()

      :rtype: A new object of type Network.

      Creates and registers (if enabled) a Network instance. The
      publicID is auto-generated.

   .. py:staticmethod:: Create(publicID)

      :rtype: A new object of type Network.

      Creates and registers (if enabled) a Network instance with
      passed publicID.

   .. py:method:: equal(other)

      :param other: Another object of type Network to compare this
                    instance to
      :rtype: A Boolean value indicating True if both objects are equal or
              False otherwise.

      Compares two objects without its child objects. Both objects are compared
      by value.

   .. py:method:: index()

      :rtype: The object's index of type NetworkIndex.

       Returns the objects index which is also used for the database as unique
       constraint.

   .. py:method:: equalIndex(lhs)

      :param lhs: :ref:`Network <api-python-datamodel-network>`
      :rtype: A Boolean value indicating True if both indexes are equal or
              False otherwise.

   .. py:method:: setCode(code)

      :param code: string

      Network code \(50.16\)

   .. py:method:: code()

      :rtype: string

   .. py:method:: setStart(start)

      :param start: seiscomp.core.Time

      Start of network epoch in ISO datetime format. Needed primarily to
      identifytemorary networks that re\-use network codes

   .. py:method:: start()

      :rtype: seiscomp.core.Time

   .. py:method:: setEnd(end)

      :param end: seiscomp.core.Time

      End of station epoch. Empty string if the station is open

   .. py:method:: end()

      :rtype: seiscomp.core.Time

      .. note::

         As this attribute is optional, this method throws a ValueError if
         the value of the attribute is not set.

   .. py:method:: setDescription(description)

      :param description: string

      Network description \(50.10\)

   .. py:method:: description()

      :rtype: string

   .. py:method:: setInstitutions(institutions)

      :param institutions: string

      Institution\(s\) operating the network

   .. py:method:: institutions()

      :rtype: string

   .. py:method:: setRegion(region)

      :param region: string

      Region of the network \(eg., euromed, global\)

   .. py:method:: region()

      :rtype: string

   .. py:method:: setType(type)

      :param type: string

      Type of the network \(eg., VBB, SP\)

   .. py:method:: type()

      :rtype: string

   .. py:method:: setNetClass(netClass)

      :param netClass: string

      ';p'; for permanent, ';t'; for temporary

   .. py:method:: netClass()

      :rtype: string

   .. py:method:: setArchive(archive)

      :param archive: string

      Archive\/Datacenter ID \(metadata authority\)

   .. py:method:: archive()

      :rtype: string

   .. py:method:: setRestricted(restricted)

      :param restricted: boolean

      Whether the network is \"restricted\"

   .. py:method:: restricted()

      :rtype: boolean

      .. note::

         As this attribute is optional, this method throws a ValueError if
         the value of the attribute is not set.

   .. py:method:: setShared(shared)

      :param shared: boolean

      Whether the metadata is synchronized with other datacenters

   .. py:method:: shared()

      :rtype: boolean

      .. note::

         As this attribute is optional, this method throws a ValueError if
         the value of the attribute is not set.

   .. py:method:: setRemark(remark)

      :param remark: :ref:`Blob <api-python-datamodel-blob>`

      Any notes

   .. py:method:: remark()

      :rtype: :ref:`Blob <api-python-datamodel-blob>`

      .. note::

         As this attribute is optional, this method throws a ValueError if
         the value of the attribute is not set.

   .. py:method:: add(comment)

      :param comment: Object of type :ref:`Comment <api-python-datamodel-comment>`
      :rtype: A Boolean value indicating success with True, False otherwise.

      Adds a Comment object to Network. The object is not
      copied but managed by this instance. Any change to the passed object
      will also change the child.

   .. py:method:: add(station)

      :param station: Object of type :ref:`Station <api-python-datamodel-station>`
      :rtype: A Boolean value indicating success with True, False otherwise.

      Adds a Station object to Network. The object is not
      copied but managed by this instance. Any change to the passed object
      will also change the child.

   .. py:method:: remove(comment)

      :param comment: Object of type :ref:`Comment <api-python-datamodel-comment>`
      :rtype: A Boolean value indicating success with True, False otherwise.

      Removes a previously added Comment object from Network.

   .. py:method:: remove(station)

      :param station: Object of type :ref:`Station <api-python-datamodel-station>`
      :rtype: A Boolean value indicating success with True, False otherwise.

      Removes a previously added Station object from Network.

   .. py:method:: removeComment(idx)

      :param idx: An integer index of the object to be removed.
      :rtype: A Boolean value indicating success with True, False otherwise.

   .. py:method:: removeComment(commentIndex);

      :param commentIndex: The index of the object to be removed of type CommentIndex.
      :rtype: A Boolean value indicating success with True, False otherwise.

   .. py:method:: removeStation(idx)

      :param idx: An integer index of the object to be removed.
      :rtype: A Boolean value indicating success with True, False otherwise.

   .. py:method:: removeStation(stationIndex);

      :param stationIndex: The index of the object to be removed of type StationIndex.
      :rtype: A Boolean value indicating success with True, False otherwise.

   .. py:method:: commentCount()

      :rtype: integer value indicating the number of child objects.

      Returns the number of Comment child objects.

   .. py:method:: stationCount()

      :rtype: integer value indicating the number of child objects.

      Returns the number of Station child objects.

   .. py:method:: comment(idx)

      :param idx: An integer index of the object to be returned.
      :rtype: Object of type :ref:`Comment <api-python-datamodel-comment>`.

      Returns the Comment at index idx.

   .. py:method:: comment(commentIndex)

      :param commentIndex: The index of the object to be removed of type CommentIndex.
      :rtype: Object of type :ref:`Comment <api-python-datamodel-comment>`.

      Returns the Comment at given index. The indexes of all child objects
      are compared by value which makes this function slower than the direct
      integer index look-up.

   .. py:method:: station(idx)

      :param idx: An integer index of the object to be returned.
      :rtype: Object of type :ref:`Station <api-python-datamodel-station>`.

      Returns the Station at index idx.

   .. py:method:: station(stationIndex)

      :param stationIndex: The index of the object to be removed of type StationIndex.
      :rtype: Object of type :ref:`Station <api-python-datamodel-station>`.

      Returns the Station at given index. The indexes of all child objects
      are compared by value which makes this function slower than the direct
      integer index look-up.

   .. py:method:: findStation(publicID)

      :param publicID: The publicID of the object to find.
      :rtype: Object of type :ref:`Station <api-python-datamodel-station>`.

      Returns the child object with a certain publicID, None otherwise.

   .. py:method:: inventory()

      :rtype: Inventory

      Returns the parent Inventory if available. Returns None
      if the parent is not a Inventory. This is a convenience wrapper
      for parent().

   .. py:method:: assign(other)

      This method implements the :ref:`Object <api-python-datamodel-object>` interface.

   .. py:method:: attachTo(parent)

      This method implements the :ref:`Object <api-python-datamodel-object>` interface.

   .. py:method:: detachFrom(parent)

      This method implements the :ref:`Object <api-python-datamodel-object>` interface.

   .. py:method:: detach()

      This method implements the :ref:`Object <api-python-datamodel-object>` interface.

   .. py:method:: clone()

      :rtype: A cloned Network.

      Returns a new instance that is a clone of the current instance. Child
      objects are being ignored.


   .. py:method:: updateChild(ref)

      :param ref: A child object derived from class Object.
      :rtype: A Boolean flag indicating success with True, False otherwise

      This method takes the passed reference object and searches for a child
      with the same publicID (if derived from :ref:`PublicObject <api-python-datamodel-publicobject>`)
      or the same index (if derived from :ref:`Object <api-python-datamodel-object>`).
      The the child was found the reference objects attributes are copied to
      the child object. Children of child are being ignored during this operation.
      This method implements the :ref:`PublicObject <api-python-datamodel-publicobject>` interface.


   .. py:method:: accept(visitor)

      :param visitor: A visitor.

      This method implements the :ref:`PublicObject <api-python-datamodel-publicobject>` interface.

.. _api-python-datamodel-nodalplane:

NodalPlane
............................................................

.. py:class:: NodalPlane

   Inherits :ref:`Object <api-python-datamodel-object>`.

   This class describes a nodal plane using the attributes strike, dip, and
   rake. For a definition of the angles see Aki and Richards \(1980\).

   **Attributes**:

   - ``strike`` -- :ref:`RealQuantity <api-python-datamodel-realquantity>`
   - ``dip`` -- :ref:`RealQuantity <api-python-datamodel-realquantity>`
   - ``rake`` -- :ref:`RealQuantity <api-python-datamodel-realquantity>`

   **Used by**:

   - :func:`NodalPlanes.nodalPlane1`
   - :func:`NodalPlanes.nodalPlane2`

   **Methods**:

   .. py:staticmethod:: Cast(obj)

      :param obj: The object to be casted.
      :rtype: An object of type NodalPlane if the cast was successful,
              None otherwise.

      Cast an arbitrary object to NodalPlane if the internal wrapped
      representation is an NodalPlane object. The cast is important if
      instances of type :ref:`Object <api-python-datamodel-object>`
      are passed to methods which need access to the real type.



   .. py:method:: equal(other)

      :param other: Another object of type NodalPlane to compare this
                    instance to
      :rtype: A Boolean value indicating True if both objects are equal or
              False otherwise.

      Compares two objects without its child objects. Both objects are compared
      by value.

   .. py:method:: setStrike(strike)

      :param strike: :ref:`RealQuantity <api-python-datamodel-realquantity>`

      Strike angle of nodal plane in degrees.

   .. py:method:: strike()

      :rtype: :ref:`RealQuantity <api-python-datamodel-realquantity>`

   .. py:method:: setDip(dip)

      :param dip: :ref:`RealQuantity <api-python-datamodel-realquantity>`

      Dip angle of nodal plane in degrees.

   .. py:method:: dip()

      :rtype: :ref:`RealQuantity <api-python-datamodel-realquantity>`

   .. py:method:: setRake(rake)

      :param rake: :ref:`RealQuantity <api-python-datamodel-realquantity>`

      Rake angle of nodal plane in degrees.

   .. py:method:: rake()

      :rtype: :ref:`RealQuantity <api-python-datamodel-realquantity>`

.. _api-python-datamodel-nodalplanes:

NodalPlanes
............................................................

.. py:class:: NodalPlanes

   Inherits :ref:`Object <api-python-datamodel-object>`.

   This class describes the nodal planes of a double\-couple moment\-tensor
   solution. The attribute preferredPlane
   can be used to define which plane is the preferred one.

   **Attributes**:

   - ``nodalPlane1`` -- :ref:`NodalPlane <api-python-datamodel-nodalplane>` (optional)
   - ``nodalPlane2`` -- :ref:`NodalPlane <api-python-datamodel-nodalplane>` (optional)
   - ``preferredPlane`` -- int (optional)

   **Used by**:

   - :func:`FocalMechanism.nodalPlanes`

   **Methods**:

   .. py:staticmethod:: Cast(obj)

      :param obj: The object to be casted.
      :rtype: An object of type NodalPlanes if the cast was successful,
              None otherwise.

      Cast an arbitrary object to NodalPlanes if the internal wrapped
      representation is an NodalPlanes object. The cast is important if
      instances of type :ref:`Object <api-python-datamodel-object>`
      are passed to methods which need access to the real type.



   .. py:method:: equal(other)

      :param other: Another object of type NodalPlanes to compare this
                    instance to
      :rtype: A Boolean value indicating True if both objects are equal or
              False otherwise.

      Compares two objects without its child objects. Both objects are compared
      by value.

   .. py:method:: setNodalPlane1(nodalPlane1)

      :param nodalPlane1: :ref:`NodalPlane <api-python-datamodel-nodalplane>`

      First nodal plane of double\-couple moment tensor solution.

   .. py:method:: nodalPlane1()

      :rtype: :ref:`NodalPlane <api-python-datamodel-nodalplane>`

      .. note::

         As this attribute is optional, this method throws a ValueError if
         the value of the attribute is not set.

   .. py:method:: setNodalPlane2(nodalPlane2)

      :param nodalPlane2: :ref:`NodalPlane <api-python-datamodel-nodalplane>`

      Second nodal plane of double\-couple moment tensor solution.

   .. py:method:: nodalPlane2()

      :rtype: :ref:`NodalPlane <api-python-datamodel-nodalplane>`

      .. note::

         As this attribute is optional, this method throws a ValueError if
         the value of the attribute is not set.

   .. py:method:: setPreferredPlane(preferredPlane)

      :param preferredPlane: int

      Indicator for preferred nodal plane of moment tensor solution. It can take
      integer values 1 or 2.

   .. py:method:: preferredPlane()

      :rtype: int

      .. note::

         As this attribute is optional, this method throws a ValueError if
         the value of the attribute is not set.

.. _api-python-datamodel-origin:

Origin
............................................................

.. py:class:: Origin

   Inherits :ref:`PublicObject <api-python-datamodel-publicobject>`.

   This class represents the focal time and geographical location of an
   earthquake hypocenter, as well as additional meta\-information. Origin
   can have objects of type OriginUncertainty and Arrival as child elements.

   **Parents**:

   - ``eventParameters`` -- :ref:`EventParameters <api-python-datamodel-eventparameters>`

   **Children**:

   - ``comment`` -- :ref:`Comment <api-python-datamodel-comment>`
   - ``compositeTime`` -- :ref:`CompositeTime <api-python-datamodel-compositetime>`
   - ``arrival`` -- :ref:`Arrival <api-python-datamodel-arrival>`
   - ``stationMagnitude`` -- :ref:`StationMagnitude <api-python-datamodel-stationmagnitude>`
   - ``magnitude`` -- :ref:`Magnitude <api-python-datamodel-magnitude>`

   **Attributes**:

   - ``publicID``: string
   - ``time`` -- :ref:`TimeQuantity <api-python-datamodel-timequantity>`
   - ``latitude`` -- :ref:`RealQuantity <api-python-datamodel-realquantity>`
   - ``longitude`` -- :ref:`RealQuantity <api-python-datamodel-realquantity>`
   - ``depth`` -- :ref:`RealQuantity <api-python-datamodel-realquantity>` (optional)
   - ``depthType`` -- :ref:`OriginDepthType <api-python-datamodel-origindepthtype>` (optional)
   - ``timeFixed`` -- boolean (optional)
   - ``epicenterFixed`` -- boolean (optional)
   - ``referenceSystemID`` -- string
   - ``methodID`` -- string
   - ``earthModelID`` -- string
   - ``quality`` -- :ref:`OriginQuality <api-python-datamodel-originquality>` (optional)
   - ``uncertainty`` -- :ref:`OriginUncertainty <api-python-datamodel-originuncertainty>` (optional)
   - ``type`` -- :ref:`OriginType <api-python-datamodel-origintype>` (optional)
   - ``evaluationMode`` -- :ref:`EvaluationMode <api-python-datamodel-evaluationmode>` (optional)
   - ``evaluationStatus`` -- :ref:`EvaluationStatus <api-python-datamodel-evaluationstatus>` (optional)
   - ``creationInfo`` -- :ref:`CreationInfo <api-python-datamodel-creationinfo>` (optional)

   **Referenced by**:

   - :func:`Event.preferredOriginID`
   - :func:`FocalMechanism.triggeringOriginID`
   - :func:`Magnitude.originID`
   - :func:`MomentTensor.derivedOriginID`
   - :func:`OriginReference.originID`
   - :func:`StationMagnitude.originID`

   **Methods**:

   .. py:staticmethod:: Cast(obj)

      :param obj: The object to be casted.
      :rtype: An object of type Origin if the cast was successful,
              None otherwise.

      Cast an arbitrary object to Origin if the internal wrapped
      representation is an Origin object. The cast is important if
      instances of type :ref:`Object <api-python-datamodel-object>`
      are passed to methods which need access to the real type.



   .. py:staticmethod:: Create()

      :rtype: A new object of type Origin.

      Creates and registers (if enabled) a Origin instance. The
      publicID is auto-generated.

   .. py:staticmethod:: Create(publicID)

      :rtype: A new object of type Origin.

      Creates and registers (if enabled) a Origin instance with
      passed publicID.

   .. py:method:: equal(other)

      :param other: Another object of type Origin to compare this
                    instance to
      :rtype: A Boolean value indicating True if both objects are equal or
              False otherwise.

      Compares two objects without its child objects. Both objects are compared
      by value.

   .. py:method:: setTime(time)

      :param time: :ref:`TimeQuantity <api-python-datamodel-timequantity>`

      Focal time as TimeQuantity.

   .. py:method:: time()

      :rtype: :ref:`TimeQuantity <api-python-datamodel-timequantity>`

   .. py:method:: setLatitude(latitude)

      :param latitude: :ref:`RealQuantity <api-python-datamodel-realquantity>`

      Hypocenter latitude with respect to the World Geodetic System 1984
      \(WGS84\) reference system \(National Imagery and Mapping Agency 2000\)
      in degrees. Uncertainties are given in kilometers.

   .. py:method:: latitude()

      :rtype: :ref:`RealQuantity <api-python-datamodel-realquantity>`

   .. py:method:: setLongitude(longitude)

      :param longitude: :ref:`RealQuantity <api-python-datamodel-realquantity>`

      Hypocenter longitude with respect to the World Geodetic System 1984
      \(WGS84\) reference system \(National Imagery and Mapping Agency 2000\)
      in degrees. Uncertainties are given in kilometers.

   .. py:method:: longitude()

      :rtype: :ref:`RealQuantity <api-python-datamodel-realquantity>`

   .. py:method:: setDepth(depth)

      :param depth: :ref:`RealQuantity <api-python-datamodel-realquantity>`

      Depth of hypocenter with respect to the nominal sea level given by the
      WGS84 geoid \(Earth Gravitational Model, EGM96, Lemoine et al. 1998\).
      Positive values indicate hypocenters below sea level. For shallow
      hypocenters, the depth value can be negative. The depth is defined
      in km.

   .. py:method:: depth()

      :rtype: :ref:`RealQuantity <api-python-datamodel-realquantity>`

      .. note::

         As this attribute is optional, this method throws a ValueError if
         the value of the attribute is not set.

   .. py:method:: setDepthType(depthType)

      :param depthType: OriginDepthType

      Type of depth determination.

   .. py:method:: depthType()

      :rtype: OriginDepthType

      .. note::

         As this attribute is optional, this method throws a ValueError if
         the value of the attribute is not set.

   .. py:method:: setTimeFixed(timeFixed)

      :param timeFixed: boolean

      Boolean flag. True if focal time was kept fixed for computation of the
      Origin.

   .. py:method:: timeFixed()

      :rtype: boolean

      .. note::

         As this attribute is optional, this method throws a ValueError if
         the value of the attribute is not set.

   .. py:method:: setEpicenterFixed(epicenterFixed)

      :param epicenterFixed: boolean

      Boolean flag. True if epicenter was kept fixed for computation of Origin.

   .. py:method:: epicenterFixed()

      :rtype: boolean

      .. note::

         As this attribute is optional, this method throws a ValueError if
         the value of the attribute is not set.

   .. py:method:: setReferenceSystemID(referenceSystemID)

      :param referenceSystemID: string

      Identifies the reference system used for hypocenter determination. This is
      only necessary if
      a modified version of the standard \(with local extensions\) is used that
      provides a non\-standard coordinate
      system.

   .. py:method:: referenceSystemID()

      :rtype: string

   .. py:method:: setMethodID(methodID)

      :param methodID: string

      Identifies the method used for locating the event.

   .. py:method:: methodID()

      :rtype: string

   .. py:method:: setEarthModelID(earthModelID)

      :param earthModelID: string

      Identifies the earth model used in methodID.

   .. py:method:: earthModelID()

      :rtype: string

   .. py:method:: setQuality(quality)

      :param quality: :ref:`OriginQuality <api-python-datamodel-originquality>`

      Additional parameters describing the quality of an Origin determination.

   .. py:method:: quality()

      :rtype: :ref:`OriginQuality <api-python-datamodel-originquality>`

      .. note::

         As this attribute is optional, this method throws a ValueError if
         the value of the attribute is not set.

   .. py:method:: setUncertainty(uncertainty)

      :param uncertainty: :ref:`OriginUncertainty <api-python-datamodel-originuncertainty>`

      Additional parameters describing the uncertainty of an Origin determination.

   .. py:method:: uncertainty()

      :rtype: :ref:`OriginUncertainty <api-python-datamodel-originuncertainty>`

      .. note::

         As this attribute is optional, this method throws a ValueError if
         the value of the attribute is not set.

   .. py:method:: setType(type)

      :param type: OriginType

      Describes the Origin type.

   .. py:method:: type()

      :rtype: OriginType

      .. note::

         As this attribute is optional, this method throws a ValueError if
         the value of the attribute is not set.

   .. py:method:: setEvaluationMode(evaluationMode)

      :param evaluationMode: EvaluationMode

      Evaluation mode of Origin.

   .. py:method:: evaluationMode()

      :rtype: EvaluationMode

      .. note::

         As this attribute is optional, this method throws a ValueError if
         the value of the attribute is not set.

   .. py:method:: setEvaluationStatus(evaluationStatus)

      :param evaluationStatus: EvaluationStatus

      Evaluation status of Origin.

   .. py:method:: evaluationStatus()

      :rtype: EvaluationStatus

      .. note::

         As this attribute is optional, this method throws a ValueError if
         the value of the attribute is not set.

   .. py:method:: setCreationInfo(creationInfo)

      :param creationInfo: :ref:`CreationInfo <api-python-datamodel-creationinfo>`

      CreationInfo for the Origin object.

   .. py:method:: creationInfo()

      :rtype: :ref:`CreationInfo <api-python-datamodel-creationinfo>`

      .. note::

         As this attribute is optional, this method throws a ValueError if
         the value of the attribute is not set.

   .. py:method:: add(comment)

      :param comment: Object of type :ref:`Comment <api-python-datamodel-comment>`
      :rtype: A Boolean value indicating success with True, False otherwise.

      Adds a Comment object to Origin. The object is not
      copied but managed by this instance. Any change to the passed object
      will also change the child.

   .. py:method:: add(compositeTime)

      :param compositeTime: Object of type :ref:`CompositeTime <api-python-datamodel-compositetime>`
      :rtype: A Boolean value indicating success with True, False otherwise.

      Adds a CompositeTime object to Origin. The object is not
      copied but managed by this instance. Any change to the passed object
      will also change the child.

   .. py:method:: add(arrival)

      :param arrival: Object of type :ref:`Arrival <api-python-datamodel-arrival>`
      :rtype: A Boolean value indicating success with True, False otherwise.

      Adds a Arrival object to Origin. The object is not
      copied but managed by this instance. Any change to the passed object
      will also change the child.

   .. py:method:: add(stationMagnitude)

      :param stationMagnitude: Object of type :ref:`StationMagnitude <api-python-datamodel-stationmagnitude>`
      :rtype: A Boolean value indicating success with True, False otherwise.

      Adds a StationMagnitude object to Origin. The object is not
      copied but managed by this instance. Any change to the passed object
      will also change the child.

   .. py:method:: add(magnitude)

      :param magnitude: Object of type :ref:`Magnitude <api-python-datamodel-magnitude>`
      :rtype: A Boolean value indicating success with True, False otherwise.

      Adds a Magnitude object to Origin. The object is not
      copied but managed by this instance. Any change to the passed object
      will also change the child.

   .. py:method:: remove(comment)

      :param comment: Object of type :ref:`Comment <api-python-datamodel-comment>`
      :rtype: A Boolean value indicating success with True, False otherwise.

      Removes a previously added Comment object from Origin.

   .. py:method:: remove(compositeTime)

      :param compositeTime: Object of type :ref:`CompositeTime <api-python-datamodel-compositetime>`
      :rtype: A Boolean value indicating success with True, False otherwise.

      Removes a previously added CompositeTime object from Origin.

   .. py:method:: remove(arrival)

      :param arrival: Object of type :ref:`Arrival <api-python-datamodel-arrival>`
      :rtype: A Boolean value indicating success with True, False otherwise.

      Removes a previously added Arrival object from Origin.

   .. py:method:: remove(stationMagnitude)

      :param stationMagnitude: Object of type :ref:`StationMagnitude <api-python-datamodel-stationmagnitude>`
      :rtype: A Boolean value indicating success with True, False otherwise.

      Removes a previously added StationMagnitude object from Origin.

   .. py:method:: remove(magnitude)

      :param magnitude: Object of type :ref:`Magnitude <api-python-datamodel-magnitude>`
      :rtype: A Boolean value indicating success with True, False otherwise.

      Removes a previously added Magnitude object from Origin.

   .. py:method:: removeComment(idx)

      :param idx: An integer index of the object to be removed.
      :rtype: A Boolean value indicating success with True, False otherwise.

   .. py:method:: removeComment(commentIndex);

      :param commentIndex: The index of the object to be removed of type CommentIndex.
      :rtype: A Boolean value indicating success with True, False otherwise.

   .. py:method:: removeCompositeTime(idx)

      :param idx: An integer index of the object to be removed.
      :rtype: A Boolean value indicating success with True, False otherwise.

   .. py:method:: removeArrival(idx)

      :param idx: An integer index of the object to be removed.
      :rtype: A Boolean value indicating success with True, False otherwise.

   .. py:method:: removeArrival(arrivalIndex);

      :param arrivalIndex: The index of the object to be removed of type ArrivalIndex.
      :rtype: A Boolean value indicating success with True, False otherwise.

   .. py:method:: removeStationMagnitude(idx)

      :param idx: An integer index of the object to be removed.
      :rtype: A Boolean value indicating success with True, False otherwise.

   .. py:method:: removeMagnitude(idx)

      :param idx: An integer index of the object to be removed.
      :rtype: A Boolean value indicating success with True, False otherwise.

   .. py:method:: commentCount()

      :rtype: integer value indicating the number of child objects.

      Returns the number of Comment child objects.

   .. py:method:: compositeTimeCount()

      :rtype: integer value indicating the number of child objects.

      Returns the number of CompositeTime child objects.

   .. py:method:: arrivalCount()

      :rtype: integer value indicating the number of child objects.

      Returns the number of Arrival child objects.

   .. py:method:: stationMagnitudeCount()

      :rtype: integer value indicating the number of child objects.

      Returns the number of StationMagnitude child objects.

   .. py:method:: magnitudeCount()

      :rtype: integer value indicating the number of child objects.

      Returns the number of Magnitude child objects.

   .. py:method:: comment(idx)

      :param idx: An integer index of the object to be returned.
      :rtype: Object of type :ref:`Comment <api-python-datamodel-comment>`.

      Returns the Comment at index idx.

   .. py:method:: comment(commentIndex)

      :param commentIndex: The index of the object to be removed of type CommentIndex.
      :rtype: Object of type :ref:`Comment <api-python-datamodel-comment>`.

      Returns the Comment at given index. The indexes of all child objects
      are compared by value which makes this function slower than the direct
      integer index look-up.

   .. py:method:: compositeTime(idx)

      :param idx: An integer index of the object to be returned.
      :rtype: Object of type :ref:`CompositeTime <api-python-datamodel-compositetime>`.

      Returns the CompositeTime at index idx.

   .. py:method:: arrival(idx)

      :param idx: An integer index of the object to be returned.
      :rtype: Object of type :ref:`Arrival <api-python-datamodel-arrival>`.

      Returns the Arrival at index idx.

   .. py:method:: arrival(arrivalIndex)

      :param arrivalIndex: The index of the object to be removed of type ArrivalIndex.
      :rtype: Object of type :ref:`Arrival <api-python-datamodel-arrival>`.

      Returns the Arrival at given index. The indexes of all child objects
      are compared by value which makes this function slower than the direct
      integer index look-up.

   .. py:method:: stationMagnitude(idx)

      :param idx: An integer index of the object to be returned.
      :rtype: Object of type :ref:`StationMagnitude <api-python-datamodel-stationmagnitude>`.

      Returns the StationMagnitude at index idx.

   .. py:method:: magnitude(idx)

      :param idx: An integer index of the object to be returned.
      :rtype: Object of type :ref:`Magnitude <api-python-datamodel-magnitude>`.

      Returns the Magnitude at index idx.

   .. py:method:: findCompositeTime(compositeTime)

      :param compositeTime: Reference object of type :ref:`CompositeTime <api-python-datamodel-compositetime>`.
      :rtype: Object of type :ref:`CompositeTime <api-python-datamodel-compositetime>`.

      Returns the child object with equals the passed object, None otherwise.

   .. py:method:: findStationMagnitude(publicID)

      :param publicID: The publicID of the object to find.
      :rtype: Object of type :ref:`StationMagnitude <api-python-datamodel-stationmagnitude>`.

      Returns the child object with a certain publicID, None otherwise.

   .. py:method:: findMagnitude(publicID)

      :param publicID: The publicID of the object to find.
      :rtype: Object of type :ref:`Magnitude <api-python-datamodel-magnitude>`.

      Returns the child object with a certain publicID, None otherwise.

   .. py:method:: eventParameters()

      :rtype: EventParameters

      Returns the parent EventParameters if available. Returns None
      if the parent is not a EventParameters. This is a convenience wrapper
      for parent().

   .. py:method:: assign(other)

      This method implements the :ref:`Object <api-python-datamodel-object>` interface.

   .. py:method:: attachTo(parent)

      This method implements the :ref:`Object <api-python-datamodel-object>` interface.

   .. py:method:: detachFrom(parent)

      This method implements the :ref:`Object <api-python-datamodel-object>` interface.

   .. py:method:: detach()

      This method implements the :ref:`Object <api-python-datamodel-object>` interface.

   .. py:method:: clone()

      :rtype: A cloned Origin.

      Returns a new instance that is a clone of the current instance. Child
      objects are being ignored.


   .. py:method:: updateChild(ref)

      :param ref: A child object derived from class Object.
      :rtype: A Boolean flag indicating success with True, False otherwise

      This method takes the passed reference object and searches for a child
      with the same publicID (if derived from :ref:`PublicObject <api-python-datamodel-publicobject>`)
      or the same index (if derived from :ref:`Object <api-python-datamodel-object>`).
      The the child was found the reference objects attributes are copied to
      the child object. Children of child are being ignored during this operation.
      This method implements the :ref:`PublicObject <api-python-datamodel-publicobject>` interface.


   .. py:method:: accept(visitor)

      :param visitor: A visitor.

      This method implements the :ref:`PublicObject <api-python-datamodel-publicobject>` interface.

.. _api-python-datamodel-originquality:

OriginQuality
............................................................

.. py:class:: OriginQuality

   Inherits :ref:`Object <api-python-datamodel-object>`.

   This type contains various attributes commonly used to describe the quality of
   an origin, e. g., errors, azimuthal
   coverage, etc. Origin objects have an optional attribute of the type
   OriginQuality.

   **Attributes**:

   - ``associatedPhaseCount`` -- int (optional)
   - ``usedPhaseCount`` -- int (optional)
   - ``associatedStationCount`` -- int (optional)
   - ``usedStationCount`` -- int (optional)
   - ``depthPhaseCount`` -- int (optional)
   - ``standardError`` -- float (optional)
   - ``azimuthalGap`` -- float (optional)
   - ``secondaryAzimuthalGap`` -- float (optional)
   - ``groundTruthLevel`` -- string
   - ``maximumDistance`` -- float (optional)
   - ``minimumDistance`` -- float (optional)
   - ``medianDistance`` -- float (optional)

   **Used by**:

   - :func:`Origin.quality`

   **Methods**:

   .. py:staticmethod:: Cast(obj)

      :param obj: The object to be casted.
      :rtype: An object of type OriginQuality if the cast was successful,
              None otherwise.

      Cast an arbitrary object to OriginQuality if the internal wrapped
      representation is an OriginQuality object. The cast is important if
      instances of type :ref:`Object <api-python-datamodel-object>`
      are passed to methods which need access to the real type.



   .. py:method:: equal(other)

      :param other: Another object of type OriginQuality to compare this
                    instance to
      :rtype: A Boolean value indicating True if both objects are equal or
              False otherwise.

      Compares two objects without its child objects. Both objects are compared
      by value.

   .. py:method:: setAssociatedPhaseCount(associatedPhaseCount)

      :param associatedPhaseCount: int

      Number of associated phases, regardless of their use for origin computation.

   .. py:method:: associatedPhaseCount()

      :rtype: int

      .. note::

         As this attribute is optional, this method throws a ValueError if
         the value of the attribute is not set.

   .. py:method:: setUsedPhaseCount(usedPhaseCount)

      :param usedPhaseCount: int

      Number of defining phases, i. e., phase observations that were actually used
      for computing
      the origin. Note that there may be more than one defining phase per station.

   .. py:method:: usedPhaseCount()

      :rtype: int

      .. note::

         As this attribute is optional, this method throws a ValueError if
         the value of the attribute is not set.

   .. py:method:: setAssociatedStationCount(associatedStationCount)

      :param associatedStationCount: int

      Number of stations at which the event was observed.

   .. py:method:: associatedStationCount()

      :rtype: int

      .. note::

         As this attribute is optional, this method throws a ValueError if
         the value of the attribute is not set.

   .. py:method:: setUsedStationCount(usedStationCount)

      :param usedStationCount: int

      Number of stations from which data was used for origin computation.

   .. py:method:: usedStationCount()

      :rtype: int

      .. note::

         As this attribute is optional, this method throws a ValueError if
         the value of the attribute is not set.

   .. py:method:: setDepthPhaseCount(depthPhaseCount)

      :param depthPhaseCount: int

      Number of depth phases \(typically pP, sometimes sP\) used in depth
      computation.

   .. py:method:: depthPhaseCount()

      :rtype: int

      .. note::

         As this attribute is optional, this method throws a ValueError if
         the value of the attribute is not set.

   .. py:method:: setStandardError(standardError)

      :param standardError: float

      RMS of the travel time residuals of the arrivals used for the origin
      computation
      in seconds.

   .. py:method:: standardError()

      :rtype: float

      .. note::

         As this attribute is optional, this method throws a ValueError if
         the value of the attribute is not set.

   .. py:method:: setAzimuthalGap(azimuthalGap)

      :param azimuthalGap: float

      Largest azimuthal gap in station distribution as seen from epicenter
      in degrees.

   .. py:method:: azimuthalGap()

      :rtype: float

      .. note::

         As this attribute is optional, this method throws a ValueError if
         the value of the attribute is not set.

   .. py:method:: setSecondaryAzimuthalGap(secondaryAzimuthalGap)

      :param secondaryAzimuthalGap: float

      Secondary azimuthal gap in station distribution, i. e., the largest
      azimuthal gap a station closes in degrees.

   .. py:method:: secondaryAzimuthalGap()

      :rtype: float

      .. note::

         As this attribute is optional, this method throws a ValueError if
         the value of the attribute is not set.

   .. py:method:: setGroundTruthLevel(groundTruthLevel)

      :param groundTruthLevel: string

      String describing ground\-truth level, e. g. GT0, GT5, etc. It has a maximum
      length of 16
      characters.

   .. py:method:: groundTruthLevel()

      :rtype: string

   .. py:method:: setMaximumDistance(maximumDistance)

      :param maximumDistance: float

      Epicentral distance of station farthest from the epicenter in degrees.

   .. py:method:: maximumDistance()

      :rtype: float

      .. note::

         As this attribute is optional, this method throws a ValueError if
         the value of the attribute is not set.

   .. py:method:: setMinimumDistance(minimumDistance)

      :param minimumDistance: float

      Epicentral distance of station closest to the epicenter in degrees.

   .. py:method:: minimumDistance()

      :rtype: float

      .. note::

         As this attribute is optional, this method throws a ValueError if
         the value of the attribute is not set.

   .. py:method:: setMedianDistance(medianDistance)

      :param medianDistance: float

      Median epicentral distance of used stations in degrees.

   .. py:method:: medianDistance()

      :rtype: float

      .. note::

         As this attribute is optional, this method throws a ValueError if
         the value of the attribute is not set.

.. _api-python-datamodel-originreference:

OriginReference
............................................................

.. py:class:: OriginReference

   Inherits :ref:`Object <api-python-datamodel-object>`.


   **Parents**:

   - ``event`` -- :ref:`Event <api-python-datamodel-event>`

   **Attributes**:

   - ``originID`` -- string

   **Methods**:

   .. py:staticmethod:: Cast(obj)

      :param obj: The object to be casted.
      :rtype: An object of type OriginReference if the cast was successful,
              None otherwise.

      Cast an arbitrary object to OriginReference if the internal wrapped
      representation is an OriginReference object. The cast is important if
      instances of type :ref:`Object <api-python-datamodel-object>`
      are passed to methods which need access to the real type.



   .. py:method:: equal(other)

      :param other: Another object of type OriginReference to compare this
                    instance to
      :rtype: A Boolean value indicating True if both objects are equal or
              False otherwise.

      Compares two objects without its child objects. Both objects are compared
      by value.

   .. py:method:: index()

      :rtype: The object's index of type OriginReferenceIndex.

       Returns the objects index which is also used for the database as unique
       constraint.

   .. py:method:: equalIndex(lhs)

      :param lhs: :ref:`OriginReference <api-python-datamodel-originreference>`
      :rtype: A Boolean value indicating True if both indexes are equal or
              False otherwise.

   .. py:method:: setOriginID(originID)

      :param originID: string

   .. py:method:: originID()

      :rtype: string

   .. py:method:: event()

      :rtype: Event

      Returns the parent Event if available. Returns None
      if the parent is not a Event. This is a convenience wrapper
      for parent().

   .. py:method:: assign(other)

      This method implements the :ref:`Object <api-python-datamodel-object>` interface.

   .. py:method:: attachTo(parent)

      This method implements the :ref:`Object <api-python-datamodel-object>` interface.

   .. py:method:: detachFrom(parent)

      This method implements the :ref:`Object <api-python-datamodel-object>` interface.

   .. py:method:: detach()

      This method implements the :ref:`Object <api-python-datamodel-object>` interface.

   .. py:method:: clone()

      :rtype: A cloned OriginReference.

      Returns a new instance that is a clone of the current instance. Child
      objects are being ignored.


   .. py:method:: accept(visitor)

      :param visitor: A visitor.

      This method implements the :ref:`PublicObject <api-python-datamodel-publicobject>` interface.

.. _api-python-datamodel-originuncertainty:

OriginUncertainty
............................................................

.. py:class:: OriginUncertainty

   Inherits :ref:`Object <api-python-datamodel-object>`.

   This class describes the location uncertainties of an origin. The uncertainty
   can be described either as a simple circular horizontal uncertainty, an
   uncertainty ellipse according to IMS1.0, or a confidence ellipsoid. If
   multiple uncertainty models are given, the preferred variant can be
   specified in the attribute preferredDescription.

   **Attributes**:

   - ``horizontalUncertainty`` -- float (optional)
   - ``minHorizontalUncertainty`` -- float (optional)
   - ``maxHorizontalUncertainty`` -- float (optional)
   - ``azimuthMaxHorizontalUncertainty`` -- float (optional)
   - ``confidenceEllipsoid`` -- :ref:`ConfidenceEllipsoid <api-python-datamodel-confidenceellipsoid>` (optional)
   - ``preferredDescription`` -- :ref:`OriginUncertaintyDescription <api-python-datamodel-originuncertaintydescription>` (optional)
   - ``confidenceLevel`` -- float (optional)

   **Used by**:

   - :func:`Origin.uncertainty`

   **Methods**:

   .. py:staticmethod:: Cast(obj)

      :param obj: The object to be casted.
      :rtype: An object of type OriginUncertainty if the cast was successful,
              None otherwise.

      Cast an arbitrary object to OriginUncertainty if the internal wrapped
      representation is an OriginUncertainty object. The cast is important if
      instances of type :ref:`Object <api-python-datamodel-object>`
      are passed to methods which need access to the real type.



   .. py:method:: equal(other)

      :param other: Another object of type OriginUncertainty to compare this
                    instance to
      :rtype: A Boolean value indicating True if both objects are equal or
              False otherwise.

      Compares two objects without its child objects. Both objects are compared
      by value.

   .. py:method:: setHorizontalUncertainty(horizontalUncertainty)

      :param horizontalUncertainty: float

      Circular confidence region, given by single value of horizontal uncertainty
      in km.

   .. py:method:: horizontalUncertainty()

      :rtype: float

      .. note::

         As this attribute is optional, this method throws a ValueError if
         the value of the attribute is not set.

   .. py:method:: setMinHorizontalUncertainty(minHorizontalUncertainty)

      :param minHorizontalUncertainty: float

      Semi\-minor axis of confidence ellipse in km.

   .. py:method:: minHorizontalUncertainty()

      :rtype: float

      .. note::

         As this attribute is optional, this method throws a ValueError if
         the value of the attribute is not set.

   .. py:method:: setMaxHorizontalUncertainty(maxHorizontalUncertainty)

      :param maxHorizontalUncertainty: float

      Semi\-major axis of confidence ellipse in km.

   .. py:method:: maxHorizontalUncertainty()

      :rtype: float

      .. note::

         As this attribute is optional, this method throws a ValueError if
         the value of the attribute is not set.

   .. py:method:: setAzimuthMaxHorizontalUncertainty(azimuthMaxHorizontalUncertainty)

      :param azimuthMaxHorizontalUncertainty: float

      Azimuth of major axis of confidence ellipse. Measured clockwise from
      South\-North direction at epicenter in degrees.

   .. py:method:: azimuthMaxHorizontalUncertainty()

      :rtype: float

      .. note::

         As this attribute is optional, this method throws a ValueError if
         the value of the attribute is not set.

   .. py:method:: setConfidenceEllipsoid(confidenceEllipsoid)

      :param confidenceEllipsoid: :ref:`ConfidenceEllipsoid <api-python-datamodel-confidenceellipsoid>`

      Confidence ellipsoid.

   .. py:method:: confidenceEllipsoid()

      :rtype: :ref:`ConfidenceEllipsoid <api-python-datamodel-confidenceellipsoid>`

      .. note::

         As this attribute is optional, this method throws a ValueError if
         the value of the attribute is not set.

   .. py:method:: setPreferredDescription(preferredDescription)

      :param preferredDescription: OriginUncertaintyDescription

      Preferred uncertainty description.

   .. py:method:: preferredDescription()

      :rtype: OriginUncertaintyDescription

      .. note::

         As this attribute is optional, this method throws a ValueError if
         the value of the attribute is not set.

   .. py:method:: setConfidenceLevel(confidenceLevel)

      :param confidenceLevel: float

      Confidence level of the uncertainty, given in percent.

   .. py:method:: confidenceLevel()

      :rtype: float

      .. note::

         As this attribute is optional, this method throws a ValueError if
         the value of the attribute is not set.

.. _api-python-datamodel-outage:

Outage
............................................................

.. py:class:: Outage

   Inherits :ref:`Object <api-python-datamodel-object>`.


   **Parents**:

   - ``qualityControl`` -- :ref:`QualityControl <api-python-datamodel-qualitycontrol>`

   **Attributes**:

   - ``waveformID`` -- :ref:`WaveformStreamID <api-python-datamodel-waveformstreamid>`
   - ``creatorID`` -- string
   - ``created`` -- seiscomp.core.Time
   - ``start`` -- seiscomp.core.Time
   - ``end`` -- seiscomp.core.Time (optional)

   **Methods**:

   .. py:staticmethod:: Cast(obj)

      :param obj: The object to be casted.
      :rtype: An object of type Outage if the cast was successful,
              None otherwise.

      Cast an arbitrary object to Outage if the internal wrapped
      representation is an Outage object. The cast is important if
      instances of type :ref:`Object <api-python-datamodel-object>`
      are passed to methods which need access to the real type.



   .. py:method:: equal(other)

      :param other: Another object of type Outage to compare this
                    instance to
      :rtype: A Boolean value indicating True if both objects are equal or
              False otherwise.

      Compares two objects without its child objects. Both objects are compared
      by value.

   .. py:method:: index()

      :rtype: The object's index of type OutageIndex.

       Returns the objects index which is also used for the database as unique
       constraint.

   .. py:method:: equalIndex(lhs)

      :param lhs: :ref:`Outage <api-python-datamodel-outage>`
      :rtype: A Boolean value indicating True if both indexes are equal or
              False otherwise.

   .. py:method:: setWaveformID(waveformID)

      :param waveformID: :ref:`WaveformStreamID <api-python-datamodel-waveformstreamid>`

   .. py:method:: waveformID()

      :rtype: :ref:`WaveformStreamID <api-python-datamodel-waveformstreamid>`

   .. py:method:: setCreatorID(creatorID)

      :param creatorID: string

   .. py:method:: creatorID()

      :rtype: string

   .. py:method:: setCreated(created)

      :param created: seiscomp.core.Time

   .. py:method:: created()

      :rtype: seiscomp.core.Time

   .. py:method:: setStart(start)

      :param start: seiscomp.core.Time

   .. py:method:: start()

      :rtype: seiscomp.core.Time

   .. py:method:: setEnd(end)

      :param end: seiscomp.core.Time

   .. py:method:: end()

      :rtype: seiscomp.core.Time

      .. note::

         As this attribute is optional, this method throws a ValueError if
         the value of the attribute is not set.

   .. py:method:: qualityControl()

      :rtype: QualityControl

      Returns the parent QualityControl if available. Returns None
      if the parent is not a QualityControl. This is a convenience wrapper
      for parent().

   .. py:method:: assign(other)

      This method implements the :ref:`Object <api-python-datamodel-object>` interface.

   .. py:method:: attachTo(parent)

      This method implements the :ref:`Object <api-python-datamodel-object>` interface.

   .. py:method:: detachFrom(parent)

      This method implements the :ref:`Object <api-python-datamodel-object>` interface.

   .. py:method:: detach()

      This method implements the :ref:`Object <api-python-datamodel-object>` interface.

   .. py:method:: clone()

      :rtype: A cloned Outage.

      Returns a new instance that is a clone of the current instance. Child
      objects are being ignored.


   .. py:method:: accept(visitor)

      :param visitor: A visitor.

      This method implements the :ref:`PublicObject <api-python-datamodel-publicobject>` interface.

.. _api-python-datamodel-parameter:

Parameter
............................................................

.. py:class:: Parameter

   Inherits :ref:`PublicObject <api-python-datamodel-publicobject>`.


   **Parents**:

   - ``parameterSet`` -- :ref:`ParameterSet <api-python-datamodel-parameterset>`

   **Children**:

   - ``comment`` -- :ref:`Comment <api-python-datamodel-comment>`

   **Attributes**:

   - ``publicID``: string
   - ``name`` -- string
   - ``value`` -- string

   **Methods**:

   .. py:staticmethod:: Cast(obj)

      :param obj: The object to be casted.
      :rtype: An object of type Parameter if the cast was successful,
              None otherwise.

      Cast an arbitrary object to Parameter if the internal wrapped
      representation is an Parameter object. The cast is important if
      instances of type :ref:`Object <api-python-datamodel-object>`
      are passed to methods which need access to the real type.



   .. py:staticmethod:: Create()

      :rtype: A new object of type Parameter.

      Creates and registers (if enabled) a Parameter instance. The
      publicID is auto-generated.

   .. py:staticmethod:: Create(publicID)

      :rtype: A new object of type Parameter.

      Creates and registers (if enabled) a Parameter instance with
      passed publicID.

   .. py:method:: equal(other)

      :param other: Another object of type Parameter to compare this
                    instance to
      :rtype: A Boolean value indicating True if both objects are equal or
              False otherwise.

      Compares two objects without its child objects. Both objects are compared
      by value.

   .. py:method:: setName(name)

      :param name: string

   .. py:method:: name()

      :rtype: string

   .. py:method:: setValue(value)

      :param value: string

   .. py:method:: value()

      :rtype: string

   .. py:method:: add(comment)

      :param comment: Object of type :ref:`Comment <api-python-datamodel-comment>`
      :rtype: A Boolean value indicating success with True, False otherwise.

      Adds a Comment object to Parameter. The object is not
      copied but managed by this instance. Any change to the passed object
      will also change the child.

   .. py:method:: remove(comment)

      :param comment: Object of type :ref:`Comment <api-python-datamodel-comment>`
      :rtype: A Boolean value indicating success with True, False otherwise.

      Removes a previously added Comment object from Parameter.

   .. py:method:: removeComment(idx)

      :param idx: An integer index of the object to be removed.
      :rtype: A Boolean value indicating success with True, False otherwise.

   .. py:method:: removeComment(commentIndex);

      :param commentIndex: The index of the object to be removed of type CommentIndex.
      :rtype: A Boolean value indicating success with True, False otherwise.

   .. py:method:: commentCount()

      :rtype: integer value indicating the number of child objects.

      Returns the number of Comment child objects.

   .. py:method:: comment(idx)

      :param idx: An integer index of the object to be returned.
      :rtype: Object of type :ref:`Comment <api-python-datamodel-comment>`.

      Returns the Comment at index idx.

   .. py:method:: comment(commentIndex)

      :param commentIndex: The index of the object to be removed of type CommentIndex.
      :rtype: Object of type :ref:`Comment <api-python-datamodel-comment>`.

      Returns the Comment at given index. The indexes of all child objects
      are compared by value which makes this function slower than the direct
      integer index look-up.

   .. py:method:: parameterSet()

      :rtype: ParameterSet

      Returns the parent ParameterSet if available. Returns None
      if the parent is not a ParameterSet. This is a convenience wrapper
      for parent().

   .. py:method:: assign(other)

      This method implements the :ref:`Object <api-python-datamodel-object>` interface.

   .. py:method:: attachTo(parent)

      This method implements the :ref:`Object <api-python-datamodel-object>` interface.

   .. py:method:: detachFrom(parent)

      This method implements the :ref:`Object <api-python-datamodel-object>` interface.

   .. py:method:: detach()

      This method implements the :ref:`Object <api-python-datamodel-object>` interface.

   .. py:method:: clone()

      :rtype: A cloned Parameter.

      Returns a new instance that is a clone of the current instance. Child
      objects are being ignored.


   .. py:method:: updateChild(ref)

      :param ref: A child object derived from class Object.
      :rtype: A Boolean flag indicating success with True, False otherwise

      This method takes the passed reference object and searches for a child
      with the same publicID (if derived from :ref:`PublicObject <api-python-datamodel-publicobject>`)
      or the same index (if derived from :ref:`Object <api-python-datamodel-object>`).
      The the child was found the reference objects attributes are copied to
      the child object. Children of child are being ignored during this operation.
      This method implements the :ref:`PublicObject <api-python-datamodel-publicobject>` interface.


   .. py:method:: accept(visitor)

      :param visitor: A visitor.

      This method implements the :ref:`PublicObject <api-python-datamodel-publicobject>` interface.

.. _api-python-datamodel-parameterset:

ParameterSet
............................................................

.. py:class:: ParameterSet

   Inherits :ref:`PublicObject <api-python-datamodel-publicobject>`.


   **Parents**:

   - ``config`` -- :ref:`Config <api-python-datamodel-config>`

   **Children**:

   - ``parameter`` -- :ref:`Parameter <api-python-datamodel-parameter>`
   - ``comment`` -- :ref:`Comment <api-python-datamodel-comment>`

   **Attributes**:

   - ``publicID``: string
   - ``baseID`` -- string
   - ``moduleID`` -- string
   - ``created`` -- seiscomp.core.Time (optional)

   **Referenced by**:

   - :func:`ConfigModule.parameterSetID`
   - :func:`ParameterSet.baseID`
   - :func:`Setup.parameterSetID`

   **Methods**:

   .. py:staticmethod:: Cast(obj)

      :param obj: The object to be casted.
      :rtype: An object of type ParameterSet if the cast was successful,
              None otherwise.

      Cast an arbitrary object to ParameterSet if the internal wrapped
      representation is an ParameterSet object. The cast is important if
      instances of type :ref:`Object <api-python-datamodel-object>`
      are passed to methods which need access to the real type.



   .. py:staticmethod:: Create()

      :rtype: A new object of type ParameterSet.

      Creates and registers (if enabled) a ParameterSet instance. The
      publicID is auto-generated.

   .. py:staticmethod:: Create(publicID)

      :rtype: A new object of type ParameterSet.

      Creates and registers (if enabled) a ParameterSet instance with
      passed publicID.

   .. py:method:: equal(other)

      :param other: Another object of type ParameterSet to compare this
                    instance to
      :rtype: A Boolean value indicating True if both objects are equal or
              False otherwise.

      Compares two objects without its child objects. Both objects are compared
      by value.

   .. py:method:: setBaseID(baseID)

      :param baseID: string

   .. py:method:: baseID()

      :rtype: string

   .. py:method:: setModuleID(moduleID)

      :param moduleID: string

   .. py:method:: moduleID()

      :rtype: string

   .. py:method:: setCreated(created)

      :param created: seiscomp.core.Time

   .. py:method:: created()

      :rtype: seiscomp.core.Time

      .. note::

         As this attribute is optional, this method throws a ValueError if
         the value of the attribute is not set.

   .. py:method:: add(parameter)

      :param parameter: Object of type :ref:`Parameter <api-python-datamodel-parameter>`
      :rtype: A Boolean value indicating success with True, False otherwise.

      Adds a Parameter object to ParameterSet. The object is not
      copied but managed by this instance. Any change to the passed object
      will also change the child.

   .. py:method:: add(comment)

      :param comment: Object of type :ref:`Comment <api-python-datamodel-comment>`
      :rtype: A Boolean value indicating success with True, False otherwise.

      Adds a Comment object to ParameterSet. The object is not
      copied but managed by this instance. Any change to the passed object
      will also change the child.

   .. py:method:: remove(parameter)

      :param parameter: Object of type :ref:`Parameter <api-python-datamodel-parameter>`
      :rtype: A Boolean value indicating success with True, False otherwise.

      Removes a previously added Parameter object from ParameterSet.

   .. py:method:: remove(comment)

      :param comment: Object of type :ref:`Comment <api-python-datamodel-comment>`
      :rtype: A Boolean value indicating success with True, False otherwise.

      Removes a previously added Comment object from ParameterSet.

   .. py:method:: removeParameter(idx)

      :param idx: An integer index of the object to be removed.
      :rtype: A Boolean value indicating success with True, False otherwise.

   .. py:method:: removeComment(idx)

      :param idx: An integer index of the object to be removed.
      :rtype: A Boolean value indicating success with True, False otherwise.

   .. py:method:: removeComment(commentIndex);

      :param commentIndex: The index of the object to be removed of type CommentIndex.
      :rtype: A Boolean value indicating success with True, False otherwise.

   .. py:method:: parameterCount()

      :rtype: integer value indicating the number of child objects.

      Returns the number of Parameter child objects.

   .. py:method:: commentCount()

      :rtype: integer value indicating the number of child objects.

      Returns the number of Comment child objects.

   .. py:method:: parameter(idx)

      :param idx: An integer index of the object to be returned.
      :rtype: Object of type :ref:`Parameter <api-python-datamodel-parameter>`.

      Returns the Parameter at index idx.

   .. py:method:: comment(idx)

      :param idx: An integer index of the object to be returned.
      :rtype: Object of type :ref:`Comment <api-python-datamodel-comment>`.

      Returns the Comment at index idx.

   .. py:method:: comment(commentIndex)

      :param commentIndex: The index of the object to be removed of type CommentIndex.
      :rtype: Object of type :ref:`Comment <api-python-datamodel-comment>`.

      Returns the Comment at given index. The indexes of all child objects
      are compared by value which makes this function slower than the direct
      integer index look-up.

   .. py:method:: findParameter(publicID)

      :param publicID: The publicID of the object to find.
      :rtype: Object of type :ref:`Parameter <api-python-datamodel-parameter>`.

      Returns the child object with a certain publicID, None otherwise.

   .. py:method:: config()

      :rtype: Config

      Returns the parent Config if available. Returns None
      if the parent is not a Config. This is a convenience wrapper
      for parent().

   .. py:method:: assign(other)

      This method implements the :ref:`Object <api-python-datamodel-object>` interface.

   .. py:method:: attachTo(parent)

      This method implements the :ref:`Object <api-python-datamodel-object>` interface.

   .. py:method:: detachFrom(parent)

      This method implements the :ref:`Object <api-python-datamodel-object>` interface.

   .. py:method:: detach()

      This method implements the :ref:`Object <api-python-datamodel-object>` interface.

   .. py:method:: clone()

      :rtype: A cloned ParameterSet.

      Returns a new instance that is a clone of the current instance. Child
      objects are being ignored.


   .. py:method:: updateChild(ref)

      :param ref: A child object derived from class Object.
      :rtype: A Boolean flag indicating success with True, False otherwise

      This method takes the passed reference object and searches for a child
      with the same publicID (if derived from :ref:`PublicObject <api-python-datamodel-publicobject>`)
      or the same index (if derived from :ref:`Object <api-python-datamodel-object>`).
      The the child was found the reference objects attributes are copied to
      the child object. Children of child are being ignored during this operation.
      This method implements the :ref:`PublicObject <api-python-datamodel-publicobject>` interface.


   .. py:method:: accept(visitor)

      :param visitor: A visitor.

      This method implements the :ref:`PublicObject <api-python-datamodel-publicobject>` interface.

.. _api-python-datamodel-phase:

Phase
............................................................

.. py:class:: Phase

   Inherits :ref:`Object <api-python-datamodel-object>`.

   Generic and extensible phase description that currently contains the phase code
   only.

   **Attributes**:

   - ``code`` -- string

   **Used by**:

   - :func:`Arrival.phase`
   - :func:`Pick.phaseHint`

   **Methods**:

   .. py:staticmethod:: Cast(obj)

      :param obj: The object to be casted.
      :rtype: An object of type Phase if the cast was successful,
              None otherwise.

      Cast an arbitrary object to Phase if the internal wrapped
      representation is an Phase object. The cast is important if
      instances of type :ref:`Object <api-python-datamodel-object>`
      are passed to methods which need access to the real type.



   .. py:method:: equal(other)

      :param other: Another object of type Phase to compare this
                    instance to
      :rtype: A Boolean value indicating True if both objects are equal or
              False otherwise.

      Compares two objects without its child objects. Both objects are compared
      by value.

   .. py:method:: setCode(code)

      :param code: string

      Phase code as given in the IASPEI Standard Seismic Phase List
      \(Storchak et al. 2003\). String with a maximum length of 32 characters.

   .. py:method:: code()

      :rtype: string

.. _api-python-datamodel-pick:

Pick
............................................................

.. py:class:: Pick

   Inherits :ref:`PublicObject <api-python-datamodel-publicobject>`.

   A pick is the observation of an amplitude anomaly in a seismogram at a
   specific point in time. It is not necessarily related to a seismic event.

   **Parents**:

   - ``eventParameters`` -- :ref:`EventParameters <api-python-datamodel-eventparameters>`

   **Children**:

   - ``comment`` -- :ref:`Comment <api-python-datamodel-comment>`

   **Attributes**:

   - ``publicID``: string
   - ``time`` -- :ref:`TimeQuantity <api-python-datamodel-timequantity>`
   - ``waveformID`` -- :ref:`WaveformStreamID <api-python-datamodel-waveformstreamid>`
   - ``filterID`` -- string
   - ``methodID`` -- string
   - ``horizontalSlowness`` -- :ref:`RealQuantity <api-python-datamodel-realquantity>` (optional)
   - ``backazimuth`` -- :ref:`RealQuantity <api-python-datamodel-realquantity>` (optional)
   - ``slownessMethodID`` -- string
   - ``onset`` -- :ref:`PickOnset <api-python-datamodel-pickonset>` (optional)
   - ``phaseHint`` -- :ref:`Phase <api-python-datamodel-phase>` (optional)
   - ``polarity`` -- :ref:`PickPolarity <api-python-datamodel-pickpolarity>` (optional)
   - ``evaluationMode`` -- :ref:`EvaluationMode <api-python-datamodel-evaluationmode>` (optional)
   - ``evaluationStatus`` -- :ref:`EvaluationStatus <api-python-datamodel-evaluationstatus>` (optional)
   - ``creationInfo`` -- :ref:`CreationInfo <api-python-datamodel-creationinfo>` (optional)

   **Referenced by**:

   - :func:`Amplitude.pickID`
   - :func:`Arrival.pickID`
   - :func:`PickReference.pickID`

   **Methods**:

   .. py:staticmethod:: Cast(obj)

      :param obj: The object to be casted.
      :rtype: An object of type Pick if the cast was successful,
              None otherwise.

      Cast an arbitrary object to Pick if the internal wrapped
      representation is an Pick object. The cast is important if
      instances of type :ref:`Object <api-python-datamodel-object>`
      are passed to methods which need access to the real type.



   .. py:staticmethod:: Create()

      :rtype: A new object of type Pick.

      Creates and registers (if enabled) a Pick instance. The
      publicID is auto-generated.

   .. py:staticmethod:: Create(publicID)

      :rtype: A new object of type Pick.

      Creates and registers (if enabled) a Pick instance with
      passed publicID.

   .. py:method:: equal(other)

      :param other: Another object of type Pick to compare this
                    instance to
      :rtype: A Boolean value indicating True if both objects are equal or
              False otherwise.

      Compares two objects without its child objects. Both objects are compared
      by value.

   .. py:method:: setTime(time)

      :param time: :ref:`TimeQuantity <api-python-datamodel-timequantity>`

      Observed onset time of signal \(\"pick time\"\).

   .. py:method:: time()

      :rtype: :ref:`TimeQuantity <api-python-datamodel-timequantity>`

   .. py:method:: setWaveformID(waveformID)

      :param waveformID: :ref:`WaveformStreamID <api-python-datamodel-waveformstreamid>`

      Identifes the waveform stream.

   .. py:method:: waveformID()

      :rtype: :ref:`WaveformStreamID <api-python-datamodel-waveformstreamid>`

   .. py:method:: setFilterID(filterID)

      :param filterID: string

      Identifies the filter or filter setup used for filtering the waveform
      stream referenced by waveformID.

   .. py:method:: filterID()

      :rtype: string

   .. py:method:: setMethodID(methodID)

      :param methodID: string

      Identifies the picker that produced the pick. This can be either a
      detection software program or a person.

   .. py:method:: methodID()

      :rtype: string

   .. py:method:: setHorizontalSlowness(horizontalSlowness)

      :param horizontalSlowness: :ref:`RealQuantity <api-python-datamodel-realquantity>`

      Observed horizontal slowness of the signal. Most relevant in array
      measurements
      in s\/deg.

   .. py:method:: horizontalSlowness()

      :rtype: :ref:`RealQuantity <api-python-datamodel-realquantity>`

      .. note::

         As this attribute is optional, this method throws a ValueError if
         the value of the attribute is not set.

   .. py:method:: setBackazimuth(backazimuth)

      :param backazimuth: :ref:`RealQuantity <api-python-datamodel-realquantity>`

      Observed backazimuth of the signal. Most relevant in array measurements
      in degrees.

   .. py:method:: backazimuth()

      :rtype: :ref:`RealQuantity <api-python-datamodel-realquantity>`

      .. note::

         As this attribute is optional, this method throws a ValueError if
         the value of the attribute is not set.

   .. py:method:: setSlownessMethodID(slownessMethodID)

      :param slownessMethodID: string

      Identifies the method that was used to determine the slowness.

   .. py:method:: slownessMethodID()

      :rtype: string

   .. py:method:: setOnset(onset)

      :param onset: PickOnset

      Flag that roughly categorizes the sharpness of the onset.

   .. py:method:: onset()

      :rtype: PickOnset

      .. note::

         As this attribute is optional, this method throws a ValueError if
         the value of the attribute is not set.

   .. py:method:: setPhaseHint(phaseHint)

      :param phaseHint: :ref:`Phase <api-python-datamodel-phase>`

      Tentative phase identification as specified by the picker.

   .. py:method:: phaseHint()

      :rtype: :ref:`Phase <api-python-datamodel-phase>`

      .. note::

         As this attribute is optional, this method throws a ValueError if
         the value of the attribute is not set.

   .. py:method:: setPolarity(polarity)

      :param polarity: PickPolarity

      Indicates the polarity of first motion, usually from impulsive onsets.

   .. py:method:: polarity()

      :rtype: PickPolarity

      .. note::

         As this attribute is optional, this method throws a ValueError if
         the value of the attribute is not set.

   .. py:method:: setEvaluationMode(evaluationMode)

      :param evaluationMode: EvaluationMode

      Evaluation mode of Pick.

   .. py:method:: evaluationMode()

      :rtype: EvaluationMode

      .. note::

         As this attribute is optional, this method throws a ValueError if
         the value of the attribute is not set.

   .. py:method:: setEvaluationStatus(evaluationStatus)

      :param evaluationStatus: EvaluationStatus

      Evaluation status of Pick.

   .. py:method:: evaluationStatus()

      :rtype: EvaluationStatus

      .. note::

         As this attribute is optional, this method throws a ValueError if
         the value of the attribute is not set.

   .. py:method:: setCreationInfo(creationInfo)

      :param creationInfo: :ref:`CreationInfo <api-python-datamodel-creationinfo>`

      CreationInfo for the Pick object.

   .. py:method:: creationInfo()

      :rtype: :ref:`CreationInfo <api-python-datamodel-creationinfo>`

      .. note::

         As this attribute is optional, this method throws a ValueError if
         the value of the attribute is not set.

   .. py:method:: add(comment)

      :param comment: Object of type :ref:`Comment <api-python-datamodel-comment>`
      :rtype: A Boolean value indicating success with True, False otherwise.

      Adds a Comment object to Pick. The object is not
      copied but managed by this instance. Any change to the passed object
      will also change the child.

   .. py:method:: remove(comment)

      :param comment: Object of type :ref:`Comment <api-python-datamodel-comment>`
      :rtype: A Boolean value indicating success with True, False otherwise.

      Removes a previously added Comment object from Pick.

   .. py:method:: removeComment(idx)

      :param idx: An integer index of the object to be removed.
      :rtype: A Boolean value indicating success with True, False otherwise.

   .. py:method:: removeComment(commentIndex);

      :param commentIndex: The index of the object to be removed of type CommentIndex.
      :rtype: A Boolean value indicating success with True, False otherwise.

   .. py:method:: commentCount()

      :rtype: integer value indicating the number of child objects.

      Returns the number of Comment child objects.

   .. py:method:: comment(idx)

      :param idx: An integer index of the object to be returned.
      :rtype: Object of type :ref:`Comment <api-python-datamodel-comment>`.

      Returns the Comment at index idx.

   .. py:method:: comment(commentIndex)

      :param commentIndex: The index of the object to be removed of type CommentIndex.
      :rtype: Object of type :ref:`Comment <api-python-datamodel-comment>`.

      Returns the Comment at given index. The indexes of all child objects
      are compared by value which makes this function slower than the direct
      integer index look-up.

   .. py:method:: eventParameters()

      :rtype: EventParameters

      Returns the parent EventParameters if available. Returns None
      if the parent is not a EventParameters. This is a convenience wrapper
      for parent().

   .. py:method:: assign(other)

      This method implements the :ref:`Object <api-python-datamodel-object>` interface.

   .. py:method:: attachTo(parent)

      This method implements the :ref:`Object <api-python-datamodel-object>` interface.

   .. py:method:: detachFrom(parent)

      This method implements the :ref:`Object <api-python-datamodel-object>` interface.

   .. py:method:: detach()

      This method implements the :ref:`Object <api-python-datamodel-object>` interface.

   .. py:method:: clone()

      :rtype: A cloned Pick.

      Returns a new instance that is a clone of the current instance. Child
      objects are being ignored.


   .. py:method:: updateChild(ref)

      :param ref: A child object derived from class Object.
      :rtype: A Boolean flag indicating success with True, False otherwise

      This method takes the passed reference object and searches for a child
      with the same publicID (if derived from :ref:`PublicObject <api-python-datamodel-publicobject>`)
      or the same index (if derived from :ref:`Object <api-python-datamodel-object>`).
      The the child was found the reference objects attributes are copied to
      the child object. Children of child are being ignored during this operation.
      This method implements the :ref:`PublicObject <api-python-datamodel-publicobject>` interface.


   .. py:method:: accept(visitor)

      :param visitor: A visitor.

      This method implements the :ref:`PublicObject <api-python-datamodel-publicobject>` interface.

.. _api-python-datamodel-pickreference:

PickReference
............................................................

.. py:class:: PickReference

   Inherits :ref:`Object <api-python-datamodel-object>`.


   **Parents**:

   - ``reading`` -- :ref:`Reading <api-python-datamodel-reading>`

   **Attributes**:

   - ``pickID`` -- string

   **Methods**:

   .. py:staticmethod:: Cast(obj)

      :param obj: The object to be casted.
      :rtype: An object of type PickReference if the cast was successful,
              None otherwise.

      Cast an arbitrary object to PickReference if the internal wrapped
      representation is an PickReference object. The cast is important if
      instances of type :ref:`Object <api-python-datamodel-object>`
      are passed to methods which need access to the real type.



   .. py:method:: equal(other)

      :param other: Another object of type PickReference to compare this
                    instance to
      :rtype: A Boolean value indicating True if both objects are equal or
              False otherwise.

      Compares two objects without its child objects. Both objects are compared
      by value.

   .. py:method:: index()

      :rtype: The object's index of type PickReferenceIndex.

       Returns the objects index which is also used for the database as unique
       constraint.

   .. py:method:: equalIndex(lhs)

      :param lhs: :ref:`PickReference <api-python-datamodel-pickreference>`
      :rtype: A Boolean value indicating True if both indexes are equal or
              False otherwise.

   .. py:method:: setPickID(pickID)

      :param pickID: string

   .. py:method:: pickID()

      :rtype: string

   .. py:method:: reading()

      :rtype: Reading

      Returns the parent Reading if available. Returns None
      if the parent is not a Reading. This is a convenience wrapper
      for parent().

   .. py:method:: assign(other)

      This method implements the :ref:`Object <api-python-datamodel-object>` interface.

   .. py:method:: attachTo(parent)

      This method implements the :ref:`Object <api-python-datamodel-object>` interface.

   .. py:method:: detachFrom(parent)

      This method implements the :ref:`Object <api-python-datamodel-object>` interface.

   .. py:method:: detach()

      This method implements the :ref:`Object <api-python-datamodel-object>` interface.

   .. py:method:: clone()

      :rtype: A cloned PickReference.

      Returns a new instance that is a clone of the current instance. Child
      objects are being ignored.


   .. py:method:: accept(visitor)

      :param visitor: A visitor.

      This method implements the :ref:`PublicObject <api-python-datamodel-publicobject>` interface.

.. _api-python-datamodel-principalaxes:

PrincipalAxes
............................................................

.. py:class:: PrincipalAxes

   Inherits :ref:`Object <api-python-datamodel-object>`.

   This class describes the principal axes of a double\-couple moment tensor
   solution. tAxis and pAxis are required,
   while nAxis is optional.

   **Attributes**:

   - ``tAxis`` -- :ref:`Axis <api-python-datamodel-axis>`
   - ``pAxis`` -- :ref:`Axis <api-python-datamodel-axis>`
   - ``nAxis`` -- :ref:`Axis <api-python-datamodel-axis>` (optional)

   **Used by**:

   - :func:`FocalMechanism.principalAxes`

   **Methods**:

   .. py:staticmethod:: Cast(obj)

      :param obj: The object to be casted.
      :rtype: An object of type PrincipalAxes if the cast was successful,
              None otherwise.

      Cast an arbitrary object to PrincipalAxes if the internal wrapped
      representation is an PrincipalAxes object. The cast is important if
      instances of type :ref:`Object <api-python-datamodel-object>`
      are passed to methods which need access to the real type.



   .. py:method:: equal(other)

      :param other: Another object of type PrincipalAxes to compare this
                    instance to
      :rtype: A Boolean value indicating True if both objects are equal or
              False otherwise.

      Compares two objects without its child objects. Both objects are compared
      by value.

   .. py:method:: setTAxis(tAxis)

      :param tAxis: :ref:`Axis <api-python-datamodel-axis>`

      T \(tension\) axis of a double\-couple moment tensor solution.

   .. py:method:: tAxis()

      :rtype: :ref:`Axis <api-python-datamodel-axis>`

   .. py:method:: setPAxis(pAxis)

      :param pAxis: :ref:`Axis <api-python-datamodel-axis>`

      P \(pressure\) axis of a double\-couple moment tensor solution.

   .. py:method:: pAxis()

      :rtype: :ref:`Axis <api-python-datamodel-axis>`

   .. py:method:: setNAxis(nAxis)

      :param nAxis: :ref:`Axis <api-python-datamodel-axis>`

      N \(neutral\) axis of a double\-couple moment tensor solution.

   .. py:method:: nAxis()

      :rtype: :ref:`Axis <api-python-datamodel-axis>`

      .. note::

         As this attribute is optional, this method throws a ValueError if
         the value of the attribute is not set.

.. _api-python-datamodel-qclog:

QCLog
............................................................

.. py:class:: QCLog

   Inherits :ref:`PublicObject <api-python-datamodel-publicobject>`.


   **Parents**:

   - ``qualityControl`` -- :ref:`QualityControl <api-python-datamodel-qualitycontrol>`

   **Attributes**:

   - ``publicID``: string
   - ``waveformID`` -- :ref:`WaveformStreamID <api-python-datamodel-waveformstreamid>`
   - ``creatorID`` -- string
   - ``created`` -- seiscomp.core.Time
   - ``start`` -- seiscomp.core.Time
   - ``end`` -- seiscomp.core.Time
   - ``message`` -- string

   **Methods**:

   .. py:staticmethod:: Cast(obj)

      :param obj: The object to be casted.
      :rtype: An object of type QCLog if the cast was successful,
              None otherwise.

      Cast an arbitrary object to QCLog if the internal wrapped
      representation is an QCLog object. The cast is important if
      instances of type :ref:`Object <api-python-datamodel-object>`
      are passed to methods which need access to the real type.



   .. py:staticmethod:: Create()

      :rtype: A new object of type QCLog.

      Creates and registers (if enabled) a QCLog instance. The
      publicID is auto-generated.

   .. py:staticmethod:: Create(publicID)

      :rtype: A new object of type QCLog.

      Creates and registers (if enabled) a QCLog instance with
      passed publicID.

   .. py:method:: equal(other)

      :param other: Another object of type QCLog to compare this
                    instance to
      :rtype: A Boolean value indicating True if both objects are equal or
              False otherwise.

      Compares two objects without its child objects. Both objects are compared
      by value.

   .. py:method:: index()

      :rtype: The object's index of type QCLogIndex.

       Returns the objects index which is also used for the database as unique
       constraint.

   .. py:method:: equalIndex(lhs)

      :param lhs: :ref:`QCLog <api-python-datamodel-qclog>`
      :rtype: A Boolean value indicating True if both indexes are equal or
              False otherwise.

   .. py:method:: setWaveformID(waveformID)

      :param waveformID: :ref:`WaveformStreamID <api-python-datamodel-waveformstreamid>`

   .. py:method:: waveformID()

      :rtype: :ref:`WaveformStreamID <api-python-datamodel-waveformstreamid>`

   .. py:method:: setCreatorID(creatorID)

      :param creatorID: string

   .. py:method:: creatorID()

      :rtype: string

   .. py:method:: setCreated(created)

      :param created: seiscomp.core.Time

   .. py:method:: created()

      :rtype: seiscomp.core.Time

   .. py:method:: setStart(start)

      :param start: seiscomp.core.Time

   .. py:method:: start()

      :rtype: seiscomp.core.Time

   .. py:method:: setEnd(end)

      :param end: seiscomp.core.Time

   .. py:method:: end()

      :rtype: seiscomp.core.Time

   .. py:method:: setMessage(message)

      :param message: string

   .. py:method:: message()

      :rtype: string

   .. py:method:: qualityControl()

      :rtype: QualityControl

      Returns the parent QualityControl if available. Returns None
      if the parent is not a QualityControl. This is a convenience wrapper
      for parent().

   .. py:method:: assign(other)

      This method implements the :ref:`Object <api-python-datamodel-object>` interface.

   .. py:method:: attachTo(parent)

      This method implements the :ref:`Object <api-python-datamodel-object>` interface.

   .. py:method:: detachFrom(parent)

      This method implements the :ref:`Object <api-python-datamodel-object>` interface.

   .. py:method:: detach()

      This method implements the :ref:`Object <api-python-datamodel-object>` interface.

   .. py:method:: clone()

      :rtype: A cloned QCLog.

      Returns a new instance that is a clone of the current instance. Child
      objects are being ignored.


   .. py:method:: updateChild(ref)

      :param ref: A child object derived from class Object.
      :rtype: A Boolean flag indicating success with True, False otherwise

      This method takes the passed reference object and searches for a child
      with the same publicID (if derived from :ref:`PublicObject <api-python-datamodel-publicobject>`)
      or the same index (if derived from :ref:`Object <api-python-datamodel-object>`).
      The the child was found the reference objects attributes are copied to
      the child object. Children of child are being ignored during this operation.
      This method implements the :ref:`PublicObject <api-python-datamodel-publicobject>` interface.


   .. py:method:: accept(visitor)

      :param visitor: A visitor.

      This method implements the :ref:`PublicObject <api-python-datamodel-publicobject>` interface.

.. _api-python-datamodel-qualitycontrol:

QualityControl
............................................................

.. py:class:: QualityControl

   Inherits :ref:`PublicObject <api-python-datamodel-publicobject>`.


   **Children**:

   - ``qCLog`` -- :ref:`QCLog <api-python-datamodel-qclog>`
   - ``waveformQuality`` -- :ref:`WaveformQuality <api-python-datamodel-waveformquality>`
   - ``outage`` -- :ref:`Outage <api-python-datamodel-outage>`

   **Attributes**:

   - ``publicID``: string

   **Methods**:

   .. py:staticmethod:: Cast(obj)

      :param obj: The object to be casted.
      :rtype: An object of type QualityControl if the cast was successful,
              None otherwise.

      Cast an arbitrary object to QualityControl if the internal wrapped
      representation is an QualityControl object. The cast is important if
      instances of type :ref:`Object <api-python-datamodel-object>`
      are passed to methods which need access to the real type.



   .. py:method:: equal(other)

      :param other: Another object of type QualityControl to compare this
                    instance to
      :rtype: A Boolean value indicating True if both objects are equal or
              False otherwise.

      Compares two objects without its child objects. Both objects are compared
      by value.

   .. py:method:: add(qCLog)

      :param qCLog: Object of type :ref:`QCLog <api-python-datamodel-qclog>`
      :rtype: A Boolean value indicating success with True, False otherwise.

      Adds a QCLog object to QualityControl. The object is not
      copied but managed by this instance. Any change to the passed object
      will also change the child.

   .. py:method:: add(waveformQuality)

      :param waveformQuality: Object of type :ref:`WaveformQuality <api-python-datamodel-waveformquality>`
      :rtype: A Boolean value indicating success with True, False otherwise.

      Adds a WaveformQuality object to QualityControl. The object is not
      copied but managed by this instance. Any change to the passed object
      will also change the child.

   .. py:method:: add(outage)

      :param outage: Object of type :ref:`Outage <api-python-datamodel-outage>`
      :rtype: A Boolean value indicating success with True, False otherwise.

      Adds a Outage object to QualityControl. The object is not
      copied but managed by this instance. Any change to the passed object
      will also change the child.

   .. py:method:: remove(qCLog)

      :param qCLog: Object of type :ref:`QCLog <api-python-datamodel-qclog>`
      :rtype: A Boolean value indicating success with True, False otherwise.

      Removes a previously added QCLog object from QualityControl.

   .. py:method:: remove(waveformQuality)

      :param waveformQuality: Object of type :ref:`WaveformQuality <api-python-datamodel-waveformquality>`
      :rtype: A Boolean value indicating success with True, False otherwise.

      Removes a previously added WaveformQuality object from QualityControl.

   .. py:method:: remove(outage)

      :param outage: Object of type :ref:`Outage <api-python-datamodel-outage>`
      :rtype: A Boolean value indicating success with True, False otherwise.

      Removes a previously added Outage object from QualityControl.

   .. py:method:: removeQCLog(idx)

      :param idx: An integer index of the object to be removed.
      :rtype: A Boolean value indicating success with True, False otherwise.

   .. py:method:: removeQCLog(qCLogIndex);

      :param qCLogIndex: The index of the object to be removed of type QCLogIndex.
      :rtype: A Boolean value indicating success with True, False otherwise.

   .. py:method:: removeWaveformQuality(idx)

      :param idx: An integer index of the object to be removed.
      :rtype: A Boolean value indicating success with True, False otherwise.

   .. py:method:: removeWaveformQuality(waveformQualityIndex);

      :param waveformQualityIndex: The index of the object to be removed of type WaveformQualityIndex.
      :rtype: A Boolean value indicating success with True, False otherwise.

   .. py:method:: removeOutage(idx)

      :param idx: An integer index of the object to be removed.
      :rtype: A Boolean value indicating success with True, False otherwise.

   .. py:method:: removeOutage(outageIndex);

      :param outageIndex: The index of the object to be removed of type OutageIndex.
      :rtype: A Boolean value indicating success with True, False otherwise.

   .. py:method:: qCLogCount()

      :rtype: integer value indicating the number of child objects.

      Returns the number of QCLog child objects.

   .. py:method:: waveformQualityCount()

      :rtype: integer value indicating the number of child objects.

      Returns the number of WaveformQuality child objects.

   .. py:method:: outageCount()

      :rtype: integer value indicating the number of child objects.

      Returns the number of Outage child objects.

   .. py:method:: qCLog(idx)

      :param idx: An integer index of the object to be returned.
      :rtype: Object of type :ref:`QCLog <api-python-datamodel-qclog>`.

      Returns the QCLog at index idx.

   .. py:method:: qCLog(qCLogIndex)

      :param qCLogIndex: The index of the object to be removed of type QCLogIndex.
      :rtype: Object of type :ref:`QCLog <api-python-datamodel-qclog>`.

      Returns the QCLog at given index. The indexes of all child objects
      are compared by value which makes this function slower than the direct
      integer index look-up.

   .. py:method:: waveformQuality(idx)

      :param idx: An integer index of the object to be returned.
      :rtype: Object of type :ref:`WaveformQuality <api-python-datamodel-waveformquality>`.

      Returns the WaveformQuality at index idx.

   .. py:method:: waveformQuality(waveformQualityIndex)

      :param waveformQualityIndex: The index of the object to be removed of type WaveformQualityIndex.
      :rtype: Object of type :ref:`WaveformQuality <api-python-datamodel-waveformquality>`.

      Returns the WaveformQuality at given index. The indexes of all child objects
      are compared by value which makes this function slower than the direct
      integer index look-up.

   .. py:method:: outage(idx)

      :param idx: An integer index of the object to be returned.
      :rtype: Object of type :ref:`Outage <api-python-datamodel-outage>`.

      Returns the Outage at index idx.

   .. py:method:: outage(outageIndex)

      :param outageIndex: The index of the object to be removed of type OutageIndex.
      :rtype: Object of type :ref:`Outage <api-python-datamodel-outage>`.

      Returns the Outage at given index. The indexes of all child objects
      are compared by value which makes this function slower than the direct
      integer index look-up.

   .. py:method:: findQCLog(publicID)

      :param publicID: The publicID of the object to find.
      :rtype: Object of type :ref:`QCLog <api-python-datamodel-qclog>`.

      Returns the child object with a certain publicID, None otherwise.

   .. py:method:: assign(other)

      This method implements the :ref:`Object <api-python-datamodel-object>` interface.

   .. py:method:: attachTo(parent)

      This method implements the :ref:`Object <api-python-datamodel-object>` interface.

   .. py:method:: detachFrom(parent)

      This method implements the :ref:`Object <api-python-datamodel-object>` interface.

   .. py:method:: detach()

      This method implements the :ref:`Object <api-python-datamodel-object>` interface.

   .. py:method:: clone()

      :rtype: A cloned QualityControl.

      Returns a new instance that is a clone of the current instance. Child
      objects are being ignored.


   .. py:method:: updateChild(ref)

      :param ref: A child object derived from class Object.
      :rtype: A Boolean flag indicating success with True, False otherwise

      This method takes the passed reference object and searches for a child
      with the same publicID (if derived from :ref:`PublicObject <api-python-datamodel-publicobject>`)
      or the same index (if derived from :ref:`Object <api-python-datamodel-object>`).
      The the child was found the reference objects attributes are copied to
      the child object. Children of child are being ignored during this operation.
      This method implements the :ref:`PublicObject <api-python-datamodel-publicobject>` interface.


   .. py:method:: accept(visitor)

      :param visitor: A visitor.

      This method implements the :ref:`PublicObject <api-python-datamodel-publicobject>` interface.

.. _api-python-datamodel-reading:

Reading
............................................................

.. py:class:: Reading

   Inherits :ref:`PublicObject <api-python-datamodel-publicobject>`.

   This class groups Pick and Amplitude elements which are thought to belong
   to the same event, but for which the event identification is not known.

   **Parents**:

   - ``eventParameters`` -- :ref:`EventParameters <api-python-datamodel-eventparameters>`

   **Children**:

   - ``pickReference`` -- :ref:`PickReference <api-python-datamodel-pickreference>`
   - ``amplitudeReference`` -- :ref:`AmplitudeReference <api-python-datamodel-amplitudereference>`

   **Attributes**:

   - ``publicID``: string

   **Methods**:

   .. py:staticmethod:: Cast(obj)

      :param obj: The object to be casted.
      :rtype: An object of type Reading if the cast was successful,
              None otherwise.

      Cast an arbitrary object to Reading if the internal wrapped
      representation is an Reading object. The cast is important if
      instances of type :ref:`Object <api-python-datamodel-object>`
      are passed to methods which need access to the real type.



   .. py:staticmethod:: Create()

      :rtype: A new object of type Reading.

      Creates and registers (if enabled) a Reading instance. The
      publicID is auto-generated.

   .. py:staticmethod:: Create(publicID)

      :rtype: A new object of type Reading.

      Creates and registers (if enabled) a Reading instance with
      passed publicID.

   .. py:method:: equal(other)

      :param other: Another object of type Reading to compare this
                    instance to
      :rtype: A Boolean value indicating True if both objects are equal or
              False otherwise.

      Compares two objects without its child objects. Both objects are compared
      by value.

   .. py:method:: add(pickReference)

      :param pickReference: Object of type :ref:`PickReference <api-python-datamodel-pickreference>`
      :rtype: A Boolean value indicating success with True, False otherwise.

      Adds a PickReference object to Reading. The object is not
      copied but managed by this instance. Any change to the passed object
      will also change the child.

   .. py:method:: add(amplitudeReference)

      :param amplitudeReference: Object of type :ref:`AmplitudeReference <api-python-datamodel-amplitudereference>`
      :rtype: A Boolean value indicating success with True, False otherwise.

      Adds a AmplitudeReference object to Reading. The object is not
      copied but managed by this instance. Any change to the passed object
      will also change the child.

   .. py:method:: remove(pickReference)

      :param pickReference: Object of type :ref:`PickReference <api-python-datamodel-pickreference>`
      :rtype: A Boolean value indicating success with True, False otherwise.

      Removes a previously added PickReference object from Reading.

   .. py:method:: remove(amplitudeReference)

      :param amplitudeReference: Object of type :ref:`AmplitudeReference <api-python-datamodel-amplitudereference>`
      :rtype: A Boolean value indicating success with True, False otherwise.

      Removes a previously added AmplitudeReference object from Reading.

   .. py:method:: removePickReference(idx)

      :param idx: An integer index of the object to be removed.
      :rtype: A Boolean value indicating success with True, False otherwise.

   .. py:method:: removePickReference(pickReferenceIndex);

      :param pickReferenceIndex: The index of the object to be removed of type PickReferenceIndex.
      :rtype: A Boolean value indicating success with True, False otherwise.

   .. py:method:: removeAmplitudeReference(idx)

      :param idx: An integer index of the object to be removed.
      :rtype: A Boolean value indicating success with True, False otherwise.

   .. py:method:: removeAmplitudeReference(amplitudeReferenceIndex);

      :param amplitudeReferenceIndex: The index of the object to be removed of type AmplitudeReferenceIndex.
      :rtype: A Boolean value indicating success with True, False otherwise.

   .. py:method:: pickReferenceCount()

      :rtype: integer value indicating the number of child objects.

      Returns the number of PickReference child objects.

   .. py:method:: amplitudeReferenceCount()

      :rtype: integer value indicating the number of child objects.

      Returns the number of AmplitudeReference child objects.

   .. py:method:: pickReference(idx)

      :param idx: An integer index of the object to be returned.
      :rtype: Object of type :ref:`PickReference <api-python-datamodel-pickreference>`.

      Returns the PickReference at index idx.

   .. py:method:: pickReference(pickReferenceIndex)

      :param pickReferenceIndex: The index of the object to be removed of type PickReferenceIndex.
      :rtype: Object of type :ref:`PickReference <api-python-datamodel-pickreference>`.

      Returns the PickReference at given index. The indexes of all child objects
      are compared by value which makes this function slower than the direct
      integer index look-up.

   .. py:method:: amplitudeReference(idx)

      :param idx: An integer index of the object to be returned.
      :rtype: Object of type :ref:`AmplitudeReference <api-python-datamodel-amplitudereference>`.

      Returns the AmplitudeReference at index idx.

   .. py:method:: amplitudeReference(amplitudeReferenceIndex)

      :param amplitudeReferenceIndex: The index of the object to be removed of type AmplitudeReferenceIndex.
      :rtype: Object of type :ref:`AmplitudeReference <api-python-datamodel-amplitudereference>`.

      Returns the AmplitudeReference at given index. The indexes of all child objects
      are compared by value which makes this function slower than the direct
      integer index look-up.

   .. py:method:: eventParameters()

      :rtype: EventParameters

      Returns the parent EventParameters if available. Returns None
      if the parent is not a EventParameters. This is a convenience wrapper
      for parent().

   .. py:method:: assign(other)

      This method implements the :ref:`Object <api-python-datamodel-object>` interface.

   .. py:method:: attachTo(parent)

      This method implements the :ref:`Object <api-python-datamodel-object>` interface.

   .. py:method:: detachFrom(parent)

      This method implements the :ref:`Object <api-python-datamodel-object>` interface.

   .. py:method:: detach()

      This method implements the :ref:`Object <api-python-datamodel-object>` interface.

   .. py:method:: clone()

      :rtype: A cloned Reading.

      Returns a new instance that is a clone of the current instance. Child
      objects are being ignored.


   .. py:method:: updateChild(ref)

      :param ref: A child object derived from class Object.
      :rtype: A Boolean flag indicating success with True, False otherwise

      This method takes the passed reference object and searches for a child
      with the same publicID (if derived from :ref:`PublicObject <api-python-datamodel-publicobject>`)
      or the same index (if derived from :ref:`Object <api-python-datamodel-object>`).
      The the child was found the reference objects attributes are copied to
      the child object. Children of child are being ignored during this operation.
      This method implements the :ref:`PublicObject <api-python-datamodel-publicobject>` interface.


   .. py:method:: accept(visitor)

      :param visitor: A visitor.

      This method implements the :ref:`PublicObject <api-python-datamodel-publicobject>` interface.

.. _api-python-datamodel-realarray:

RealArray
............................................................

.. py:class:: RealArray

   Inherits :ref:`Object <api-python-datamodel-object>`.


   **Attributes**:

   - ``content`` -- float (optional)

   **Used by**:

   - :func:`RealPDF1D.variable`
   - :func:`RealPDF1D.probability`
   - :func:`ResponseFAP.tuples`
   - :func:`ResponseFIR.coefficients`
   - :func:`ResponseIIR.numerators`
   - :func:`ResponseIIR.denominators`
   - :func:`ResponsePolynomial.coefficients`
   - :func:`TimePDF1D.probability`

   **Methods**:

   .. py:staticmethod:: Cast(obj)

      :param obj: The object to be casted.
      :rtype: An object of type RealArray if the cast was successful,
              None otherwise.

      Cast an arbitrary object to RealArray if the internal wrapped
      representation is an RealArray object. The cast is important if
      instances of type :ref:`Object <api-python-datamodel-object>`
      are passed to methods which need access to the real type.



   .. py:method:: equal(other)

      :param other: Another object of type RealArray to compare this
                    instance to
      :rtype: A Boolean value indicating True if both objects are equal or
              False otherwise.

      Compares two objects without its child objects. Both objects are compared
      by value.

   .. py:method:: setContent(content)

      :param content: float

   .. py:method:: content()

      :rtype: float

      .. note::

         As this attribute is optional, this method throws a ValueError if
         the value of the attribute is not set.

.. _api-python-datamodel-realpdf1d:

RealPDF1D
............................................................

.. py:class:: RealPDF1D

   Inherits :ref:`Object <api-python-datamodel-object>`.

   A probability density function description. It can be used in three
   different modes:
   
   1\) \"raw samples mode\"
   
   variable is a list of M values, no probability. The values represent
   samples, no binning\/probabilities made.
   
   2\) \"implicitly binned PDF\"
   
   variable and probabilty arrays have length N. variable values to be
   interpreted as \"bin centers\" \(or representative values\),
   no bin edges given.
   
   3\) \"explicitly binned PDF\"
   
   variable has length N+1, probability has length N. variable values
   describe bin edges \(upper bin edge is lower edge of next bin\).

   **Attributes**:

   - ``variable`` -- :ref:`RealArray <api-python-datamodel-realarray>`
   - ``probability`` -- :ref:`RealArray <api-python-datamodel-realarray>`

   **Used by**:

   - :func:`RealQuantity.pdf`

   **Methods**:

   .. py:staticmethod:: Cast(obj)

      :param obj: The object to be casted.
      :rtype: An object of type RealPDF1D if the cast was successful,
              None otherwise.

      Cast an arbitrary object to RealPDF1D if the internal wrapped
      representation is an RealPDF1D object. The cast is important if
      instances of type :ref:`Object <api-python-datamodel-object>`
      are passed to methods which need access to the real type.



   .. py:method:: equal(other)

      :param other: Another object of type RealPDF1D to compare this
                    instance to
      :rtype: A Boolean value indicating True if both objects are equal or
              False otherwise.

      Compares two objects without its child objects. Both objects are compared
      by value.

   .. py:method:: setVariable(variable)

      :param variable: :ref:`RealArray <api-python-datamodel-realarray>`

      List of values

   .. py:method:: variable()

      :rtype: :ref:`RealArray <api-python-datamodel-realarray>`

   .. py:method:: setProbability(probability)

      :param probability: :ref:`RealArray <api-python-datamodel-realarray>`

      List of probabilities

   .. py:method:: probability()

      :rtype: :ref:`RealArray <api-python-datamodel-realarray>`

.. _api-python-datamodel-realquantity:

RealQuantity
............................................................

.. py:class:: RealQuantity

   Inherits :ref:`Object <api-python-datamodel-object>`.

   Physical quantities expressed as floating point numbers are represented by their
   measured or computed values and optional values for symmetric or upper
   and lower uncertainties. The interpretation of these uncertainties is
   not defined in the standard. They can contain statistically well\-defined
   error measures, but the mechanism can also be used to simply describe a
   possible value range. If the confidence level of the uncertainty is known,
   it can be listed in the optional attribute confidenceLevel.
   Note that uncertainty, upperUncertainty, and lowerUncertainty are given as
   absolute values of the deviation
   from the main value.

   **Attributes**:

   - ``value`` -- float
   - ``uncertainty`` -- float (optional)
   - ``lowerUncertainty`` -- float (optional)
   - ``upperUncertainty`` -- float (optional)
   - ``confidenceLevel`` -- float (optional)
   - ``pdf`` -- :ref:`RealPDF1D <api-python-datamodel-realpdf1d>` (optional)

   **Used by**:

   - :func:`Amplitude.amplitude`
   - :func:`Amplitude.period`
   - :func:`Axis.azimuth`
   - :func:`Axis.plunge`
   - :func:`Axis.length`
   - :func:`CompositeTime.second`
   - :func:`Magnitude.magnitude`
   - :func:`MomentTensor.scalarMoment`
   - :func:`NodalPlane.strike`
   - :func:`NodalPlane.dip`
   - :func:`NodalPlane.rake`
   - :func:`Origin.latitude`
   - :func:`Origin.longitude`
   - :func:`Origin.depth`
   - :func:`Pick.horizontalSlowness`
   - :func:`Pick.backazimuth`
   - :func:`StationMagnitude.magnitude`
   - :func:`Tensor.Mrr`
   - :func:`Tensor.Mtt`
   - :func:`Tensor.Mpp`
   - :func:`Tensor.Mrt`
   - :func:`Tensor.Mrp`
   - :func:`Tensor.Mtp`

   **Methods**:

   .. py:staticmethod:: Cast(obj)

      :param obj: The object to be casted.
      :rtype: An object of type RealQuantity if the cast was successful,
              None otherwise.

      Cast an arbitrary object to RealQuantity if the internal wrapped
      representation is an RealQuantity object. The cast is important if
      instances of type :ref:`Object <api-python-datamodel-object>`
      are passed to methods which need access to the real type.



   .. py:method:: equal(other)

      :param other: Another object of type RealQuantity to compare this
                    instance to
      :rtype: A Boolean value indicating True if both objects are equal or
              False otherwise.

      Compares two objects without its child objects. Both objects are compared
      by value.

   .. py:method:: setValue(value)

      :param value: float

      Value of the quantity. The unit is implicitly defined and depends on the
      context.

   .. py:method:: value()

      :rtype: float

   .. py:method:: setUncertainty(uncertainty)

      :param uncertainty: float

      Uncertainty as the absolute value of symmetric deviation from the main value.

   .. py:method:: uncertainty()

      :rtype: float

      .. note::

         As this attribute is optional, this method throws a ValueError if
         the value of the attribute is not set.

   .. py:method:: setLowerUncertainty(lowerUncertainty)

      :param lowerUncertainty: float

      Uncertainty as the absolute value of deviation from the main value towards
      smaller values.

   .. py:method:: lowerUncertainty()

      :rtype: float

      .. note::

         As this attribute is optional, this method throws a ValueError if
         the value of the attribute is not set.

   .. py:method:: setUpperUncertainty(upperUncertainty)

      :param upperUncertainty: float

      Uncertainty as the absolute value of deviation from the main value towards
      larger values.

   .. py:method:: upperUncertainty()

      :rtype: float

      .. note::

         As this attribute is optional, this method throws a ValueError if
         the value of the attribute is not set.

   .. py:method:: setConfidenceLevel(confidenceLevel)

      :param confidenceLevel: float

      Confidence level of the uncertainty, given in percent.

   .. py:method:: confidenceLevel()

      :rtype: float

      .. note::

         As this attribute is optional, this method throws a ValueError if
         the value of the attribute is not set.

   .. py:method:: setPdf(pdf)

      :param pdf: :ref:`RealPDF1D <api-python-datamodel-realpdf1d>`

      Probability density function of the quantity.

   .. py:method:: pdf()

      :rtype: :ref:`RealPDF1D <api-python-datamodel-realpdf1d>`

      .. note::

         As this attribute is optional, this method throws a ValueError if
         the value of the attribute is not set.

.. _api-python-datamodel-responsefap:

ResponseFAP
............................................................

.. py:class:: ResponseFAP

   Inherits :ref:`PublicObject <api-python-datamodel-publicobject>`.

   This type describes a sensor response composed of frequency\/amplitude\/phase
   angle tuples. According to the SEED manual \(blockette 55\) this description
   alone is not an acceptable response description.

   **Parents**:

   - ``inventory`` -- :ref:`Inventory <api-python-datamodel-inventory>`

   **Attributes**:

   - ``publicID``: string
   - ``name`` -- string
   - ``gain`` -- float (optional)
   - ``gainFrequency`` -- float (optional)
   - ``numberOfTuples`` -- int (optional)
   - ``tuples`` -- :ref:`RealArray <api-python-datamodel-realarray>` (optional)
   - ``remark`` -- :ref:`Blob <api-python-datamodel-blob>` (optional)

   **Methods**:

   .. py:staticmethod:: Cast(obj)

      :param obj: The object to be casted.
      :rtype: An object of type ResponseFAP if the cast was successful,
              None otherwise.

      Cast an arbitrary object to ResponseFAP if the internal wrapped
      representation is an ResponseFAP object. The cast is important if
      instances of type :ref:`Object <api-python-datamodel-object>`
      are passed to methods which need access to the real type.



   .. py:staticmethod:: Create()

      :rtype: A new object of type ResponseFAP.

      Creates and registers (if enabled) a ResponseFAP instance. The
      publicID is auto-generated.

   .. py:staticmethod:: Create(publicID)

      :rtype: A new object of type ResponseFAP.

      Creates and registers (if enabled) a ResponseFAP instance with
      passed publicID.

   .. py:method:: equal(other)

      :param other: Another object of type ResponseFAP to compare this
                    instance to
      :rtype: A Boolean value indicating True if both objects are equal or
              False otherwise.

      Compares two objects without its child objects. Both objects are compared
      by value.

   .. py:method:: index()

      :rtype: The object's index of type ResponseFAPIndex.

       Returns the objects index which is also used for the database as unique
       constraint.

   .. py:method:: equalIndex(lhs)

      :param lhs: :ref:`ResponseFAP <api-python-datamodel-responsefap>`
      :rtype: A Boolean value indicating True if both indexes are equal or
              False otherwise.

   .. py:method:: setName(name)

      :param name: string

      Unique response name

   .. py:method:: name()

      :rtype: string

   .. py:method:: setGain(gain)

      :param gain: float

      Gain of response \(48.05\/58.04\)

   .. py:method:: gain()

      :rtype: float

      .. note::

         As this attribute is optional, this method throws a ValueError if
         the value of the attribute is not set.

   .. py:method:: setGainFrequency(gainFrequency)

      :param gainFrequency: float

      Gain frequency \(48.06\/58.05\)

   .. py:method:: gainFrequency()

      :rtype: float

      .. note::

         As this attribute is optional, this method throws a ValueError if
         the value of the attribute is not set.

   .. py:method:: setNumberOfTuples(numberOfTuples)

      :param numberOfTuples: int

      The number of fap tuples in the response

   .. py:method:: numberOfTuples()

      :rtype: int

      .. note::

         As this attribute is optional, this method throws a ValueError if
         the value of the attribute is not set.

   .. py:method:: setTuples(tuples)

      :param tuples: :ref:`RealArray <api-python-datamodel-realarray>`

      The tuples organized as linear array. The array size must be numberOfTuples
      * 3. Each tuple consists of frequency \(in Hz\), amplitude and phase angle
      \(in degree\).

   .. py:method:: tuples()

      :rtype: :ref:`RealArray <api-python-datamodel-realarray>`

      .. note::

         As this attribute is optional, this method throws a ValueError if
         the value of the attribute is not set.

   .. py:method:: setRemark(remark)

      :param remark: :ref:`Blob <api-python-datamodel-blob>`

      Optional remark

   .. py:method:: remark()

      :rtype: :ref:`Blob <api-python-datamodel-blob>`

      .. note::

         As this attribute is optional, this method throws a ValueError if
         the value of the attribute is not set.

   .. py:method:: inventory()

      :rtype: Inventory

      Returns the parent Inventory if available. Returns None
      if the parent is not a Inventory. This is a convenience wrapper
      for parent().

   .. py:method:: assign(other)

      This method implements the :ref:`Object <api-python-datamodel-object>` interface.

   .. py:method:: attachTo(parent)

      This method implements the :ref:`Object <api-python-datamodel-object>` interface.

   .. py:method:: detachFrom(parent)

      This method implements the :ref:`Object <api-python-datamodel-object>` interface.

   .. py:method:: detach()

      This method implements the :ref:`Object <api-python-datamodel-object>` interface.

   .. py:method:: clone()

      :rtype: A cloned ResponseFAP.

      Returns a new instance that is a clone of the current instance. Child
      objects are being ignored.


   .. py:method:: updateChild(ref)

      :param ref: A child object derived from class Object.
      :rtype: A Boolean flag indicating success with True, False otherwise

      This method takes the passed reference object and searches for a child
      with the same publicID (if derived from :ref:`PublicObject <api-python-datamodel-publicobject>`)
      or the same index (if derived from :ref:`Object <api-python-datamodel-object>`).
      The the child was found the reference objects attributes are copied to
      the child object. Children of child are being ignored during this operation.
      This method implements the :ref:`PublicObject <api-python-datamodel-publicobject>` interface.


   .. py:method:: accept(visitor)

      :param visitor: A visitor.

      This method implements the :ref:`PublicObject <api-python-datamodel-publicobject>` interface.

.. _api-python-datamodel-responsefir:

ResponseFIR
............................................................

.. py:class:: ResponseFIR

   Inherits :ref:`PublicObject <api-python-datamodel-publicobject>`.

   This type describes a finite impulse response filter

   **Parents**:

   - ``inventory`` -- :ref:`Inventory <api-python-datamodel-inventory>`

   **Attributes**:

   - ``publicID``: string
   - ``name`` -- string
   - ``gain`` -- float (optional)
   - ``gainFrequency`` -- float (optional)
   - ``decimationFactor`` -- int (optional)
   - ``delay`` -- float (optional)
   - ``correction`` -- float (optional)
   - ``numberOfCoefficients`` -- int (optional)
   - ``symmetry`` -- string
   - ``coefficients`` -- :ref:`RealArray <api-python-datamodel-realarray>` (optional)
   - ``remark`` -- :ref:`Blob <api-python-datamodel-blob>` (optional)

   **Methods**:

   .. py:staticmethod:: Cast(obj)

      :param obj: The object to be casted.
      :rtype: An object of type ResponseFIR if the cast was successful,
              None otherwise.

      Cast an arbitrary object to ResponseFIR if the internal wrapped
      representation is an ResponseFIR object. The cast is important if
      instances of type :ref:`Object <api-python-datamodel-object>`
      are passed to methods which need access to the real type.



   .. py:staticmethod:: Create()

      :rtype: A new object of type ResponseFIR.

      Creates and registers (if enabled) a ResponseFIR instance. The
      publicID is auto-generated.

   .. py:staticmethod:: Create(publicID)

      :rtype: A new object of type ResponseFIR.

      Creates and registers (if enabled) a ResponseFIR instance with
      passed publicID.

   .. py:method:: equal(other)

      :param other: Another object of type ResponseFIR to compare this
                    instance to
      :rtype: A Boolean value indicating True if both objects are equal or
              False otherwise.

      Compares two objects without its child objects. Both objects are compared
      by value.

   .. py:method:: index()

      :rtype: The object's index of type ResponseFIRIndex.

       Returns the objects index which is also used for the database as unique
       constraint.

   .. py:method:: equalIndex(lhs)

      :param lhs: :ref:`ResponseFIR <api-python-datamodel-responsefir>`
      :rtype: A Boolean value indicating True if both indexes are equal or
              False otherwise.

   .. py:method:: setName(name)

      :param name: string

      Unique response name

   .. py:method:: name()

      :rtype: string

   .. py:method:: setGain(gain)

      :param gain: float

      Gain of response \(48.05\/58.04\)

   .. py:method:: gain()

      :rtype: float

      .. note::

         As this attribute is optional, this method throws a ValueError if
         the value of the attribute is not set.

   .. py:method:: setGainFrequency(gainFrequency)

      :param gainFrequency: float

      Gain frequency \(48.06\/58.05\)

   .. py:method:: gainFrequency()

      :rtype: float

      .. note::

         As this attribute is optional, this method throws a ValueError if
         the value of the attribute is not set.

   .. py:method:: setDecimationFactor(decimationFactor)

      :param decimationFactor: int

      Decimation factor \(47.06\/57.05\)

   .. py:method:: decimationFactor()

      :rtype: int

      .. note::

         As this attribute is optional, this method throws a ValueError if
         the value of the attribute is not set.

   .. py:method:: setDelay(delay)

      :param delay: float

      Estimated delay \(47.08\/57.07\)

   .. py:method:: delay()

      :rtype: float

      .. note::

         As this attribute is optional, this method throws a ValueError if
         the value of the attribute is not set.

   .. py:method:: setCorrection(correction)

      :param correction: float

      Applied correction \(47.09\/57.08\)

   .. py:method:: correction()

      :rtype: float

      .. note::

         As this attribute is optional, this method throws a ValueError if
         the value of the attribute is not set.

   .. py:method:: setNumberOfCoefficients(numberOfCoefficients)

      :param numberOfCoefficients: int

      Number of coefficients \(41.08\/61.08\)

   .. py:method:: numberOfCoefficients()

      :rtype: int

      .. note::

         As this attribute is optional, this method throws a ValueError if
         the value of the attribute is not set.

   .. py:method:: setSymmetry(symmetry)

      :param symmetry: string

      Symmetry code \(41.05\/61.05\)

   .. py:method:: symmetry()

      :rtype: string

   .. py:method:: setCoefficients(coefficients)

      :param coefficients: :ref:`RealArray <api-python-datamodel-realarray>`

      Coefficients normalized to gain\=1.0 \(41.09\/61.09\)

   .. py:method:: coefficients()

      :rtype: :ref:`RealArray <api-python-datamodel-realarray>`

      .. note::

         As this attribute is optional, this method throws a ValueError if
         the value of the attribute is not set.

   .. py:method:: setRemark(remark)

      :param remark: :ref:`Blob <api-python-datamodel-blob>`

   .. py:method:: remark()

      :rtype: :ref:`Blob <api-python-datamodel-blob>`

      .. note::

         As this attribute is optional, this method throws a ValueError if
         the value of the attribute is not set.

   .. py:method:: inventory()

      :rtype: Inventory

      Returns the parent Inventory if available. Returns None
      if the parent is not a Inventory. This is a convenience wrapper
      for parent().

   .. py:method:: assign(other)

      This method implements the :ref:`Object <api-python-datamodel-object>` interface.

   .. py:method:: attachTo(parent)

      This method implements the :ref:`Object <api-python-datamodel-object>` interface.

   .. py:method:: detachFrom(parent)

      This method implements the :ref:`Object <api-python-datamodel-object>` interface.

   .. py:method:: detach()

      This method implements the :ref:`Object <api-python-datamodel-object>` interface.

   .. py:method:: clone()

      :rtype: A cloned ResponseFIR.

      Returns a new instance that is a clone of the current instance. Child
      objects are being ignored.


   .. py:method:: updateChild(ref)

      :param ref: A child object derived from class Object.
      :rtype: A Boolean flag indicating success with True, False otherwise

      This method takes the passed reference object and searches for a child
      with the same publicID (if derived from :ref:`PublicObject <api-python-datamodel-publicobject>`)
      or the same index (if derived from :ref:`Object <api-python-datamodel-object>`).
      The the child was found the reference objects attributes are copied to
      the child object. Children of child are being ignored during this operation.
      This method implements the :ref:`PublicObject <api-python-datamodel-publicobject>` interface.


   .. py:method:: accept(visitor)

      :param visitor: A visitor.

      This method implements the :ref:`PublicObject <api-python-datamodel-publicobject>` interface.

.. _api-python-datamodel-responseiir:

ResponseIIR
............................................................

.. py:class:: ResponseIIR

   Inherits :ref:`PublicObject <api-python-datamodel-publicobject>`.

   This type describes a infinite impulse response filter

   **Parents**:

   - ``inventory`` -- :ref:`Inventory <api-python-datamodel-inventory>`

   **Attributes**:

   - ``publicID``: string
   - ``name`` -- string
   - ``type`` -- string
   - ``gain`` -- float (optional)
   - ``gainFrequency`` -- float (optional)
   - ``decimationFactor`` -- int (optional)
   - ``delay`` -- float (optional)
   - ``correction`` -- float (optional)
   - ``numberOfNumerators`` -- int (optional)
   - ``numberOfDenominators`` -- int (optional)
   - ``numerators`` -- :ref:`RealArray <api-python-datamodel-realarray>` (optional)
   - ``denominators`` -- :ref:`RealArray <api-python-datamodel-realarray>` (optional)
   - ``remark`` -- :ref:`Blob <api-python-datamodel-blob>` (optional)

   **Methods**:

   .. py:staticmethod:: Cast(obj)

      :param obj: The object to be casted.
      :rtype: An object of type ResponseIIR if the cast was successful,
              None otherwise.

      Cast an arbitrary object to ResponseIIR if the internal wrapped
      representation is an ResponseIIR object. The cast is important if
      instances of type :ref:`Object <api-python-datamodel-object>`
      are passed to methods which need access to the real type.



   .. py:staticmethod:: Create()

      :rtype: A new object of type ResponseIIR.

      Creates and registers (if enabled) a ResponseIIR instance. The
      publicID is auto-generated.

   .. py:staticmethod:: Create(publicID)

      :rtype: A new object of type ResponseIIR.

      Creates and registers (if enabled) a ResponseIIR instance with
      passed publicID.

   .. py:method:: equal(other)

      :param other: Another object of type ResponseIIR to compare this
                    instance to
      :rtype: A Boolean value indicating True if both objects are equal or
              False otherwise.

      Compares two objects without its child objects. Both objects are compared
      by value.

   .. py:method:: index()

      :rtype: The object's index of type ResponseIIRIndex.

       Returns the objects index which is also used for the database as unique
       constraint.

   .. py:method:: equalIndex(lhs)

      :param lhs: :ref:`ResponseIIR <api-python-datamodel-responseiir>`
      :rtype: A Boolean value indicating True if both indexes are equal or
              False otherwise.

   .. py:method:: setName(name)

      :param name: string

      Unique response name

   .. py:method:: name()

      :rtype: string

   .. py:method:: setType(type)

      :param type: string

      Response type \(43.05\/53.03\/54.03\): A \- Laplace transform analog
      response in rad\/sec, B \- Analog response in Hz, C \- Composite \(currently
      undefined\), D \- Digital \(Z \- transform\)

   .. py:method:: type()

      :rtype: string

   .. py:method:: setGain(gain)

      :param gain: float

      Gain of response \(48.05\/58.04\)

   .. py:method:: gain()

      :rtype: float

      .. note::

         As this attribute is optional, this method throws a ValueError if
         the value of the attribute is not set.

   .. py:method:: setGainFrequency(gainFrequency)

      :param gainFrequency: float

      Gain frequency \(48.06\/58.05\)

   .. py:method:: gainFrequency()

      :rtype: float

      .. note::

         As this attribute is optional, this method throws a ValueError if
         the value of the attribute is not set.

   .. py:method:: setDecimationFactor(decimationFactor)

      :param decimationFactor: int

      Decimation factor \(47.06\/57.05\)

   .. py:method:: decimationFactor()

      :rtype: int

      .. note::

         As this attribute is optional, this method throws a ValueError if
         the value of the attribute is not set.

   .. py:method:: setDelay(delay)

      :param delay: float

      Estimated delay \(47.08\/57.07\)

   .. py:method:: delay()

      :rtype: float

      .. note::

         As this attribute is optional, this method throws a ValueError if
         the value of the attribute is not set.

   .. py:method:: setCorrection(correction)

      :param correction: float

      Applied correction \(47.09\/57.08\)

   .. py:method:: correction()

      :rtype: float

      .. note::

         As this attribute is optional, this method throws a ValueError if
         the value of the attribute is not set.

   .. py:method:: setNumberOfNumerators(numberOfNumerators)

      :param numberOfNumerators: int

      Number of numerators \(54.07\)

   .. py:method:: numberOfNumerators()

      :rtype: int

      .. note::

         As this attribute is optional, this method throws a ValueError if
         the value of the attribute is not set.

   .. py:method:: setNumberOfDenominators(numberOfDenominators)

      :param numberOfDenominators: int

      Number of denominators \(54.10\)

   .. py:method:: numberOfDenominators()

      :rtype: int

      .. note::

         As this attribute is optional, this method throws a ValueError if
         the value of the attribute is not set.

   .. py:method:: setNumerators(numerators)

      :param numerators: :ref:`RealArray <api-python-datamodel-realarray>`

      Numerators \(54.08\-09\)

   .. py:method:: numerators()

      :rtype: :ref:`RealArray <api-python-datamodel-realarray>`

      .. note::

         As this attribute is optional, this method throws a ValueError if
         the value of the attribute is not set.

   .. py:method:: setDenominators(denominators)

      :param denominators: :ref:`RealArray <api-python-datamodel-realarray>`

      Denominators \(54.11\-12\)

   .. py:method:: denominators()

      :rtype: :ref:`RealArray <api-python-datamodel-realarray>`

      .. note::

         As this attribute is optional, this method throws a ValueError if
         the value of the attribute is not set.

   .. py:method:: setRemark(remark)

      :param remark: :ref:`Blob <api-python-datamodel-blob>`

   .. py:method:: remark()

      :rtype: :ref:`Blob <api-python-datamodel-blob>`

      .. note::

         As this attribute is optional, this method throws a ValueError if
         the value of the attribute is not set.

   .. py:method:: inventory()

      :rtype: Inventory

      Returns the parent Inventory if available. Returns None
      if the parent is not a Inventory. This is a convenience wrapper
      for parent().

   .. py:method:: assign(other)

      This method implements the :ref:`Object <api-python-datamodel-object>` interface.

   .. py:method:: attachTo(parent)

      This method implements the :ref:`Object <api-python-datamodel-object>` interface.

   .. py:method:: detachFrom(parent)

      This method implements the :ref:`Object <api-python-datamodel-object>` interface.

   .. py:method:: detach()

      This method implements the :ref:`Object <api-python-datamodel-object>` interface.

   .. py:method:: clone()

      :rtype: A cloned ResponseIIR.

      Returns a new instance that is a clone of the current instance. Child
      objects are being ignored.


   .. py:method:: updateChild(ref)

      :param ref: A child object derived from class Object.
      :rtype: A Boolean flag indicating success with True, False otherwise

      This method takes the passed reference object and searches for a child
      with the same publicID (if derived from :ref:`PublicObject <api-python-datamodel-publicobject>`)
      or the same index (if derived from :ref:`Object <api-python-datamodel-object>`).
      The the child was found the reference objects attributes are copied to
      the child object. Children of child are being ignored during this operation.
      This method implements the :ref:`PublicObject <api-python-datamodel-publicobject>` interface.


   .. py:method:: accept(visitor)

      :param visitor: A visitor.

      This method implements the :ref:`PublicObject <api-python-datamodel-publicobject>` interface.

.. _api-python-datamodel-responsepaz:

ResponsePAZ
............................................................

.. py:class:: ResponsePAZ

   Inherits :ref:`PublicObject <api-python-datamodel-publicobject>`.

   This type describes a sensor response using poles and zeros

   **Parents**:

   - ``inventory`` -- :ref:`Inventory <api-python-datamodel-inventory>`

   **Attributes**:

   - ``publicID``: string
   - ``name`` -- string
   - ``type`` -- string
   - ``gain`` -- float (optional)
   - ``gainFrequency`` -- float (optional)
   - ``normalizationFactor`` -- float (optional)
   - ``normalizationFrequency`` -- float (optional)
   - ``numberOfZeros`` -- int (optional)
   - ``numberOfPoles`` -- int (optional)
   - ``zeros`` -- :ref:`ComplexArray <api-python-datamodel-complexarray>` (optional)
   - ``poles`` -- :ref:`ComplexArray <api-python-datamodel-complexarray>` (optional)
   - ``remark`` -- :ref:`Blob <api-python-datamodel-blob>` (optional)
   - ``decimationFactor`` -- int (optional)
   - ``delay`` -- float (optional)
   - ``correction`` -- float (optional)

   **Methods**:

   .. py:staticmethod:: Cast(obj)

      :param obj: The object to be casted.
      :rtype: An object of type ResponsePAZ if the cast was successful,
              None otherwise.

      Cast an arbitrary object to ResponsePAZ if the internal wrapped
      representation is an ResponsePAZ object. The cast is important if
      instances of type :ref:`Object <api-python-datamodel-object>`
      are passed to methods which need access to the real type.



   .. py:staticmethod:: Create()

      :rtype: A new object of type ResponsePAZ.

      Creates and registers (if enabled) a ResponsePAZ instance. The
      publicID is auto-generated.

   .. py:staticmethod:: Create(publicID)

      :rtype: A new object of type ResponsePAZ.

      Creates and registers (if enabled) a ResponsePAZ instance with
      passed publicID.

   .. py:method:: equal(other)

      :param other: Another object of type ResponsePAZ to compare this
                    instance to
      :rtype: A Boolean value indicating True if both objects are equal or
              False otherwise.

      Compares two objects without its child objects. Both objects are compared
      by value.

   .. py:method:: index()

      :rtype: The object's index of type ResponsePAZIndex.

       Returns the objects index which is also used for the database as unique
       constraint.

   .. py:method:: equalIndex(lhs)

      :param lhs: :ref:`ResponsePAZ <api-python-datamodel-responsepaz>`
      :rtype: A Boolean value indicating True if both indexes are equal or
              False otherwise.

   .. py:method:: setName(name)

      :param name: string

      Unique response name

   .. py:method:: name()

      :rtype: string

   .. py:method:: setType(type)

      :param type: string

      Response type \(43.05\/53.03\): A \- Laplace transform analog response in
      rad\/sec, B \- Analog response in Hz, C \- Composite \(currently
      undefined\), D \- Digital \(Z \- transform\)

   .. py:method:: type()

      :rtype: string

   .. py:method:: setGain(gain)

      :param gain: float

      Gain of response \(48.05\/58.04\)

   .. py:method:: gain()

      :rtype: float

      .. note::

         As this attribute is optional, this method throws a ValueError if
         the value of the attribute is not set.

   .. py:method:: setGainFrequency(gainFrequency)

      :param gainFrequency: float

      Gain frequency \(48.06\/58.05\)

   .. py:method:: gainFrequency()

      :rtype: float

      .. note::

         As this attribute is optional, this method throws a ValueError if
         the value of the attribute is not set.

   .. py:method:: setNormalizationFactor(normalizationFactor)

      :param normalizationFactor: float

      A0 normalization factor \(43.08\/53.07\)

   .. py:method:: normalizationFactor()

      :rtype: float

      .. note::

         As this attribute is optional, this method throws a ValueError if
         the value of the attribute is not set.

   .. py:method:: setNormalizationFrequency(normalizationFrequency)

      :param normalizationFrequency: float

      Normalization frequency \(43.09\/53.08\)

   .. py:method:: normalizationFrequency()

      :rtype: float

      .. note::

         As this attribute is optional, this method throws a ValueError if
         the value of the attribute is not set.

   .. py:method:: setNumberOfZeros(numberOfZeros)

      :param numberOfZeros: int

      Number of zeros \(43.10\/53.09\)

   .. py:method:: numberOfZeros()

      :rtype: int

      .. note::

         As this attribute is optional, this method throws a ValueError if
         the value of the attribute is not set.

   .. py:method:: setNumberOfPoles(numberOfPoles)

      :param numberOfPoles: int

      Number of poles \(43.15\/53.14\)

   .. py:method:: numberOfPoles()

      :rtype: int

      .. note::

         As this attribute is optional, this method throws a ValueError if
         the value of the attribute is not set.

   .. py:method:: setZeros(zeros)

      :param zeros: :ref:`ComplexArray <api-python-datamodel-complexarray>`

      Zeros \(43.16\-19\/53.10\-13\)

   .. py:method:: zeros()

      :rtype: :ref:`ComplexArray <api-python-datamodel-complexarray>`

      .. note::

         As this attribute is optional, this method throws a ValueError if
         the value of the attribute is not set.

   .. py:method:: setPoles(poles)

      :param poles: :ref:`ComplexArray <api-python-datamodel-complexarray>`

      Poles \(43.11\-14\/53.15\-18\)

   .. py:method:: poles()

      :rtype: :ref:`ComplexArray <api-python-datamodel-complexarray>`

      .. note::

         As this attribute is optional, this method throws a ValueError if
         the value of the attribute is not set.

   .. py:method:: setRemark(remark)

      :param remark: :ref:`Blob <api-python-datamodel-blob>`

   .. py:method:: remark()

      :rtype: :ref:`Blob <api-python-datamodel-blob>`

      .. note::

         As this attribute is optional, this method throws a ValueError if
         the value of the attribute is not set.

   .. py:method:: setDecimationFactor(decimationFactor)

      :param decimationFactor: int

      Decimation factor \(47.06\/57.05\)

   .. py:method:: decimationFactor()

      :rtype: int

      .. note::

         As this attribute is optional, this method throws a ValueError if
         the value of the attribute is not set.

   .. py:method:: setDelay(delay)

      :param delay: float

      Estimated delay \(47.08\/57.07\)

   .. py:method:: delay()

      :rtype: float

      .. note::

         As this attribute is optional, this method throws a ValueError if
         the value of the attribute is not set.

   .. py:method:: setCorrection(correction)

      :param correction: float

      Applied correction \(47.09\/57.08\)

   .. py:method:: correction()

      :rtype: float

      .. note::

         As this attribute is optional, this method throws a ValueError if
         the value of the attribute is not set.

   .. py:method:: inventory()

      :rtype: Inventory

      Returns the parent Inventory if available. Returns None
      if the parent is not a Inventory. This is a convenience wrapper
      for parent().

   .. py:method:: assign(other)

      This method implements the :ref:`Object <api-python-datamodel-object>` interface.

   .. py:method:: attachTo(parent)

      This method implements the :ref:`Object <api-python-datamodel-object>` interface.

   .. py:method:: detachFrom(parent)

      This method implements the :ref:`Object <api-python-datamodel-object>` interface.

   .. py:method:: detach()

      This method implements the :ref:`Object <api-python-datamodel-object>` interface.

   .. py:method:: clone()

      :rtype: A cloned ResponsePAZ.

      Returns a new instance that is a clone of the current instance. Child
      objects are being ignored.


   .. py:method:: updateChild(ref)

      :param ref: A child object derived from class Object.
      :rtype: A Boolean flag indicating success with True, False otherwise

      This method takes the passed reference object and searches for a child
      with the same publicID (if derived from :ref:`PublicObject <api-python-datamodel-publicobject>`)
      or the same index (if derived from :ref:`Object <api-python-datamodel-object>`).
      The the child was found the reference objects attributes are copied to
      the child object. Children of child are being ignored during this operation.
      This method implements the :ref:`PublicObject <api-python-datamodel-publicobject>` interface.


   .. py:method:: accept(visitor)

      :param visitor: A visitor.

      This method implements the :ref:`PublicObject <api-python-datamodel-publicobject>` interface.

.. _api-python-datamodel-responsepolynomial:

ResponsePolynomial
............................................................

.. py:class:: ResponsePolynomial

   Inherits :ref:`PublicObject <api-python-datamodel-publicobject>`.

   This type describes a sensor response using a polynomial

   **Parents**:

   - ``inventory`` -- :ref:`Inventory <api-python-datamodel-inventory>`

   **Attributes**:

   - ``publicID``: string
   - ``name`` -- string
   - ``gain`` -- float (optional)
   - ``gainFrequency`` -- float (optional)
   - ``frequencyUnit`` -- string
   - ``approximationType`` -- string
   - ``approximationLowerBound`` -- float (optional)
   - ``approximationUpperBound`` -- float (optional)
   - ``approximationError`` -- float (optional)
   - ``numberOfCoefficients`` -- int (optional)
   - ``coefficients`` -- :ref:`RealArray <api-python-datamodel-realarray>` (optional)
   - ``remark`` -- :ref:`Blob <api-python-datamodel-blob>` (optional)

   **Methods**:

   .. py:staticmethod:: Cast(obj)

      :param obj: The object to be casted.
      :rtype: An object of type ResponsePolynomial if the cast was successful,
              None otherwise.

      Cast an arbitrary object to ResponsePolynomial if the internal wrapped
      representation is an ResponsePolynomial object. The cast is important if
      instances of type :ref:`Object <api-python-datamodel-object>`
      are passed to methods which need access to the real type.



   .. py:staticmethod:: Create()

      :rtype: A new object of type ResponsePolynomial.

      Creates and registers (if enabled) a ResponsePolynomial instance. The
      publicID is auto-generated.

   .. py:staticmethod:: Create(publicID)

      :rtype: A new object of type ResponsePolynomial.

      Creates and registers (if enabled) a ResponsePolynomial instance with
      passed publicID.

   .. py:method:: equal(other)

      :param other: Another object of type ResponsePolynomial to compare this
                    instance to
      :rtype: A Boolean value indicating True if both objects are equal or
              False otherwise.

      Compares two objects without its child objects. Both objects are compared
      by value.

   .. py:method:: index()

      :rtype: The object's index of type ResponsePolynomialIndex.

       Returns the objects index which is also used for the database as unique
       constraint.

   .. py:method:: equalIndex(lhs)

      :param lhs: :ref:`ResponsePolynomial <api-python-datamodel-responsepolynomial>`
      :rtype: A Boolean value indicating True if both indexes are equal or
              False otherwise.

   .. py:method:: setName(name)

      :param name: string

      Unique response name

   .. py:method:: name()

      :rtype: string

   .. py:method:: setGain(gain)

      :param gain: float

      Gain of response \(48.05\/58.04\)

   .. py:method:: gain()

      :rtype: float

      .. note::

         As this attribute is optional, this method throws a ValueError if
         the value of the attribute is not set.

   .. py:method:: setGainFrequency(gainFrequency)

      :param gainFrequency: float

      Gain frequency \(48.06\/58.05\)

   .. py:method:: gainFrequency()

      :rtype: float

      .. note::

         As this attribute is optional, this method throws a ValueError if
         the value of the attribute is not set.

   .. py:method:: setFrequencyUnit(frequencyUnit)

      :param frequencyUnit: string

      A single character describing valid frequency units \(42.09\/62.08\): A \-
      rad\/s, B \- Hz

   .. py:method:: frequencyUnit()

      :rtype: string

   .. py:method:: setApproximationType(approximationType)

      :param approximationType: string

      A single character describing the type of polynomial approximation
      \(42.08\/62.07\): M \- MacLaurin

   .. py:method:: approximationType()

      :rtype: string

   .. py:method:: setApproximationLowerBound(approximationLowerBound)

      :param approximationLowerBound: float

      Lower bound of approximation \(42.12\/62.11\)

   .. py:method:: approximationLowerBound()

      :rtype: float

      .. note::

         As this attribute is optional, this method throws a ValueError if
         the value of the attribute is not set.

   .. py:method:: setApproximationUpperBound(approximationUpperBound)

      :param approximationUpperBound: float

      Upper bound of approximation \(42.13\/62.12\)

   .. py:method:: approximationUpperBound()

      :rtype: float

      .. note::

         As this attribute is optional, this method throws a ValueError if
         the value of the attribute is not set.

   .. py:method:: setApproximationError(approximationError)

      :param approximationError: float

      The maximum absolute error of the polynomial approximation \(42.14\/62.13;
      Put 0.0 if the value is unknown or actually zero\)

   .. py:method:: approximationError()

      :rtype: float

      .. note::

         As this attribute is optional, this method throws a ValueError if
         the value of the attribute is not set.

   .. py:method:: setNumberOfCoefficients(numberOfCoefficients)

      :param numberOfCoefficients: int

      The number of coefficients in the polynomial approximation \(42.15\/62.14;
      one more than the degree of the polynomial

   .. py:method:: numberOfCoefficients()

      :rtype: int

      .. note::

         As this attribute is optional, this method throws a ValueError if
         the value of the attribute is not set.

   .. py:method:: setCoefficients(coefficients)

      :param coefficients: :ref:`RealArray <api-python-datamodel-realarray>`

      The polynomial coefficients, lowest order first \(42.16\/62.15\)

   .. py:method:: coefficients()

      :rtype: :ref:`RealArray <api-python-datamodel-realarray>`

      .. note::

         As this attribute is optional, this method throws a ValueError if
         the value of the attribute is not set.

   .. py:method:: setRemark(remark)

      :param remark: :ref:`Blob <api-python-datamodel-blob>`

   .. py:method:: remark()

      :rtype: :ref:`Blob <api-python-datamodel-blob>`

      .. note::

         As this attribute is optional, this method throws a ValueError if
         the value of the attribute is not set.

   .. py:method:: inventory()

      :rtype: Inventory

      Returns the parent Inventory if available. Returns None
      if the parent is not a Inventory. This is a convenience wrapper
      for parent().

   .. py:method:: assign(other)

      This method implements the :ref:`Object <api-python-datamodel-object>` interface.

   .. py:method:: attachTo(parent)

      This method implements the :ref:`Object <api-python-datamodel-object>` interface.

   .. py:method:: detachFrom(parent)

      This method implements the :ref:`Object <api-python-datamodel-object>` interface.

   .. py:method:: detach()

      This method implements the :ref:`Object <api-python-datamodel-object>` interface.

   .. py:method:: clone()

      :rtype: A cloned ResponsePolynomial.

      Returns a new instance that is a clone of the current instance. Child
      objects are being ignored.


   .. py:method:: updateChild(ref)

      :param ref: A child object derived from class Object.
      :rtype: A Boolean flag indicating success with True, False otherwise

      This method takes the passed reference object and searches for a child
      with the same publicID (if derived from :ref:`PublicObject <api-python-datamodel-publicobject>`)
      or the same index (if derived from :ref:`Object <api-python-datamodel-object>`).
      The the child was found the reference objects attributes are copied to
      the child object. Children of child are being ignored during this operation.
      This method implements the :ref:`PublicObject <api-python-datamodel-publicobject>` interface.


   .. py:method:: accept(visitor)

      :param visitor: A visitor.

      This method implements the :ref:`PublicObject <api-python-datamodel-publicobject>` interface.

.. _api-python-datamodel-route:

Route
............................................................

.. py:class:: Route

   Inherits :ref:`PublicObject <api-python-datamodel-publicobject>`.

   This type describes an ArcLink route \(collection of servers that provide
   specific datastreams\)

   **Parents**:

   - ``routing`` -- :ref:`Routing <api-python-datamodel-routing>`

   **Children**:

   - ``routeArclink`` -- :ref:`RouteArclink <api-python-datamodel-routearclink>`
   - ``routeSeedlink`` -- :ref:`RouteSeedlink <api-python-datamodel-routeseedlink>`

   **Attributes**:

   - ``publicID``: string
   - ``networkCode`` -- string
   - ``stationCode`` -- string
   - ``locationCode`` -- string
   - ``streamCode`` -- string

   **Methods**:

   .. py:staticmethod:: Cast(obj)

      :param obj: The object to be casted.
      :rtype: An object of type Route if the cast was successful,
              None otherwise.

      Cast an arbitrary object to Route if the internal wrapped
      representation is an Route object. The cast is important if
      instances of type :ref:`Object <api-python-datamodel-object>`
      are passed to methods which need access to the real type.



   .. py:staticmethod:: Create()

      :rtype: A new object of type Route.

      Creates and registers (if enabled) a Route instance. The
      publicID is auto-generated.

   .. py:staticmethod:: Create(publicID)

      :rtype: A new object of type Route.

      Creates and registers (if enabled) a Route instance with
      passed publicID.

   .. py:method:: equal(other)

      :param other: Another object of type Route to compare this
                    instance to
      :rtype: A Boolean value indicating True if both objects are equal or
              False otherwise.

      Compares two objects without its child objects. Both objects are compared
      by value.

   .. py:method:: index()

      :rtype: The object's index of type RouteIndex.

       Returns the objects index which is also used for the database as unique
       constraint.

   .. py:method:: equalIndex(lhs)

      :param lhs: :ref:`Route <api-python-datamodel-route>`
      :rtype: A Boolean value indicating True if both indexes are equal or
              False otherwise.

   .. py:method:: setNetworkCode(networkCode)

      :param networkCode: string

      Network code

   .. py:method:: networkCode()

      :rtype: string

   .. py:method:: setStationCode(stationCode)

      :param stationCode: string

      Station code \(empty for any station\)

   .. py:method:: stationCode()

      :rtype: string

   .. py:method:: setLocationCode(locationCode)

      :param locationCode: string

      Location code \(empty for any location\)

   .. py:method:: locationCode()

      :rtype: string

   .. py:method:: setStreamCode(streamCode)

      :param streamCode: string

      Stream \(Channel\) code \(empty for any stream\)

   .. py:method:: streamCode()

      :rtype: string

   .. py:method:: add(routeArclink)

      :param routeArclink: Object of type :ref:`RouteArclink <api-python-datamodel-routearclink>`
      :rtype: A Boolean value indicating success with True, False otherwise.

      Adds a RouteArclink object to Route. The object is not
      copied but managed by this instance. Any change to the passed object
      will also change the child.

   .. py:method:: add(routeSeedlink)

      :param routeSeedlink: Object of type :ref:`RouteSeedlink <api-python-datamodel-routeseedlink>`
      :rtype: A Boolean value indicating success with True, False otherwise.

      Adds a RouteSeedlink object to Route. The object is not
      copied but managed by this instance. Any change to the passed object
      will also change the child.

   .. py:method:: remove(routeArclink)

      :param routeArclink: Object of type :ref:`RouteArclink <api-python-datamodel-routearclink>`
      :rtype: A Boolean value indicating success with True, False otherwise.

      Removes a previously added RouteArclink object from Route.

   .. py:method:: remove(routeSeedlink)

      :param routeSeedlink: Object of type :ref:`RouteSeedlink <api-python-datamodel-routeseedlink>`
      :rtype: A Boolean value indicating success with True, False otherwise.

      Removes a previously added RouteSeedlink object from Route.

   .. py:method:: removeRouteArclink(idx)

      :param idx: An integer index of the object to be removed.
      :rtype: A Boolean value indicating success with True, False otherwise.

   .. py:method:: removeRouteArclink(routeArclinkIndex);

      :param routeArclinkIndex: The index of the object to be removed of type RouteArclinkIndex.
      :rtype: A Boolean value indicating success with True, False otherwise.

   .. py:method:: removeRouteSeedlink(idx)

      :param idx: An integer index of the object to be removed.
      :rtype: A Boolean value indicating success with True, False otherwise.

   .. py:method:: removeRouteSeedlink(routeSeedlinkIndex);

      :param routeSeedlinkIndex: The index of the object to be removed of type RouteSeedlinkIndex.
      :rtype: A Boolean value indicating success with True, False otherwise.

   .. py:method:: routeArclinkCount()

      :rtype: integer value indicating the number of child objects.

      Returns the number of RouteArclink child objects.

   .. py:method:: routeSeedlinkCount()

      :rtype: integer value indicating the number of child objects.

      Returns the number of RouteSeedlink child objects.

   .. py:method:: routeArclink(idx)

      :param idx: An integer index of the object to be returned.
      :rtype: Object of type :ref:`RouteArclink <api-python-datamodel-routearclink>`.

      Returns the RouteArclink at index idx.

   .. py:method:: routeArclink(routeArclinkIndex)

      :param routeArclinkIndex: The index of the object to be removed of type RouteArclinkIndex.
      :rtype: Object of type :ref:`RouteArclink <api-python-datamodel-routearclink>`.

      Returns the RouteArclink at given index. The indexes of all child objects
      are compared by value which makes this function slower than the direct
      integer index look-up.

   .. py:method:: routeSeedlink(idx)

      :param idx: An integer index of the object to be returned.
      :rtype: Object of type :ref:`RouteSeedlink <api-python-datamodel-routeseedlink>`.

      Returns the RouteSeedlink at index idx.

   .. py:method:: routeSeedlink(routeSeedlinkIndex)

      :param routeSeedlinkIndex: The index of the object to be removed of type RouteSeedlinkIndex.
      :rtype: Object of type :ref:`RouteSeedlink <api-python-datamodel-routeseedlink>`.

      Returns the RouteSeedlink at given index. The indexes of all child objects
      are compared by value which makes this function slower than the direct
      integer index look-up.

   .. py:method:: routing()

      :rtype: Routing

      Returns the parent Routing if available. Returns None
      if the parent is not a Routing. This is a convenience wrapper
      for parent().

   .. py:method:: assign(other)

      This method implements the :ref:`Object <api-python-datamodel-object>` interface.

   .. py:method:: attachTo(parent)

      This method implements the :ref:`Object <api-python-datamodel-object>` interface.

   .. py:method:: detachFrom(parent)

      This method implements the :ref:`Object <api-python-datamodel-object>` interface.

   .. py:method:: detach()

      This method implements the :ref:`Object <api-python-datamodel-object>` interface.

   .. py:method:: clone()

      :rtype: A cloned Route.

      Returns a new instance that is a clone of the current instance. Child
      objects are being ignored.


   .. py:method:: updateChild(ref)

      :param ref: A child object derived from class Object.
      :rtype: A Boolean flag indicating success with True, False otherwise

      This method takes the passed reference object and searches for a child
      with the same publicID (if derived from :ref:`PublicObject <api-python-datamodel-publicobject>`)
      or the same index (if derived from :ref:`Object <api-python-datamodel-object>`).
      The the child was found the reference objects attributes are copied to
      the child object. Children of child are being ignored during this operation.
      This method implements the :ref:`PublicObject <api-python-datamodel-publicobject>` interface.


   .. py:method:: accept(visitor)

      :param visitor: A visitor.

      This method implements the :ref:`PublicObject <api-python-datamodel-publicobject>` interface.

.. _api-python-datamodel-routearclink:

RouteArclink
............................................................

.. py:class:: RouteArclink

   Inherits :ref:`Object <api-python-datamodel-object>`.

   This type describes an ArcLink route \(data source\)

   **Parents**:

   - ``route`` -- :ref:`Route <api-python-datamodel-route>`

   **Attributes**:

   - ``address`` -- string
   - ``start`` -- seiscomp.core.Time
   - ``end`` -- seiscomp.core.Time (optional)
   - ``priority`` -- int (optional)

   **Methods**:

   .. py:staticmethod:: Cast(obj)

      :param obj: The object to be casted.
      :rtype: An object of type RouteArclink if the cast was successful,
              None otherwise.

      Cast an arbitrary object to RouteArclink if the internal wrapped
      representation is an RouteArclink object. The cast is important if
      instances of type :ref:`Object <api-python-datamodel-object>`
      are passed to methods which need access to the real type.



   .. py:method:: equal(other)

      :param other: Another object of type RouteArclink to compare this
                    instance to
      :rtype: A Boolean value indicating True if both objects are equal or
              False otherwise.

      Compares two objects without its child objects. Both objects are compared
      by value.

   .. py:method:: index()

      :rtype: The object's index of type RouteArclinkIndex.

       Returns the objects index which is also used for the database as unique
       constraint.

   .. py:method:: equalIndex(lhs)

      :param lhs: :ref:`RouteArclink <api-python-datamodel-routearclink>`
      :rtype: A Boolean value indicating True if both indexes are equal or
              False otherwise.

   .. py:method:: setAddress(address)

      :param address: string

      Server address in ip:port format

   .. py:method:: address()

      :rtype: string

   .. py:method:: setStart(start)

      :param start: seiscomp.core.Time

      Start of data

   .. py:method:: start()

      :rtype: seiscomp.core.Time

   .. py:method:: setEnd(end)

      :param end: seiscomp.core.Time

      End of data

   .. py:method:: end()

      :rtype: seiscomp.core.Time

      .. note::

         As this attribute is optional, this method throws a ValueError if
         the value of the attribute is not set.

   .. py:method:: setPriority(priority)

      :param priority: int

      priority \(1 is highest\)

   .. py:method:: priority()

      :rtype: int

      .. note::

         As this attribute is optional, this method throws a ValueError if
         the value of the attribute is not set.

   .. py:method:: route()

      :rtype: Route

      Returns the parent Route if available. Returns None
      if the parent is not a Route. This is a convenience wrapper
      for parent().

   .. py:method:: assign(other)

      This method implements the :ref:`Object <api-python-datamodel-object>` interface.

   .. py:method:: attachTo(parent)

      This method implements the :ref:`Object <api-python-datamodel-object>` interface.

   .. py:method:: detachFrom(parent)

      This method implements the :ref:`Object <api-python-datamodel-object>` interface.

   .. py:method:: detach()

      This method implements the :ref:`Object <api-python-datamodel-object>` interface.

   .. py:method:: clone()

      :rtype: A cloned RouteArclink.

      Returns a new instance that is a clone of the current instance. Child
      objects are being ignored.


   .. py:method:: accept(visitor)

      :param visitor: A visitor.

      This method implements the :ref:`PublicObject <api-python-datamodel-publicobject>` interface.

.. _api-python-datamodel-routeseedlink:

RouteSeedlink
............................................................

.. py:class:: RouteSeedlink

   Inherits :ref:`Object <api-python-datamodel-object>`.

   This type describes an SeedLink route \(data source\)

   **Parents**:

   - ``route`` -- :ref:`Route <api-python-datamodel-route>`

   **Attributes**:

   - ``address`` -- string
   - ``priority`` -- int (optional)

   **Methods**:

   .. py:staticmethod:: Cast(obj)

      :param obj: The object to be casted.
      :rtype: An object of type RouteSeedlink if the cast was successful,
              None otherwise.

      Cast an arbitrary object to RouteSeedlink if the internal wrapped
      representation is an RouteSeedlink object. The cast is important if
      instances of type :ref:`Object <api-python-datamodel-object>`
      are passed to methods which need access to the real type.



   .. py:method:: equal(other)

      :param other: Another object of type RouteSeedlink to compare this
                    instance to
      :rtype: A Boolean value indicating True if both objects are equal or
              False otherwise.

      Compares two objects without its child objects. Both objects are compared
      by value.

   .. py:method:: index()

      :rtype: The object's index of type RouteSeedlinkIndex.

       Returns the objects index which is also used for the database as unique
       constraint.

   .. py:method:: equalIndex(lhs)

      :param lhs: :ref:`RouteSeedlink <api-python-datamodel-routeseedlink>`
      :rtype: A Boolean value indicating True if both indexes are equal or
              False otherwise.

   .. py:method:: setAddress(address)

      :param address: string

      Server address in ip:port format

   .. py:method:: address()

      :rtype: string

   .. py:method:: setPriority(priority)

      :param priority: int

      priority \(1 is highest\)

   .. py:method:: priority()

      :rtype: int

      .. note::

         As this attribute is optional, this method throws a ValueError if
         the value of the attribute is not set.

   .. py:method:: route()

      :rtype: Route

      Returns the parent Route if available. Returns None
      if the parent is not a Route. This is a convenience wrapper
      for parent().

   .. py:method:: assign(other)

      This method implements the :ref:`Object <api-python-datamodel-object>` interface.

   .. py:method:: attachTo(parent)

      This method implements the :ref:`Object <api-python-datamodel-object>` interface.

   .. py:method:: detachFrom(parent)

      This method implements the :ref:`Object <api-python-datamodel-object>` interface.

   .. py:method:: detach()

      This method implements the :ref:`Object <api-python-datamodel-object>` interface.

   .. py:method:: clone()

      :rtype: A cloned RouteSeedlink.

      Returns a new instance that is a clone of the current instance. Child
      objects are being ignored.


   .. py:method:: accept(visitor)

      :param visitor: A visitor.

      This method implements the :ref:`PublicObject <api-python-datamodel-publicobject>` interface.

.. _api-python-datamodel-routing:

Routing
............................................................

.. py:class:: Routing

   Inherits :ref:`PublicObject <api-python-datamodel-publicobject>`.


   **Children**:

   - ``route`` -- :ref:`Route <api-python-datamodel-route>`
   - ``access`` -- :ref:`Access <api-python-datamodel-access>`

   **Attributes**:

   - ``publicID``: string

   **Methods**:

   .. py:staticmethod:: Cast(obj)

      :param obj: The object to be casted.
      :rtype: An object of type Routing if the cast was successful,
              None otherwise.

      Cast an arbitrary object to Routing if the internal wrapped
      representation is an Routing object. The cast is important if
      instances of type :ref:`Object <api-python-datamodel-object>`
      are passed to methods which need access to the real type.



   .. py:method:: equal(other)

      :param other: Another object of type Routing to compare this
                    instance to
      :rtype: A Boolean value indicating True if both objects are equal or
              False otherwise.

      Compares two objects without its child objects. Both objects are compared
      by value.

   .. py:method:: add(route)

      :param route: Object of type :ref:`Route <api-python-datamodel-route>`
      :rtype: A Boolean value indicating success with True, False otherwise.

      Adds a Route object to Routing. The object is not
      copied but managed by this instance. Any change to the passed object
      will also change the child.

   .. py:method:: add(access)

      :param access: Object of type :ref:`Access <api-python-datamodel-access>`
      :rtype: A Boolean value indicating success with True, False otherwise.

      Adds a Access object to Routing. The object is not
      copied but managed by this instance. Any change to the passed object
      will also change the child.

   .. py:method:: remove(route)

      :param route: Object of type :ref:`Route <api-python-datamodel-route>`
      :rtype: A Boolean value indicating success with True, False otherwise.

      Removes a previously added Route object from Routing.

   .. py:method:: remove(access)

      :param access: Object of type :ref:`Access <api-python-datamodel-access>`
      :rtype: A Boolean value indicating success with True, False otherwise.

      Removes a previously added Access object from Routing.

   .. py:method:: removeRoute(idx)

      :param idx: An integer index of the object to be removed.
      :rtype: A Boolean value indicating success with True, False otherwise.

   .. py:method:: removeRoute(routeIndex);

      :param routeIndex: The index of the object to be removed of type RouteIndex.
      :rtype: A Boolean value indicating success with True, False otherwise.

   .. py:method:: removeAccess(idx)

      :param idx: An integer index of the object to be removed.
      :rtype: A Boolean value indicating success with True, False otherwise.

   .. py:method:: removeAccess(accessIndex);

      :param accessIndex: The index of the object to be removed of type AccessIndex.
      :rtype: A Boolean value indicating success with True, False otherwise.

   .. py:method:: routeCount()

      :rtype: integer value indicating the number of child objects.

      Returns the number of Route child objects.

   .. py:method:: accessCount()

      :rtype: integer value indicating the number of child objects.

      Returns the number of Access child objects.

   .. py:method:: route(idx)

      :param idx: An integer index of the object to be returned.
      :rtype: Object of type :ref:`Route <api-python-datamodel-route>`.

      Returns the Route at index idx.

   .. py:method:: route(routeIndex)

      :param routeIndex: The index of the object to be removed of type RouteIndex.
      :rtype: Object of type :ref:`Route <api-python-datamodel-route>`.

      Returns the Route at given index. The indexes of all child objects
      are compared by value which makes this function slower than the direct
      integer index look-up.

   .. py:method:: access(idx)

      :param idx: An integer index of the object to be returned.
      :rtype: Object of type :ref:`Access <api-python-datamodel-access>`.

      Returns the Access at index idx.

   .. py:method:: access(accessIndex)

      :param accessIndex: The index of the object to be removed of type AccessIndex.
      :rtype: Object of type :ref:`Access <api-python-datamodel-access>`.

      Returns the Access at given index. The indexes of all child objects
      are compared by value which makes this function slower than the direct
      integer index look-up.

   .. py:method:: findRoute(publicID)

      :param publicID: The publicID of the object to find.
      :rtype: Object of type :ref:`Route <api-python-datamodel-route>`.

      Returns the child object with a certain publicID, None otherwise.

   .. py:method:: assign(other)

      This method implements the :ref:`Object <api-python-datamodel-object>` interface.

   .. py:method:: attachTo(parent)

      This method implements the :ref:`Object <api-python-datamodel-object>` interface.

   .. py:method:: detachFrom(parent)

      This method implements the :ref:`Object <api-python-datamodel-object>` interface.

   .. py:method:: detach()

      This method implements the :ref:`Object <api-python-datamodel-object>` interface.

   .. py:method:: clone()

      :rtype: A cloned Routing.

      Returns a new instance that is a clone of the current instance. Child
      objects are being ignored.


   .. py:method:: updateChild(ref)

      :param ref: A child object derived from class Object.
      :rtype: A Boolean flag indicating success with True, False otherwise

      This method takes the passed reference object and searches for a child
      with the same publicID (if derived from :ref:`PublicObject <api-python-datamodel-publicobject>`)
      or the same index (if derived from :ref:`Object <api-python-datamodel-object>`).
      The the child was found the reference objects attributes are copied to
      the child object. Children of child are being ignored during this operation.
      This method implements the :ref:`PublicObject <api-python-datamodel-publicobject>` interface.


   .. py:method:: accept(visitor)

      :param visitor: A visitor.

      This method implements the :ref:`PublicObject <api-python-datamodel-publicobject>` interface.

.. _api-python-datamodel-sensor:

Sensor
............................................................

.. py:class:: Sensor

   Inherits :ref:`PublicObject <api-python-datamodel-publicobject>`.

   This type describes a sensor

   **Parents**:

   - ``inventory`` -- :ref:`Inventory <api-python-datamodel-inventory>`

   **Children**:

   - ``sensorCalibration`` -- :ref:`SensorCalibration <api-python-datamodel-sensorcalibration>`

   **Attributes**:

   - ``publicID``: string
   - ``name`` -- string
   - ``description`` -- string
   - ``model`` -- string
   - ``manufacturer`` -- string
   - ``type`` -- string
   - ``unit`` -- string
   - ``lowFrequency`` -- float (optional)
   - ``highFrequency`` -- float (optional)
   - ``response`` -- string
   - ``remark`` -- :ref:`Blob <api-python-datamodel-blob>` (optional)

   **Referenced by**:

   - :func:`Stream.sensor`

   **Methods**:

   .. py:staticmethod:: Cast(obj)

      :param obj: The object to be casted.
      :rtype: An object of type Sensor if the cast was successful,
              None otherwise.

      Cast an arbitrary object to Sensor if the internal wrapped
      representation is an Sensor object. The cast is important if
      instances of type :ref:`Object <api-python-datamodel-object>`
      are passed to methods which need access to the real type.



   .. py:staticmethod:: Create()

      :rtype: A new object of type Sensor.

      Creates and registers (if enabled) a Sensor instance. The
      publicID is auto-generated.

   .. py:staticmethod:: Create(publicID)

      :rtype: A new object of type Sensor.

      Creates and registers (if enabled) a Sensor instance with
      passed publicID.

   .. py:method:: equal(other)

      :param other: Another object of type Sensor to compare this
                    instance to
      :rtype: A Boolean value indicating True if both objects are equal or
              False otherwise.

      Compares two objects without its child objects. Both objects are compared
      by value.

   .. py:method:: index()

      :rtype: The object's index of type SensorIndex.

       Returns the objects index which is also used for the database as unique
       constraint.

   .. py:method:: equalIndex(lhs)

      :param lhs: :ref:`Sensor <api-python-datamodel-sensor>`
      :rtype: A Boolean value indicating True if both indexes are equal or
              False otherwise.

   .. py:method:: setName(name)

      :param name: string

      Unique sensor name

   .. py:method:: name()

      :rtype: string

   .. py:method:: setDescription(description)

      :param description: string

      Sensor description

   .. py:method:: description()

      :rtype: string

   .. py:method:: setModel(model)

      :param model: string

      Sensor model

   .. py:method:: model()

      :rtype: string

   .. py:method:: setManufacturer(manufacturer)

      :param manufacturer: string

      Sensor manufacturer

   .. py:method:: manufacturer()

      :rtype: string

   .. py:method:: setType(type)

      :param type: string

      Sensor type \(VBB, BB, SP, SM, OBS\)

   .. py:method:: type()

      :rtype: string

   .. py:method:: setUnit(unit)

      :param unit: string

      Unit of measurement \(M, M\/S, M\/S**2, RAD\/S, V, A, PA, C\)

   .. py:method:: unit()

      :rtype: string

   .. py:method:: setLowFrequency(lowFrequency)

      :param lowFrequency: float

      Lower corner frequency \(optional\)

   .. py:method:: lowFrequency()

      :rtype: float

      .. note::

         As this attribute is optional, this method throws a ValueError if
         the value of the attribute is not set.

   .. py:method:: setHighFrequency(highFrequency)

      :param highFrequency: float

      Higher corner frequency \(optional\)

   .. py:method:: highFrequency()

      :rtype: float

      .. note::

         As this attribute is optional, this method throws a ValueError if
         the value of the attribute is not set.

   .. py:method:: setResponse(response)

      :param response: string

      Reference to responsePAZ\/\@publicID or responsePolynomial\/\@publicID or
      responseFAP\/\@publicID

   .. py:method:: response()

      :rtype: string

   .. py:method:: setRemark(remark)

      :param remark: :ref:`Blob <api-python-datamodel-blob>`

   .. py:method:: remark()

      :rtype: :ref:`Blob <api-python-datamodel-blob>`

      .. note::

         As this attribute is optional, this method throws a ValueError if
         the value of the attribute is not set.

   .. py:method:: add(sensorCalibration)

      :param sensorCalibration: Object of type :ref:`SensorCalibration <api-python-datamodel-sensorcalibration>`
      :rtype: A Boolean value indicating success with True, False otherwise.

      Adds a SensorCalibration object to Sensor. The object is not
      copied but managed by this instance. Any change to the passed object
      will also change the child.

   .. py:method:: remove(sensorCalibration)

      :param sensorCalibration: Object of type :ref:`SensorCalibration <api-python-datamodel-sensorcalibration>`
      :rtype: A Boolean value indicating success with True, False otherwise.

      Removes a previously added SensorCalibration object from Sensor.

   .. py:method:: removeSensorCalibration(idx)

      :param idx: An integer index of the object to be removed.
      :rtype: A Boolean value indicating success with True, False otherwise.

   .. py:method:: removeSensorCalibration(sensorCalibrationIndex);

      :param sensorCalibrationIndex: The index of the object to be removed of type SensorCalibrationIndex.
      :rtype: A Boolean value indicating success with True, False otherwise.

   .. py:method:: sensorCalibrationCount()

      :rtype: integer value indicating the number of child objects.

      Returns the number of SensorCalibration child objects.

   .. py:method:: sensorCalibration(idx)

      :param idx: An integer index of the object to be returned.
      :rtype: Object of type :ref:`SensorCalibration <api-python-datamodel-sensorcalibration>`.

      Returns the SensorCalibration at index idx.

   .. py:method:: sensorCalibration(sensorCalibrationIndex)

      :param sensorCalibrationIndex: The index of the object to be removed of type SensorCalibrationIndex.
      :rtype: Object of type :ref:`SensorCalibration <api-python-datamodel-sensorcalibration>`.

      Returns the SensorCalibration at given index. The indexes of all child objects
      are compared by value which makes this function slower than the direct
      integer index look-up.

   .. py:method:: inventory()

      :rtype: Inventory

      Returns the parent Inventory if available. Returns None
      if the parent is not a Inventory. This is a convenience wrapper
      for parent().

   .. py:method:: assign(other)

      This method implements the :ref:`Object <api-python-datamodel-object>` interface.

   .. py:method:: attachTo(parent)

      This method implements the :ref:`Object <api-python-datamodel-object>` interface.

   .. py:method:: detachFrom(parent)

      This method implements the :ref:`Object <api-python-datamodel-object>` interface.

   .. py:method:: detach()

      This method implements the :ref:`Object <api-python-datamodel-object>` interface.

   .. py:method:: clone()

      :rtype: A cloned Sensor.

      Returns a new instance that is a clone of the current instance. Child
      objects are being ignored.


   .. py:method:: updateChild(ref)

      :param ref: A child object derived from class Object.
      :rtype: A Boolean flag indicating success with True, False otherwise

      This method takes the passed reference object and searches for a child
      with the same publicID (if derived from :ref:`PublicObject <api-python-datamodel-publicobject>`)
      or the same index (if derived from :ref:`Object <api-python-datamodel-object>`).
      The the child was found the reference objects attributes are copied to
      the child object. Children of child are being ignored during this operation.
      This method implements the :ref:`PublicObject <api-python-datamodel-publicobject>` interface.


   .. py:method:: accept(visitor)

      :param visitor: A visitor.

      This method implements the :ref:`PublicObject <api-python-datamodel-publicobject>` interface.

.. _api-python-datamodel-sensorcalibration:

SensorCalibration
............................................................

.. py:class:: SensorCalibration

   Inherits :ref:`Object <api-python-datamodel-object>`.

   This type describes a sensor calibration

   **Parents**:

   - ``sensor`` -- :ref:`Sensor <api-python-datamodel-sensor>`

   **Attributes**:

   - ``serialNumber`` -- string
   - ``channel`` -- int
   - ``start`` -- seiscomp.core.Time
   - ``end`` -- seiscomp.core.Time (optional)
   - ``gain`` -- float (optional)
   - ``gainFrequency`` -- float (optional)
   - ``remark`` -- :ref:`Blob <api-python-datamodel-blob>` (optional)

   **Methods**:

   .. py:staticmethod:: Cast(obj)

      :param obj: The object to be casted.
      :rtype: An object of type SensorCalibration if the cast was successful,
              None otherwise.

      Cast an arbitrary object to SensorCalibration if the internal wrapped
      representation is an SensorCalibration object. The cast is important if
      instances of type :ref:`Object <api-python-datamodel-object>`
      are passed to methods which need access to the real type.



   .. py:method:: equal(other)

      :param other: Another object of type SensorCalibration to compare this
                    instance to
      :rtype: A Boolean value indicating True if both objects are equal or
              False otherwise.

      Compares two objects without its child objects. Both objects are compared
      by value.

   .. py:method:: index()

      :rtype: The object's index of type SensorCalibrationIndex.

       Returns the objects index which is also used for the database as unique
       constraint.

   .. py:method:: equalIndex(lhs)

      :param lhs: :ref:`SensorCalibration <api-python-datamodel-sensorcalibration>`
      :rtype: A Boolean value indicating True if both indexes are equal or
              False otherwise.

   .. py:method:: setSerialNumber(serialNumber)

      :param serialNumber: string

      Referred from network\/station\/Stream\/\@sensorSerialNumber

   .. py:method:: serialNumber()

      :rtype: string

   .. py:method:: setChannel(channel)

      :param channel: int

      Referred from network\/station\/Stream\/\@sensorChannel

   .. py:method:: channel()

      :rtype: int

   .. py:method:: setStart(start)

      :param start: seiscomp.core.Time

      Start of validity

   .. py:method:: start()

      :rtype: seiscomp.core.Time

   .. py:method:: setEnd(end)

      :param end: seiscomp.core.Time

      End of validity

   .. py:method:: end()

      :rtype: seiscomp.core.Time

      .. note::

         As this attribute is optional, this method throws a ValueError if
         the value of the attribute is not set.

   .. py:method:: setGain(gain)

      :param gain: float

      Overrides nominal gain of calibrated sensor \(48.05\/58.04\)

   .. py:method:: gain()

      :rtype: float

      .. note::

         As this attribute is optional, this method throws a ValueError if
         the value of the attribute is not set.

   .. py:method:: setGainFrequency(gainFrequency)

      :param gainFrequency: float

      Gain frequency \(48.06\/58.05\)

   .. py:method:: gainFrequency()

      :rtype: float

      .. note::

         As this attribute is optional, this method throws a ValueError if
         the value of the attribute is not set.

   .. py:method:: setRemark(remark)

      :param remark: :ref:`Blob <api-python-datamodel-blob>`

   .. py:method:: remark()

      :rtype: :ref:`Blob <api-python-datamodel-blob>`

      .. note::

         As this attribute is optional, this method throws a ValueError if
         the value of the attribute is not set.

   .. py:method:: sensor()

      :rtype: Sensor

      Returns the parent Sensor if available. Returns None
      if the parent is not a Sensor. This is a convenience wrapper
      for parent().

   .. py:method:: assign(other)

      This method implements the :ref:`Object <api-python-datamodel-object>` interface.

   .. py:method:: attachTo(parent)

      This method implements the :ref:`Object <api-python-datamodel-object>` interface.

   .. py:method:: detachFrom(parent)

      This method implements the :ref:`Object <api-python-datamodel-object>` interface.

   .. py:method:: detach()

      This method implements the :ref:`Object <api-python-datamodel-object>` interface.

   .. py:method:: clone()

      :rtype: A cloned SensorCalibration.

      Returns a new instance that is a clone of the current instance. Child
      objects are being ignored.


   .. py:method:: accept(visitor)

      :param visitor: A visitor.

      This method implements the :ref:`PublicObject <api-python-datamodel-publicobject>` interface.

.. _api-python-datamodel-sensorlocation:

SensorLocation
............................................................

.. py:class:: SensorLocation

   Inherits :ref:`PublicObject <api-python-datamodel-publicobject>`.

   This type describes a sensor location

   **Parents**:

   - ``station`` -- :ref:`Station <api-python-datamodel-station>`

   **Children**:

   - ``comment`` -- :ref:`Comment <api-python-datamodel-comment>`
   - ``auxStream`` -- :ref:`AuxStream <api-python-datamodel-auxstream>`
   - ``stream`` -- :ref:`Stream <api-python-datamodel-stream>`

   **Attributes**:

   - ``publicID``: string
   - ``code`` -- string
   - ``start`` -- seiscomp.core.Time
   - ``end`` -- seiscomp.core.Time (optional)
   - ``latitude`` -- float (optional)
   - ``longitude`` -- float (optional)
   - ``elevation`` -- float (optional)

   **Methods**:

   .. py:staticmethod:: Cast(obj)

      :param obj: The object to be casted.
      :rtype: An object of type SensorLocation if the cast was successful,
              None otherwise.

      Cast an arbitrary object to SensorLocation if the internal wrapped
      representation is an SensorLocation object. The cast is important if
      instances of type :ref:`Object <api-python-datamodel-object>`
      are passed to methods which need access to the real type.



   .. py:staticmethod:: Create()

      :rtype: A new object of type SensorLocation.

      Creates and registers (if enabled) a SensorLocation instance. The
      publicID is auto-generated.

   .. py:staticmethod:: Create(publicID)

      :rtype: A new object of type SensorLocation.

      Creates and registers (if enabled) a SensorLocation instance with
      passed publicID.

   .. py:method:: equal(other)

      :param other: Another object of type SensorLocation to compare this
                    instance to
      :rtype: A Boolean value indicating True if both objects are equal or
              False otherwise.

      Compares two objects without its child objects. Both objects are compared
      by value.

   .. py:method:: index()

      :rtype: The object's index of type SensorLocationIndex.

       Returns the objects index which is also used for the database as unique
       constraint.

   .. py:method:: equalIndex(lhs)

      :param lhs: :ref:`SensorLocation <api-python-datamodel-sensorlocation>`
      :rtype: A Boolean value indicating True if both indexes are equal or
              False otherwise.

   .. py:method:: setCode(code)

      :param code: string

      Station code \(52.03\)

   .. py:method:: code()

      :rtype: string

   .. py:method:: setStart(start)

      :param start: seiscomp.core.Time

      Start of epoch in ISO datetime format

   .. py:method:: start()

      :rtype: seiscomp.core.Time

   .. py:method:: setEnd(end)

      :param end: seiscomp.core.Time

      End of epoch

   .. py:method:: end()

      :rtype: seiscomp.core.Time

      .. note::

         As this attribute is optional, this method throws a ValueError if
         the value of the attribute is not set.

   .. py:method:: setLatitude(latitude)

      :param latitude: float

      Sensor latitude \(52.10\) with respect to the World Geodetic System
      1984 \(WGS84\) reference system \(National Imagery and Mapping Agency
      2000\) in degrees.

   .. py:method:: latitude()

      :rtype: float

      .. note::

         As this attribute is optional, this method throws a ValueError if
         the value of the attribute is not set.

   .. py:method:: setLongitude(longitude)

      :param longitude: float

      Sensor longitude \(52.11\) with respect to the World Geodetic System
      1984 \(WGS84\) reference system \(National Imagery and Mapping Agency
      2000\) in degrees.

   .. py:method:: longitude()

      :rtype: float

      .. note::

         As this attribute is optional, this method throws a ValueError if
         the value of the attribute is not set.

   .. py:method:: setElevation(elevation)

      :param elevation: float

      Sensor elevation \(52.12\) with respect to the World Geodetic System
      1984 \(WGS84\) reference system \(National Imagery and Mapping Agency
      2000\) in meters.

   .. py:method:: elevation()

      :rtype: float

      .. note::

         As this attribute is optional, this method throws a ValueError if
         the value of the attribute is not set.

   .. py:method:: add(comment)

      :param comment: Object of type :ref:`Comment <api-python-datamodel-comment>`
      :rtype: A Boolean value indicating success with True, False otherwise.

      Adds a Comment object to SensorLocation. The object is not
      copied but managed by this instance. Any change to the passed object
      will also change the child.

   .. py:method:: add(auxStream)

      :param auxStream: Object of type :ref:`AuxStream <api-python-datamodel-auxstream>`
      :rtype: A Boolean value indicating success with True, False otherwise.

      Adds a AuxStream object to SensorLocation. The object is not
      copied but managed by this instance. Any change to the passed object
      will also change the child.

   .. py:method:: add(stream)

      :param stream: Object of type :ref:`Stream <api-python-datamodel-stream>`
      :rtype: A Boolean value indicating success with True, False otherwise.

      Adds a Stream object to SensorLocation. The object is not
      copied but managed by this instance. Any change to the passed object
      will also change the child.

   .. py:method:: remove(comment)

      :param comment: Object of type :ref:`Comment <api-python-datamodel-comment>`
      :rtype: A Boolean value indicating success with True, False otherwise.

      Removes a previously added Comment object from SensorLocation.

   .. py:method:: remove(auxStream)

      :param auxStream: Object of type :ref:`AuxStream <api-python-datamodel-auxstream>`
      :rtype: A Boolean value indicating success with True, False otherwise.

      Removes a previously added AuxStream object from SensorLocation.

   .. py:method:: remove(stream)

      :param stream: Object of type :ref:`Stream <api-python-datamodel-stream>`
      :rtype: A Boolean value indicating success with True, False otherwise.

      Removes a previously added Stream object from SensorLocation.

   .. py:method:: removeComment(idx)

      :param idx: An integer index of the object to be removed.
      :rtype: A Boolean value indicating success with True, False otherwise.

   .. py:method:: removeComment(commentIndex);

      :param commentIndex: The index of the object to be removed of type CommentIndex.
      :rtype: A Boolean value indicating success with True, False otherwise.

   .. py:method:: removeAuxStream(idx)

      :param idx: An integer index of the object to be removed.
      :rtype: A Boolean value indicating success with True, False otherwise.

   .. py:method:: removeAuxStream(auxStreamIndex);

      :param auxStreamIndex: The index of the object to be removed of type AuxStreamIndex.
      :rtype: A Boolean value indicating success with True, False otherwise.

   .. py:method:: removeStream(idx)

      :param idx: An integer index of the object to be removed.
      :rtype: A Boolean value indicating success with True, False otherwise.

   .. py:method:: removeStream(streamIndex);

      :param streamIndex: The index of the object to be removed of type StreamIndex.
      :rtype: A Boolean value indicating success with True, False otherwise.

   .. py:method:: commentCount()

      :rtype: integer value indicating the number of child objects.

      Returns the number of Comment child objects.

   .. py:method:: auxStreamCount()

      :rtype: integer value indicating the number of child objects.

      Returns the number of AuxStream child objects.

   .. py:method:: streamCount()

      :rtype: integer value indicating the number of child objects.

      Returns the number of Stream child objects.

   .. py:method:: comment(idx)

      :param idx: An integer index of the object to be returned.
      :rtype: Object of type :ref:`Comment <api-python-datamodel-comment>`.

      Returns the Comment at index idx.

   .. py:method:: comment(commentIndex)

      :param commentIndex: The index of the object to be removed of type CommentIndex.
      :rtype: Object of type :ref:`Comment <api-python-datamodel-comment>`.

      Returns the Comment at given index. The indexes of all child objects
      are compared by value which makes this function slower than the direct
      integer index look-up.

   .. py:method:: auxStream(idx)

      :param idx: An integer index of the object to be returned.
      :rtype: Object of type :ref:`AuxStream <api-python-datamodel-auxstream>`.

      Returns the AuxStream at index idx.

   .. py:method:: auxStream(auxStreamIndex)

      :param auxStreamIndex: The index of the object to be removed of type AuxStreamIndex.
      :rtype: Object of type :ref:`AuxStream <api-python-datamodel-auxstream>`.

      Returns the AuxStream at given index. The indexes of all child objects
      are compared by value which makes this function slower than the direct
      integer index look-up.

   .. py:method:: stream(idx)

      :param idx: An integer index of the object to be returned.
      :rtype: Object of type :ref:`Stream <api-python-datamodel-stream>`.

      Returns the Stream at index idx.

   .. py:method:: stream(streamIndex)

      :param streamIndex: The index of the object to be removed of type StreamIndex.
      :rtype: Object of type :ref:`Stream <api-python-datamodel-stream>`.

      Returns the Stream at given index. The indexes of all child objects
      are compared by value which makes this function slower than the direct
      integer index look-up.

   .. py:method:: findStream(publicID)

      :param publicID: The publicID of the object to find.
      :rtype: Object of type :ref:`Stream <api-python-datamodel-stream>`.

      Returns the child object with a certain publicID, None otherwise.

   .. py:method:: station()

      :rtype: Station

      Returns the parent Station if available. Returns None
      if the parent is not a Station. This is a convenience wrapper
      for parent().

   .. py:method:: assign(other)

      This method implements the :ref:`Object <api-python-datamodel-object>` interface.

   .. py:method:: attachTo(parent)

      This method implements the :ref:`Object <api-python-datamodel-object>` interface.

   .. py:method:: detachFrom(parent)

      This method implements the :ref:`Object <api-python-datamodel-object>` interface.

   .. py:method:: detach()

      This method implements the :ref:`Object <api-python-datamodel-object>` interface.

   .. py:method:: clone()

      :rtype: A cloned SensorLocation.

      Returns a new instance that is a clone of the current instance. Child
      objects are being ignored.


   .. py:method:: updateChild(ref)

      :param ref: A child object derived from class Object.
      :rtype: A Boolean flag indicating success with True, False otherwise

      This method takes the passed reference object and searches for a child
      with the same publicID (if derived from :ref:`PublicObject <api-python-datamodel-publicobject>`)
      or the same index (if derived from :ref:`Object <api-python-datamodel-object>`).
      The the child was found the reference objects attributes are copied to
      the child object. Children of child are being ignored during this operation.
      This method implements the :ref:`PublicObject <api-python-datamodel-publicobject>` interface.


   .. py:method:: accept(visitor)

      :param visitor: A visitor.

      This method implements the :ref:`PublicObject <api-python-datamodel-publicobject>` interface.

.. _api-python-datamodel-setup:

Setup
............................................................

.. py:class:: Setup

   Inherits :ref:`Object <api-python-datamodel-object>`.


   **Parents**:

   - ``configStation`` -- :ref:`ConfigStation <api-python-datamodel-configstation>`

   **Attributes**:

   - ``name`` -- string
   - ``parameterSetID`` -- string
   - ``enabled`` -- boolean

   **Methods**:

   .. py:staticmethod:: Cast(obj)

      :param obj: The object to be casted.
      :rtype: An object of type Setup if the cast was successful,
              None otherwise.

      Cast an arbitrary object to Setup if the internal wrapped
      representation is an Setup object. The cast is important if
      instances of type :ref:`Object <api-python-datamodel-object>`
      are passed to methods which need access to the real type.



   .. py:method:: equal(other)

      :param other: Another object of type Setup to compare this
                    instance to
      :rtype: A Boolean value indicating True if both objects are equal or
              False otherwise.

      Compares two objects without its child objects. Both objects are compared
      by value.

   .. py:method:: index()

      :rtype: The object's index of type SetupIndex.

       Returns the objects index which is also used for the database as unique
       constraint.

   .. py:method:: equalIndex(lhs)

      :param lhs: :ref:`Setup <api-python-datamodel-setup>`
      :rtype: A Boolean value indicating True if both indexes are equal or
              False otherwise.

   .. py:method:: setName(name)

      :param name: string

   .. py:method:: name()

      :rtype: string

   .. py:method:: setParameterSetID(parameterSetID)

      :param parameterSetID: string

   .. py:method:: parameterSetID()

      :rtype: string

   .. py:method:: setEnabled(enabled)

      :param enabled: boolean

   .. py:method:: enabled()

      :rtype: boolean

   .. py:method:: configStation()

      :rtype: ConfigStation

      Returns the parent ConfigStation if available. Returns None
      if the parent is not a ConfigStation. This is a convenience wrapper
      for parent().

   .. py:method:: assign(other)

      This method implements the :ref:`Object <api-python-datamodel-object>` interface.

   .. py:method:: attachTo(parent)

      This method implements the :ref:`Object <api-python-datamodel-object>` interface.

   .. py:method:: detachFrom(parent)

      This method implements the :ref:`Object <api-python-datamodel-object>` interface.

   .. py:method:: detach()

      This method implements the :ref:`Object <api-python-datamodel-object>` interface.

   .. py:method:: clone()

      :rtype: A cloned Setup.

      Returns a new instance that is a clone of the current instance. Child
      objects are being ignored.


   .. py:method:: accept(visitor)

      :param visitor: A visitor.

      This method implements the :ref:`PublicObject <api-python-datamodel-publicobject>` interface.

.. _api-python-datamodel-sourcetimefunction:

SourceTimeFunction
............................................................

.. py:class:: SourceTimeFunction

   Inherits :ref:`Object <api-python-datamodel-object>`.

   Source time function used in moment\-tensor inversion.

   **Attributes**:

   - ``type`` -- :ref:`SourceTimeFunctionType <api-python-datamodel-sourcetimefunctiontype>`
   - ``duration`` -- float
   - ``riseTime`` -- float (optional)
   - ``decayTime`` -- float (optional)

   **Used by**:

   - :func:`MomentTensor.sourceTimeFunction`

   **Methods**:

   .. py:staticmethod:: Cast(obj)

      :param obj: The object to be casted.
      :rtype: An object of type SourceTimeFunction if the cast was successful,
              None otherwise.

      Cast an arbitrary object to SourceTimeFunction if the internal wrapped
      representation is an SourceTimeFunction object. The cast is important if
      instances of type :ref:`Object <api-python-datamodel-object>`
      are passed to methods which need access to the real type.



   .. py:method:: equal(other)

      :param other: Another object of type SourceTimeFunction to compare this
                    instance to
      :rtype: A Boolean value indicating True if both objects are equal or
              False otherwise.

      Compares two objects without its child objects. Both objects are compared
      by value.

   .. py:method:: setType(type)

      :param type: SourceTimeFunctionType

      Type of source time function. Values can be taken from the following:
      BOX_CAR, TRIANGLE, TRAPEZOID, UNKNOWN_FUNCTION.

   .. py:method:: type()

      :rtype: SourceTimeFunctionType

   .. py:method:: setDuration(duration)

      :param duration: float

      Source time function duration in seconds.

   .. py:method:: duration()

      :rtype: float

   .. py:method:: setRiseTime(riseTime)

      :param riseTime: float

      Source time function rise time in seconds.

   .. py:method:: riseTime()

      :rtype: float

      .. note::

         As this attribute is optional, this method throws a ValueError if
         the value of the attribute is not set.

   .. py:method:: setDecayTime(decayTime)

      :param decayTime: float

      Source time function decay time in seconds.

   .. py:method:: decayTime()

      :rtype: float

      .. note::

         As this attribute is optional, this method throws a ValueError if
         the value of the attribute is not set.

.. _api-python-datamodel-station:

Station
............................................................

.. py:class:: Station

   Inherits :ref:`PublicObject <api-python-datamodel-publicobject>`.

   This type describes a seismic station

   **Parents**:

   - ``network`` -- :ref:`Network <api-python-datamodel-network>`

   **Children**:

   - ``comment`` -- :ref:`Comment <api-python-datamodel-comment>`
   - ``sensorLocation`` -- :ref:`SensorLocation <api-python-datamodel-sensorlocation>`

   **Attributes**:

   - ``publicID``: string
   - ``code`` -- string
   - ``start`` -- seiscomp.core.Time
   - ``end`` -- seiscomp.core.Time (optional)
   - ``description`` -- string
   - ``latitude`` -- float (optional)
   - ``longitude`` -- float (optional)
   - ``elevation`` -- float (optional)
   - ``place`` -- string
   - ``country`` -- string
   - ``affiliation`` -- string
   - ``type`` -- string
   - ``archive`` -- string
   - ``archiveNetworkCode`` -- string
   - ``restricted`` -- boolean (optional)
   - ``shared`` -- boolean (optional)
   - ``remark`` -- :ref:`Blob <api-python-datamodel-blob>` (optional)

   **Referenced by**:

   - :func:`StationReference.stationID`

   **Methods**:

   .. py:staticmethod:: Cast(obj)

      :param obj: The object to be casted.
      :rtype: An object of type Station if the cast was successful,
              None otherwise.

      Cast an arbitrary object to Station if the internal wrapped
      representation is an Station object. The cast is important if
      instances of type :ref:`Object <api-python-datamodel-object>`
      are passed to methods which need access to the real type.



   .. py:staticmethod:: Create()

      :rtype: A new object of type Station.

      Creates and registers (if enabled) a Station instance. The
      publicID is auto-generated.

   .. py:staticmethod:: Create(publicID)

      :rtype: A new object of type Station.

      Creates and registers (if enabled) a Station instance with
      passed publicID.

   .. py:method:: equal(other)

      :param other: Another object of type Station to compare this
                    instance to
      :rtype: A Boolean value indicating True if both objects are equal or
              False otherwise.

      Compares two objects without its child objects. Both objects are compared
      by value.

   .. py:method:: index()

      :rtype: The object's index of type StationIndex.

       Returns the objects index which is also used for the database as unique
       constraint.

   .. py:method:: equalIndex(lhs)

      :param lhs: :ref:`Station <api-python-datamodel-station>`
      :rtype: A Boolean value indicating True if both indexes are equal or
              False otherwise.

   .. py:method:: setCode(code)

      :param code: string

      Station code \(50.03\)

   .. py:method:: code()

      :rtype: string

   .. py:method:: setStart(start)

      :param start: seiscomp.core.Time

      Start of station epoch in ISO datetime format

   .. py:method:: start()

      :rtype: seiscomp.core.Time

   .. py:method:: setEnd(end)

      :param end: seiscomp.core.Time

      End of station epoch. Empty string if the station is open

   .. py:method:: end()

      :rtype: seiscomp.core.Time

      .. note::

         As this attribute is optional, this method throws a ValueError if
         the value of the attribute is not set.

   .. py:method:: setDescription(description)

      :param description: string

      Station description in ASCII \(50.09\)

   .. py:method:: description()

      :rtype: string

   .. py:method:: setLatitude(latitude)

      :param latitude: float

      Station latitude \(50.04\) with respect to the World Geodetic System
      1984 \(WGS84\) reference system \(National Imagery and Mapping Agency
      2000\) in degrees.

   .. py:method:: latitude()

      :rtype: float

      .. note::

         As this attribute is optional, this method throws a ValueError if
         the value of the attribute is not set.

   .. py:method:: setLongitude(longitude)

      :param longitude: float

      Station longitude \(50.05\) with respect to the World Geodetic System
      1984 \(WGS84\) reference system \(National Imagery and Mapping Agency
      2000\) in degrees.

   .. py:method:: longitude()

      :rtype: float

      .. note::

         As this attribute is optional, this method throws a ValueError if
         the value of the attribute is not set.

   .. py:method:: setElevation(elevation)

      :param elevation: float

      Station elevation \(50.06\) with respect to the World Geodetic System
      1984 \(WGS84\) reference system \(National Imagery and Mapping Agency
      2000\) in meters.

   .. py:method:: elevation()

      :rtype: float

      .. note::

         As this attribute is optional, this method throws a ValueError if
         the value of the attribute is not set.

   .. py:method:: setPlace(place)

      :param place: string

      Place where the station is located \(UTF\-8\)

   .. py:method:: place()

      :rtype: string

   .. py:method:: setCountry(country)

      :param country: string

      Country where the station is located \(UTF\-8\)

   .. py:method:: country()

      :rtype: string

   .. py:method:: setAffiliation(affiliation)

      :param affiliation: string

      Station affiliation \(eg., GEOFON\)

   .. py:method:: affiliation()

      :rtype: string

   .. py:method:: setType(type)

      :param type: string

      Type of station \(eg., VBB, SP\)

   .. py:method:: type()

      :rtype: string

   .. py:method:: setArchive(archive)

      :param archive: string

      Archive\/Datacenter ID \(metadata authority\)

   .. py:method:: archive()

      :rtype: string

   .. py:method:: setArchiveNetworkCode(archiveNetworkCode)

      :param archiveNetworkCode: string

      Internal network code, under which this station is archived

   .. py:method:: archiveNetworkCode()

      :rtype: string

   .. py:method:: setRestricted(restricted)

      :param restricted: boolean

      Whether the station is \"restricted\"

   .. py:method:: restricted()

      :rtype: boolean

      .. note::

         As this attribute is optional, this method throws a ValueError if
         the value of the attribute is not set.

   .. py:method:: setShared(shared)

      :param shared: boolean

      Whether the metadata is synchronized with other datacenters

   .. py:method:: shared()

      :rtype: boolean

      .. note::

         As this attribute is optional, this method throws a ValueError if
         the value of the attribute is not set.

   .. py:method:: setRemark(remark)

      :param remark: :ref:`Blob <api-python-datamodel-blob>`

      Any notes

   .. py:method:: remark()

      :rtype: :ref:`Blob <api-python-datamodel-blob>`

      .. note::

         As this attribute is optional, this method throws a ValueError if
         the value of the attribute is not set.

   .. py:method:: add(comment)

      :param comment: Object of type :ref:`Comment <api-python-datamodel-comment>`
      :rtype: A Boolean value indicating success with True, False otherwise.

      Adds a Comment object to Station. The object is not
      copied but managed by this instance. Any change to the passed object
      will also change the child.

   .. py:method:: add(sensorLocation)

      :param sensorLocation: Object of type :ref:`SensorLocation <api-python-datamodel-sensorlocation>`
      :rtype: A Boolean value indicating success with True, False otherwise.

      Adds a SensorLocation object to Station. The object is not
      copied but managed by this instance. Any change to the passed object
      will also change the child.

   .. py:method:: remove(comment)

      :param comment: Object of type :ref:`Comment <api-python-datamodel-comment>`
      :rtype: A Boolean value indicating success with True, False otherwise.

      Removes a previously added Comment object from Station.

   .. py:method:: remove(sensorLocation)

      :param sensorLocation: Object of type :ref:`SensorLocation <api-python-datamodel-sensorlocation>`
      :rtype: A Boolean value indicating success with True, False otherwise.

      Removes a previously added SensorLocation object from Station.

   .. py:method:: removeComment(idx)

      :param idx: An integer index of the object to be removed.
      :rtype: A Boolean value indicating success with True, False otherwise.

   .. py:method:: removeComment(commentIndex);

      :param commentIndex: The index of the object to be removed of type CommentIndex.
      :rtype: A Boolean value indicating success with True, False otherwise.

   .. py:method:: removeSensorLocation(idx)

      :param idx: An integer index of the object to be removed.
      :rtype: A Boolean value indicating success with True, False otherwise.

   .. py:method:: removeSensorLocation(sensorLocationIndex);

      :param sensorLocationIndex: The index of the object to be removed of type SensorLocationIndex.
      :rtype: A Boolean value indicating success with True, False otherwise.

   .. py:method:: commentCount()

      :rtype: integer value indicating the number of child objects.

      Returns the number of Comment child objects.

   .. py:method:: sensorLocationCount()

      :rtype: integer value indicating the number of child objects.

      Returns the number of SensorLocation child objects.

   .. py:method:: comment(idx)

      :param idx: An integer index of the object to be returned.
      :rtype: Object of type :ref:`Comment <api-python-datamodel-comment>`.

      Returns the Comment at index idx.

   .. py:method:: comment(commentIndex)

      :param commentIndex: The index of the object to be removed of type CommentIndex.
      :rtype: Object of type :ref:`Comment <api-python-datamodel-comment>`.

      Returns the Comment at given index. The indexes of all child objects
      are compared by value which makes this function slower than the direct
      integer index look-up.

   .. py:method:: sensorLocation(idx)

      :param idx: An integer index of the object to be returned.
      :rtype: Object of type :ref:`SensorLocation <api-python-datamodel-sensorlocation>`.

      Returns the SensorLocation at index idx.

   .. py:method:: sensorLocation(sensorLocationIndex)

      :param sensorLocationIndex: The index of the object to be removed of type SensorLocationIndex.
      :rtype: Object of type :ref:`SensorLocation <api-python-datamodel-sensorlocation>`.

      Returns the SensorLocation at given index. The indexes of all child objects
      are compared by value which makes this function slower than the direct
      integer index look-up.

   .. py:method:: findSensorLocation(publicID)

      :param publicID: The publicID of the object to find.
      :rtype: Object of type :ref:`SensorLocation <api-python-datamodel-sensorlocation>`.

      Returns the child object with a certain publicID, None otherwise.

   .. py:method:: network()

      :rtype: Network

      Returns the parent Network if available. Returns None
      if the parent is not a Network. This is a convenience wrapper
      for parent().

   .. py:method:: assign(other)

      This method implements the :ref:`Object <api-python-datamodel-object>` interface.

   .. py:method:: attachTo(parent)

      This method implements the :ref:`Object <api-python-datamodel-object>` interface.

   .. py:method:: detachFrom(parent)

      This method implements the :ref:`Object <api-python-datamodel-object>` interface.

   .. py:method:: detach()

      This method implements the :ref:`Object <api-python-datamodel-object>` interface.

   .. py:method:: clone()

      :rtype: A cloned Station.

      Returns a new instance that is a clone of the current instance. Child
      objects are being ignored.


   .. py:method:: updateChild(ref)

      :param ref: A child object derived from class Object.
      :rtype: A Boolean flag indicating success with True, False otherwise

      This method takes the passed reference object and searches for a child
      with the same publicID (if derived from :ref:`PublicObject <api-python-datamodel-publicobject>`)
      or the same index (if derived from :ref:`Object <api-python-datamodel-object>`).
      The the child was found the reference objects attributes are copied to
      the child object. Children of child are being ignored during this operation.
      This method implements the :ref:`PublicObject <api-python-datamodel-publicobject>` interface.


   .. py:method:: accept(visitor)

      :param visitor: A visitor.

      This method implements the :ref:`PublicObject <api-python-datamodel-publicobject>` interface.

.. _api-python-datamodel-stationgroup:

StationGroup
............................................................

.. py:class:: StationGroup

   Inherits :ref:`PublicObject <api-python-datamodel-publicobject>`.

   This type describes a group of stations, an array or a virtual network

   **Parents**:

   - ``inventory`` -- :ref:`Inventory <api-python-datamodel-inventory>`

   **Children**:

   - ``stationReference`` -- :ref:`StationReference <api-python-datamodel-stationreference>`

   **Attributes**:

   - ``publicID``: string
   - ``type`` -- :ref:`StationGroupType <api-python-datamodel-stationgrouptype>` (optional)
   - ``code`` -- string
   - ``start`` -- seiscomp.core.Time (optional)
   - ``end`` -- seiscomp.core.Time (optional)
   - ``description`` -- string
   - ``latitude`` -- float (optional)
   - ``longitude`` -- float (optional)
   - ``elevation`` -- float (optional)

   **Methods**:

   .. py:staticmethod:: Cast(obj)

      :param obj: The object to be casted.
      :rtype: An object of type StationGroup if the cast was successful,
              None otherwise.

      Cast an arbitrary object to StationGroup if the internal wrapped
      representation is an StationGroup object. The cast is important if
      instances of type :ref:`Object <api-python-datamodel-object>`
      are passed to methods which need access to the real type.



   .. py:staticmethod:: Create()

      :rtype: A new object of type StationGroup.

      Creates and registers (if enabled) a StationGroup instance. The
      publicID is auto-generated.

   .. py:staticmethod:: Create(publicID)

      :rtype: A new object of type StationGroup.

      Creates and registers (if enabled) a StationGroup instance with
      passed publicID.

   .. py:method:: equal(other)

      :param other: Another object of type StationGroup to compare this
                    instance to
      :rtype: A Boolean value indicating True if both objects are equal or
              False otherwise.

      Compares two objects without its child objects. Both objects are compared
      by value.

   .. py:method:: index()

      :rtype: The object's index of type StationGroupIndex.

       Returns the objects index which is also used for the database as unique
       constraint.

   .. py:method:: equalIndex(lhs)

      :param lhs: :ref:`StationGroup <api-python-datamodel-stationgroup>`
      :rtype: A Boolean value indicating True if both indexes are equal or
              False otherwise.

   .. py:method:: setType(type)

      :param type: StationGroupType

      ARRAY or DEPLOYMENT

   .. py:method:: type()

      :rtype: StationGroupType

      .. note::

         As this attribute is optional, this method throws a ValueError if
         the value of the attribute is not set.

   .. py:method:: setCode(code)

      :param code: string

      Virtual network code \(up to 20 characters\)

   .. py:method:: code()

      :rtype: string

   .. py:method:: setStart(start)

      :param start: seiscomp.core.Time

      Start of epoch in ISO datetime format

   .. py:method:: start()

      :rtype: seiscomp.core.Time

      .. note::

         As this attribute is optional, this method throws a ValueError if
         the value of the attribute is not set.

   .. py:method:: setEnd(end)

      :param end: seiscomp.core.Time

      End of epoch \(empty string if the station is open\)

   .. py:method:: end()

      :rtype: seiscomp.core.Time

      .. note::

         As this attribute is optional, this method throws a ValueError if
         the value of the attribute is not set.

   .. py:method:: setDescription(description)

      :param description: string

      Station group description

   .. py:method:: description()

      :rtype: string

   .. py:method:: setLatitude(latitude)

      :param latitude: float

      Optional latitude \(eg., of the central station\) with respect to the
      World Geodetic System 1984 \(WGS84\) reference system \(National
      Imagery and Mapping Agency 2000\) in degrees. The uncertainties are
      given in kilometers.

   .. py:method:: latitude()

      :rtype: float

      .. note::

         As this attribute is optional, this method throws a ValueError if
         the value of the attribute is not set.

   .. py:method:: setLongitude(longitude)

      :param longitude: float

      Optional longitude \(eg., of the central station\) with respect to the
      World Geodetic System 1984 \(WGS84\) reference system \(National
      Imagery and Mapping Agency 2000\) in degrees.

   .. py:method:: longitude()

      :rtype: float

      .. note::

         As this attribute is optional, this method throws a ValueError if
         the value of the attribute is not set.

   .. py:method:: setElevation(elevation)

      :param elevation: float

      Optional elevation \(eg., of the central station\) with respect to the
      World Geodetic System 1984 \(WGS84\) reference system \(National Imagery
      and Mapping Agency 2000\) in meters.

   .. py:method:: elevation()

      :rtype: float

      .. note::

         As this attribute is optional, this method throws a ValueError if
         the value of the attribute is not set.

   .. py:method:: add(stationReference)

      :param stationReference: Object of type :ref:`StationReference <api-python-datamodel-stationreference>`
      :rtype: A Boolean value indicating success with True, False otherwise.

      Adds a StationReference object to StationGroup. The object is not
      copied but managed by this instance. Any change to the passed object
      will also change the child.

   .. py:method:: remove(stationReference)

      :param stationReference: Object of type :ref:`StationReference <api-python-datamodel-stationreference>`
      :rtype: A Boolean value indicating success with True, False otherwise.

      Removes a previously added StationReference object from StationGroup.

   .. py:method:: removeStationReference(idx)

      :param idx: An integer index of the object to be removed.
      :rtype: A Boolean value indicating success with True, False otherwise.

   .. py:method:: removeStationReference(stationReferenceIndex);

      :param stationReferenceIndex: The index of the object to be removed of type StationReferenceIndex.
      :rtype: A Boolean value indicating success with True, False otherwise.

   .. py:method:: stationReferenceCount()

      :rtype: integer value indicating the number of child objects.

      Returns the number of StationReference child objects.

   .. py:method:: stationReference(idx)

      :param idx: An integer index of the object to be returned.
      :rtype: Object of type :ref:`StationReference <api-python-datamodel-stationreference>`.

      Returns the StationReference at index idx.

   .. py:method:: stationReference(stationReferenceIndex)

      :param stationReferenceIndex: The index of the object to be removed of type StationReferenceIndex.
      :rtype: Object of type :ref:`StationReference <api-python-datamodel-stationreference>`.

      Returns the StationReference at given index. The indexes of all child objects
      are compared by value which makes this function slower than the direct
      integer index look-up.

   .. py:method:: inventory()

      :rtype: Inventory

      Returns the parent Inventory if available. Returns None
      if the parent is not a Inventory. This is a convenience wrapper
      for parent().

   .. py:method:: assign(other)

      This method implements the :ref:`Object <api-python-datamodel-object>` interface.

   .. py:method:: attachTo(parent)

      This method implements the :ref:`Object <api-python-datamodel-object>` interface.

   .. py:method:: detachFrom(parent)

      This method implements the :ref:`Object <api-python-datamodel-object>` interface.

   .. py:method:: detach()

      This method implements the :ref:`Object <api-python-datamodel-object>` interface.

   .. py:method:: clone()

      :rtype: A cloned StationGroup.

      Returns a new instance that is a clone of the current instance. Child
      objects are being ignored.


   .. py:method:: updateChild(ref)

      :param ref: A child object derived from class Object.
      :rtype: A Boolean flag indicating success with True, False otherwise

      This method takes the passed reference object and searches for a child
      with the same publicID (if derived from :ref:`PublicObject <api-python-datamodel-publicobject>`)
      or the same index (if derived from :ref:`Object <api-python-datamodel-object>`).
      The the child was found the reference objects attributes are copied to
      the child object. Children of child are being ignored during this operation.
      This method implements the :ref:`PublicObject <api-python-datamodel-publicobject>` interface.


   .. py:method:: accept(visitor)

      :param visitor: A visitor.

      This method implements the :ref:`PublicObject <api-python-datamodel-publicobject>` interface.

.. _api-python-datamodel-stationmagnitude:

StationMagnitude
............................................................

.. py:class:: StationMagnitude

   Inherits :ref:`PublicObject <api-python-datamodel-publicobject>`.

   This class describes the magnitude derived from a single waveform stream.

   **Parents**:

   - ``origin`` -- :ref:`Origin <api-python-datamodel-origin>`

   **Children**:

   - ``comment`` -- :ref:`Comment <api-python-datamodel-comment>`

   **Attributes**:

   - ``publicID``: string
   - ``originID`` -- string
   - ``magnitude`` -- :ref:`RealQuantity <api-python-datamodel-realquantity>`
   - ``type`` -- string
   - ``amplitudeID`` -- string
   - ``methodID`` -- string
   - ``waveformID`` -- :ref:`WaveformStreamID <api-python-datamodel-waveformstreamid>` (optional)
   - ``passedQC`` -- boolean (optional)
   - ``creationInfo`` -- :ref:`CreationInfo <api-python-datamodel-creationinfo>` (optional)

   **Methods**:

   .. py:staticmethod:: Cast(obj)

      :param obj: The object to be casted.
      :rtype: An object of type StationMagnitude if the cast was successful,
              None otherwise.

      Cast an arbitrary object to StationMagnitude if the internal wrapped
      representation is an StationMagnitude object. The cast is important if
      instances of type :ref:`Object <api-python-datamodel-object>`
      are passed to methods which need access to the real type.



   .. py:staticmethod:: Create()

      :rtype: A new object of type StationMagnitude.

      Creates and registers (if enabled) a StationMagnitude instance. The
      publicID is auto-generated.

   .. py:staticmethod:: Create(publicID)

      :rtype: A new object of type StationMagnitude.

      Creates and registers (if enabled) a StationMagnitude instance with
      passed publicID.

   .. py:method:: equal(other)

      :param other: Another object of type StationMagnitude to compare this
                    instance to
      :rtype: A Boolean value indicating True if both objects are equal or
              False otherwise.

      Compares two objects without its child objects. Both objects are compared
      by value.

   .. py:method:: setOriginID(originID)

      :param originID: string

      Reference to an origin's publicID if the StationMagnitude has an associated
      Origin.

   .. py:method:: originID()

      :rtype: string

   .. py:method:: setMagnitude(magnitude)

      :param magnitude: :ref:`RealQuantity <api-python-datamodel-realquantity>`

      Estimated magnitude as RealQuantity.

   .. py:method:: magnitude()

      :rtype: :ref:`RealQuantity <api-python-datamodel-realquantity>`

   .. py:method:: setType(type)

      :param type: string

      See class Magnitude.

   .. py:method:: type()

      :rtype: string

   .. py:method:: setAmplitudeID(amplitudeID)

      :param amplitudeID: string

      Identifies the data source of the StationMagnitude. For magnitudes derived
      from amplitudes in
      waveforms \(e. g., local magnitude ML \), amplitudeID points to publicID in
      class Amplitude.

   .. py:method:: amplitudeID()

      :rtype: string

   .. py:method:: setMethodID(methodID)

      :param methodID: string

      See class Magnitude.

   .. py:method:: methodID()

      :rtype: string

   .. py:method:: setWaveformID(waveformID)

      :param waveformID: :ref:`WaveformStreamID <api-python-datamodel-waveformstreamid>`

      Identifies the waveform stream. This element can be helpful if no
      amplitude is referenced, or the amplitude is not available in the
      context. Otherwise, it would duplicate the waveformID provided there
      and can be omitted.

   .. py:method:: waveformID()

      :rtype: :ref:`WaveformStreamID <api-python-datamodel-waveformstreamid>`

      .. note::

         As this attribute is optional, this method throws a ValueError if
         the value of the attribute is not set.

   .. py:method:: setPassedQC(passedQC)

      :param passedQC: boolean

      An optional flag that indicates whether a station magnitude has passed
      the quality control or not. For example, if a station magnitude is
      out of the defined distance range but should be associated to a network
      magnitude for further analysis then this flag can be set to false.
      If the flag is not set, it defaults to true.

   .. py:method:: passedQC()

      :rtype: boolean

      .. note::

         As this attribute is optional, this method throws a ValueError if
         the value of the attribute is not set.

   .. py:method:: setCreationInfo(creationInfo)

      :param creationInfo: :ref:`CreationInfo <api-python-datamodel-creationinfo>`

      CreationInfo for the StationMagnitude object.

   .. py:method:: creationInfo()

      :rtype: :ref:`CreationInfo <api-python-datamodel-creationinfo>`

      .. note::

         As this attribute is optional, this method throws a ValueError if
         the value of the attribute is not set.

   .. py:method:: add(comment)

      :param comment: Object of type :ref:`Comment <api-python-datamodel-comment>`
      :rtype: A Boolean value indicating success with True, False otherwise.

      Adds a Comment object to StationMagnitude. The object is not
      copied but managed by this instance. Any change to the passed object
      will also change the child.

   .. py:method:: remove(comment)

      :param comment: Object of type :ref:`Comment <api-python-datamodel-comment>`
      :rtype: A Boolean value indicating success with True, False otherwise.

      Removes a previously added Comment object from StationMagnitude.

   .. py:method:: removeComment(idx)

      :param idx: An integer index of the object to be removed.
      :rtype: A Boolean value indicating success with True, False otherwise.

   .. py:method:: removeComment(commentIndex);

      :param commentIndex: The index of the object to be removed of type CommentIndex.
      :rtype: A Boolean value indicating success with True, False otherwise.

   .. py:method:: commentCount()

      :rtype: integer value indicating the number of child objects.

      Returns the number of Comment child objects.

   .. py:method:: comment(idx)

      :param idx: An integer index of the object to be returned.
      :rtype: Object of type :ref:`Comment <api-python-datamodel-comment>`.

      Returns the Comment at index idx.

   .. py:method:: comment(commentIndex)

      :param commentIndex: The index of the object to be removed of type CommentIndex.
      :rtype: Object of type :ref:`Comment <api-python-datamodel-comment>`.

      Returns the Comment at given index. The indexes of all child objects
      are compared by value which makes this function slower than the direct
      integer index look-up.

   .. py:method:: origin()

      :rtype: Origin

      Returns the parent Origin if available. Returns None
      if the parent is not a Origin. This is a convenience wrapper
      for parent().

   .. py:method:: assign(other)

      This method implements the :ref:`Object <api-python-datamodel-object>` interface.

   .. py:method:: attachTo(parent)

      This method implements the :ref:`Object <api-python-datamodel-object>` interface.

   .. py:method:: detachFrom(parent)

      This method implements the :ref:`Object <api-python-datamodel-object>` interface.

   .. py:method:: detach()

      This method implements the :ref:`Object <api-python-datamodel-object>` interface.

   .. py:method:: clone()

      :rtype: A cloned StationMagnitude.

      Returns a new instance that is a clone of the current instance. Child
      objects are being ignored.


   .. py:method:: updateChild(ref)

      :param ref: A child object derived from class Object.
      :rtype: A Boolean flag indicating success with True, False otherwise

      This method takes the passed reference object and searches for a child
      with the same publicID (if derived from :ref:`PublicObject <api-python-datamodel-publicobject>`)
      or the same index (if derived from :ref:`Object <api-python-datamodel-object>`).
      The the child was found the reference objects attributes are copied to
      the child object. Children of child are being ignored during this operation.
      This method implements the :ref:`PublicObject <api-python-datamodel-publicobject>` interface.


   .. py:method:: accept(visitor)

      :param visitor: A visitor.

      This method implements the :ref:`PublicObject <api-python-datamodel-publicobject>` interface.

.. _api-python-datamodel-stationmagnitudecontribution:

StationMagnitudeContribution
............................................................

.. py:class:: StationMagnitudeContribution

   Inherits :ref:`Object <api-python-datamodel-object>`.

   This class describes the weighting of magnitude values from several
   StationMagnitude objects for computing a
   network magnitude estimation.

   **Parents**:

   - ``magnitude`` -- :ref:`Magnitude <api-python-datamodel-magnitude>`

   **Attributes**:

   - ``stationMagnitudeID`` -- string
   - ``residual`` -- float (optional)
   - ``weight`` -- float (optional)

   **Methods**:

   .. py:staticmethod:: Cast(obj)

      :param obj: The object to be casted.
      :rtype: An object of type StationMagnitudeContribution if the cast was successful,
              None otherwise.

      Cast an arbitrary object to StationMagnitudeContribution if the internal wrapped
      representation is an StationMagnitudeContribution object. The cast is important if
      instances of type :ref:`Object <api-python-datamodel-object>`
      are passed to methods which need access to the real type.



   .. py:method:: equal(other)

      :param other: Another object of type StationMagnitudeContribution to compare this
                    instance to
      :rtype: A Boolean value indicating True if both objects are equal or
              False otherwise.

      Compares two objects without its child objects. Both objects are compared
      by value.

   .. py:method:: index()

      :rtype: The object's index of type StationMagnitudeContributionIndex.

       Returns the objects index which is also used for the database as unique
       constraint.

   .. py:method:: equalIndex(lhs)

      :param lhs: :ref:`StationMagnitudeContribution <api-python-datamodel-stationmagnitudecontribution>`
      :rtype: A Boolean value indicating True if both indexes are equal or
              False otherwise.

   .. py:method:: setStationMagnitudeID(stationMagnitudeID)

      :param stationMagnitudeID: string

      Refers to the publicID of a StationMagnitude object.

   .. py:method:: stationMagnitudeID()

      :rtype: string

   .. py:method:: setResidual(residual)

      :param residual: float

      Residual of magnitude computation.

   .. py:method:: residual()

      :rtype: float

      .. note::

         As this attribute is optional, this method throws a ValueError if
         the value of the attribute is not set.

   .. py:method:: setWeight(weight)

      :param weight: float

      Weight of the magnitude value from class StationMagnitude for computing
      the magnitude value in class Magnitude. Note that there is no rule
      for the sum of the weights of all station magnitude contributions
      to a specific network magnitude. In particular, the weights are not
      required to sum up to unity.

   .. py:method:: weight()

      :rtype: float

      .. note::

         As this attribute is optional, this method throws a ValueError if
         the value of the attribute is not set.

   .. py:method:: magnitude()

      :rtype: Magnitude

      Returns the parent Magnitude if available. Returns None
      if the parent is not a Magnitude. This is a convenience wrapper
      for parent().

   .. py:method:: assign(other)

      This method implements the :ref:`Object <api-python-datamodel-object>` interface.

   .. py:method:: attachTo(parent)

      This method implements the :ref:`Object <api-python-datamodel-object>` interface.

   .. py:method:: detachFrom(parent)

      This method implements the :ref:`Object <api-python-datamodel-object>` interface.

   .. py:method:: detach()

      This method implements the :ref:`Object <api-python-datamodel-object>` interface.

   .. py:method:: clone()

      :rtype: A cloned StationMagnitudeContribution.

      Returns a new instance that is a clone of the current instance. Child
      objects are being ignored.


   .. py:method:: accept(visitor)

      :param visitor: A visitor.

      This method implements the :ref:`PublicObject <api-python-datamodel-publicobject>` interface.

.. _api-python-datamodel-stationreference:

StationReference
............................................................

.. py:class:: StationReference

   Inherits :ref:`Object <api-python-datamodel-object>`.

   This type describes a station reference within a station group

   **Parents**:

   - ``stationGroup`` -- :ref:`StationGroup <api-python-datamodel-stationgroup>`

   **Attributes**:

   - ``stationID`` -- string

   **Methods**:

   .. py:staticmethod:: Cast(obj)

      :param obj: The object to be casted.
      :rtype: An object of type StationReference if the cast was successful,
              None otherwise.

      Cast an arbitrary object to StationReference if the internal wrapped
      representation is an StationReference object. The cast is important if
      instances of type :ref:`Object <api-python-datamodel-object>`
      are passed to methods which need access to the real type.



   .. py:method:: equal(other)

      :param other: Another object of type StationReference to compare this
                    instance to
      :rtype: A Boolean value indicating True if both objects are equal or
              False otherwise.

      Compares two objects without its child objects. Both objects are compared
      by value.

   .. py:method:: index()

      :rtype: The object's index of type StationReferenceIndex.

       Returns the objects index which is also used for the database as unique
       constraint.

   .. py:method:: equalIndex(lhs)

      :param lhs: :ref:`StationReference <api-python-datamodel-stationreference>`
      :rtype: A Boolean value indicating True if both indexes are equal or
              False otherwise.

   .. py:method:: setStationID(stationID)

      :param stationID: string

      Reference to network\/station\/\@publicID

   .. py:method:: stationID()

      :rtype: string

   .. py:method:: stationGroup()

      :rtype: StationGroup

      Returns the parent StationGroup if available. Returns None
      if the parent is not a StationGroup. This is a convenience wrapper
      for parent().

   .. py:method:: assign(other)

      This method implements the :ref:`Object <api-python-datamodel-object>` interface.

   .. py:method:: attachTo(parent)

      This method implements the :ref:`Object <api-python-datamodel-object>` interface.

   .. py:method:: detachFrom(parent)

      This method implements the :ref:`Object <api-python-datamodel-object>` interface.

   .. py:method:: detach()

      This method implements the :ref:`Object <api-python-datamodel-object>` interface.

   .. py:method:: clone()

      :rtype: A cloned StationReference.

      Returns a new instance that is a clone of the current instance. Child
      objects are being ignored.


   .. py:method:: accept(visitor)

      :param visitor: A visitor.

      This method implements the :ref:`PublicObject <api-python-datamodel-publicobject>` interface.

.. _api-python-datamodel-stream:

Stream
............................................................

.. py:class:: Stream

   Inherits :ref:`PublicObject <api-python-datamodel-publicobject>`.

   This type describes a stream \(channel\) with defined frequency response

   **Parents**:

   - ``sensorLocation`` -- :ref:`SensorLocation <api-python-datamodel-sensorlocation>`

   **Children**:

   - ``comment`` -- :ref:`Comment <api-python-datamodel-comment>`

   **Attributes**:

   - ``publicID``: string
   - ``code`` -- string
   - ``start`` -- seiscomp.core.Time
   - ``end`` -- seiscomp.core.Time (optional)
   - ``datalogger`` -- string
   - ``dataloggerSerialNumber`` -- string
   - ``dataloggerChannel`` -- int (optional)
   - ``sensor`` -- string
   - ``sensorSerialNumber`` -- string
   - ``sensorChannel`` -- int (optional)
   - ``clockSerialNumber`` -- string
   - ``sampleRateNumerator`` -- int (optional)
   - ``sampleRateDenominator`` -- int (optional)
   - ``depth`` -- float (optional)
   - ``azimuth`` -- float (optional)
   - ``dip`` -- float (optional)
   - ``gain`` -- float (optional)
   - ``gainFrequency`` -- float (optional)
   - ``gainUnit`` -- string
   - ``format`` -- string
   - ``flags`` -- string
   - ``restricted`` -- boolean (optional)
   - ``shared`` -- boolean (optional)

   **Methods**:

   .. py:staticmethod:: Cast(obj)

      :param obj: The object to be casted.
      :rtype: An object of type Stream if the cast was successful,
              None otherwise.

      Cast an arbitrary object to Stream if the internal wrapped
      representation is an Stream object. The cast is important if
      instances of type :ref:`Object <api-python-datamodel-object>`
      are passed to methods which need access to the real type.



   .. py:staticmethod:: Create()

      :rtype: A new object of type Stream.

      Creates and registers (if enabled) a Stream instance. The
      publicID is auto-generated.

   .. py:staticmethod:: Create(publicID)

      :rtype: A new object of type Stream.

      Creates and registers (if enabled) a Stream instance with
      passed publicID.

   .. py:method:: equal(other)

      :param other: Another object of type Stream to compare this
                    instance to
      :rtype: A Boolean value indicating True if both objects are equal or
              False otherwise.

      Compares two objects without its child objects. Both objects are compared
      by value.

   .. py:method:: index()

      :rtype: The object's index of type StreamIndex.

       Returns the objects index which is also used for the database as unique
       constraint.

   .. py:method:: equalIndex(lhs)

      :param lhs: :ref:`Stream <api-python-datamodel-stream>`
      :rtype: A Boolean value indicating True if both indexes are equal or
              False otherwise.

   .. py:method:: setCode(code)

      :param code: string

      Stream code \(52.04\)

   .. py:method:: code()

      :rtype: string

   .. py:method:: setStart(start)

      :param start: seiscomp.core.Time

      Start of epoch in ISO datetime format \(52.22\)

   .. py:method:: start()

      :rtype: seiscomp.core.Time

   .. py:method:: setEnd(end)

      :param end: seiscomp.core.Time

      End of epoch \(52.23\)

   .. py:method:: end()

      :rtype: seiscomp.core.Time

      .. note::

         As this attribute is optional, this method throws a ValueError if
         the value of the attribute is not set.

   .. py:method:: setDatalogger(datalogger)

      :param datalogger: string

      Reference to datalogger\/\@publicID

   .. py:method:: datalogger()

      :rtype: string

   .. py:method:: setDataloggerSerialNumber(dataloggerSerialNumber)

      :param dataloggerSerialNumber: string

      Reference to datalogger\/calibration\/\@serialNumber

   .. py:method:: dataloggerSerialNumber()

      :rtype: string

   .. py:method:: setDataloggerChannel(dataloggerChannel)

      :param dataloggerChannel: int

      Reference to datalogger\/calibration\/\@channel

   .. py:method:: dataloggerChannel()

      :rtype: int

      .. note::

         As this attribute is optional, this method throws a ValueError if
         the value of the attribute is not set.

   .. py:method:: setSensor(sensor)

      :param sensor: string

      Reference to sensor\/\@publicID

   .. py:method:: sensor()

      :rtype: string

   .. py:method:: setSensorSerialNumber(sensorSerialNumber)

      :param sensorSerialNumber: string

      Reference to sensor\/calibration\/\@serialNumber

   .. py:method:: sensorSerialNumber()

      :rtype: string

   .. py:method:: setSensorChannel(sensorChannel)

      :param sensorChannel: int

      Reference to sensor\/calibration\/\@channel

   .. py:method:: sensorChannel()

      :rtype: int

      .. note::

         As this attribute is optional, this method throws a ValueError if
         the value of the attribute is not set.

   .. py:method:: setClockSerialNumber(clockSerialNumber)

      :param clockSerialNumber: string

      Serial no. of clock \(GPS\). Mostly unused

   .. py:method:: clockSerialNumber()

      :rtype: string

   .. py:method:: setSampleRateNumerator(sampleRateNumerator)

      :param sampleRateNumerator: int

      Sample rate numerator \(always >0, eg., not identical to 52.18\)

   .. py:method:: sampleRateNumerator()

      :rtype: int

      .. note::

         As this attribute is optional, this method throws a ValueError if
         the value of the attribute is not set.

   .. py:method:: setSampleRateDenominator(sampleRateDenominator)

      :param sampleRateDenominator: int

      Sample rate denominator \(always >0, eg., not identical to 52.19\)

   .. py:method:: sampleRateDenominator()

      :rtype: int

      .. note::

         As this attribute is optional, this method throws a ValueError if
         the value of the attribute is not set.

   .. py:method:: setDepth(depth)

      :param depth: float

      Depth \(52.13\) of the sensor below sensorLocation in meters

   .. py:method:: depth()

      :rtype: float

      .. note::

         As this attribute is optional, this method throws a ValueError if
         the value of the attribute is not set.

   .. py:method:: setAzimuth(azimuth)

      :param azimuth: float

      Azimuth \(52.14\)

   .. py:method:: azimuth()

      :rtype: float

      .. note::

         As this attribute is optional, this method throws a ValueError if
         the value of the attribute is not set.

   .. py:method:: setDip(dip)

      :param dip: float

      Dip \(52.15\)

   .. py:method:: dip()

      :rtype: float

      .. note::

         As this attribute is optional, this method throws a ValueError if
         the value of the attribute is not set.

   .. py:method:: setGain(gain)

      :param gain: float

      Overall sensitivity \(58.04\) in counts\/gainUnit

   .. py:method:: gain()

      :rtype: float

      .. note::

         As this attribute is optional, this method throws a ValueError if
         the value of the attribute is not set.

   .. py:method:: setGainFrequency(gainFrequency)

      :param gainFrequency: float

      Gain frequency \(58.05\)

   .. py:method:: gainFrequency()

      :rtype: float

      .. note::

         As this attribute is optional, this method throws a ValueError if
         the value of the attribute is not set.

   .. py:method:: setGainUnit(gainUnit)

      :param gainUnit: string

      Sensor's unit of measurement \(eg., M\/S, M\/S**2\)

   .. py:method:: gainUnit()

      :rtype: string

   .. py:method:: setFormat(format)

      :param format: string

      Data format, eg.: \"steim1\", \"steim2\", \"mseedN\" \(N \= encoding format
      in blockette 1000\)

   .. py:method:: format()

      :rtype: string

   .. py:method:: setFlags(flags)

      :param flags: string

      Channel flags \(52.21\)

   .. py:method:: flags()

      :rtype: string

   .. py:method:: setRestricted(restricted)

      :param restricted: boolean

      Whether the stream is \"restricted\"

   .. py:method:: restricted()

      :rtype: boolean

      .. note::

         As this attribute is optional, this method throws a ValueError if
         the value of the attribute is not set.

   .. py:method:: setShared(shared)

      :param shared: boolean

      Whether the metadata is synchronized with other datacenters

   .. py:method:: shared()

      :rtype: boolean

      .. note::

         As this attribute is optional, this method throws a ValueError if
         the value of the attribute is not set.

   .. py:method:: add(comment)

      :param comment: Object of type :ref:`Comment <api-python-datamodel-comment>`
      :rtype: A Boolean value indicating success with True, False otherwise.

      Adds a Comment object to Stream. The object is not
      copied but managed by this instance. Any change to the passed object
      will also change the child.

   .. py:method:: remove(comment)

      :param comment: Object of type :ref:`Comment <api-python-datamodel-comment>`
      :rtype: A Boolean value indicating success with True, False otherwise.

      Removes a previously added Comment object from Stream.

   .. py:method:: removeComment(idx)

      :param idx: An integer index of the object to be removed.
      :rtype: A Boolean value indicating success with True, False otherwise.

   .. py:method:: removeComment(commentIndex);

      :param commentIndex: The index of the object to be removed of type CommentIndex.
      :rtype: A Boolean value indicating success with True, False otherwise.

   .. py:method:: commentCount()

      :rtype: integer value indicating the number of child objects.

      Returns the number of Comment child objects.

   .. py:method:: comment(idx)

      :param idx: An integer index of the object to be returned.
      :rtype: Object of type :ref:`Comment <api-python-datamodel-comment>`.

      Returns the Comment at index idx.

   .. py:method:: comment(commentIndex)

      :param commentIndex: The index of the object to be removed of type CommentIndex.
      :rtype: Object of type :ref:`Comment <api-python-datamodel-comment>`.

      Returns the Comment at given index. The indexes of all child objects
      are compared by value which makes this function slower than the direct
      integer index look-up.

   .. py:method:: sensorLocation()

      :rtype: SensorLocation

      Returns the parent SensorLocation if available. Returns None
      if the parent is not a SensorLocation. This is a convenience wrapper
      for parent().

   .. py:method:: assign(other)

      This method implements the :ref:`Object <api-python-datamodel-object>` interface.

   .. py:method:: attachTo(parent)

      This method implements the :ref:`Object <api-python-datamodel-object>` interface.

   .. py:method:: detachFrom(parent)

      This method implements the :ref:`Object <api-python-datamodel-object>` interface.

   .. py:method:: detach()

      This method implements the :ref:`Object <api-python-datamodel-object>` interface.

   .. py:method:: clone()

      :rtype: A cloned Stream.

      Returns a new instance that is a clone of the current instance. Child
      objects are being ignored.


   .. py:method:: updateChild(ref)

      :param ref: A child object derived from class Object.
      :rtype: A Boolean flag indicating success with True, False otherwise

      This method takes the passed reference object and searches for a child
      with the same publicID (if derived from :ref:`PublicObject <api-python-datamodel-publicobject>`)
      or the same index (if derived from :ref:`Object <api-python-datamodel-object>`).
      The the child was found the reference objects attributes are copied to
      the child object. Children of child are being ignored during this operation.
      This method implements the :ref:`PublicObject <api-python-datamodel-publicobject>` interface.


   .. py:method:: accept(visitor)

      :param visitor: A visitor.

      This method implements the :ref:`PublicObject <api-python-datamodel-publicobject>` interface.

.. _api-python-datamodel-tensor:

Tensor
............................................................

.. py:class:: Tensor

   Inherits :ref:`Object <api-python-datamodel-object>`.

   The Tensor class represents the six moment\-tensor elements Mrr , Mtt ,
   Mpp , Mrt , Mrp , Mtp in the spherical coordinate system defined by local
   upward vertical \(r\), North\-South \(t\), and West\-East \(p\) directions. See
   Aki and Richards \(1980\) for conversions to other coordinate systems.

   **Attributes**:

   - ``Mrr`` -- :ref:`RealQuantity <api-python-datamodel-realquantity>`
   - ``Mtt`` -- :ref:`RealQuantity <api-python-datamodel-realquantity>`
   - ``Mpp`` -- :ref:`RealQuantity <api-python-datamodel-realquantity>`
   - ``Mrt`` -- :ref:`RealQuantity <api-python-datamodel-realquantity>`
   - ``Mrp`` -- :ref:`RealQuantity <api-python-datamodel-realquantity>`
   - ``Mtp`` -- :ref:`RealQuantity <api-python-datamodel-realquantity>`

   **Used by**:

   - :func:`MomentTensor.tensor`

   **Methods**:

   .. py:staticmethod:: Cast(obj)

      :param obj: The object to be casted.
      :rtype: An object of type Tensor if the cast was successful,
              None otherwise.

      Cast an arbitrary object to Tensor if the internal wrapped
      representation is an Tensor object. The cast is important if
      instances of type :ref:`Object <api-python-datamodel-object>`
      are passed to methods which need access to the real type.



   .. py:method:: equal(other)

      :param other: Another object of type Tensor to compare this
                    instance to
      :rtype: A Boolean value indicating True if both objects are equal or
              False otherwise.

      Compares two objects without its child objects. Both objects are compared
      by value.

   .. py:method:: setMrr(Mrr)

      :param Mrr: :ref:`RealQuantity <api-python-datamodel-realquantity>`

      Moment\-tensor element Mrr in Nm.

   .. py:method:: Mrr()

      :rtype: :ref:`RealQuantity <api-python-datamodel-realquantity>`

   .. py:method:: setMtt(Mtt)

      :param Mtt: :ref:`RealQuantity <api-python-datamodel-realquantity>`

      Moment\-tensor element Mtt in Nm.

   .. py:method:: Mtt()

      :rtype: :ref:`RealQuantity <api-python-datamodel-realquantity>`

   .. py:method:: setMpp(Mpp)

      :param Mpp: :ref:`RealQuantity <api-python-datamodel-realquantity>`

      Moment\-tensor element Mpp in Nm.

   .. py:method:: Mpp()

      :rtype: :ref:`RealQuantity <api-python-datamodel-realquantity>`

   .. py:method:: setMrt(Mrt)

      :param Mrt: :ref:`RealQuantity <api-python-datamodel-realquantity>`

      Moment\-tensor element Mrt in Nm.

   .. py:method:: Mrt()

      :rtype: :ref:`RealQuantity <api-python-datamodel-realquantity>`

   .. py:method:: setMrp(Mrp)

      :param Mrp: :ref:`RealQuantity <api-python-datamodel-realquantity>`

      Moment\-tensor element Mrp in Nm.

   .. py:method:: Mrp()

      :rtype: :ref:`RealQuantity <api-python-datamodel-realquantity>`

   .. py:method:: setMtp(Mtp)

      :param Mtp: :ref:`RealQuantity <api-python-datamodel-realquantity>`

      Moment\-tensor element Mtp in Nm.

   .. py:method:: Mtp()

      :rtype: :ref:`RealQuantity <api-python-datamodel-realquantity>`

.. _api-python-datamodel-timearray:

TimeArray
............................................................

.. py:class:: TimeArray

   Inherits :ref:`Object <api-python-datamodel-object>`.


   **Attributes**:

   - ``content`` -- seiscomp.core.Time (optional)

   **Used by**:

   - :func:`TimePDF1D.variable`

   **Methods**:

   .. py:staticmethod:: Cast(obj)

      :param obj: The object to be casted.
      :rtype: An object of type TimeArray if the cast was successful,
              None otherwise.

      Cast an arbitrary object to TimeArray if the internal wrapped
      representation is an TimeArray object. The cast is important if
      instances of type :ref:`Object <api-python-datamodel-object>`
      are passed to methods which need access to the real type.



   .. py:method:: equal(other)

      :param other: Another object of type TimeArray to compare this
                    instance to
      :rtype: A Boolean value indicating True if both objects are equal or
              False otherwise.

      Compares two objects without its child objects. Both objects are compared
      by value.

   .. py:method:: setContent(content)

      :param content: seiscomp.core.Time

   .. py:method:: content()

      :rtype: seiscomp.core.Time

      .. note::

         As this attribute is optional, this method throws a ValueError if
         the value of the attribute is not set.

.. _api-python-datamodel-timepdf1d:

TimePDF1D
............................................................

.. py:class:: TimePDF1D

   Inherits :ref:`Object <api-python-datamodel-object>`.

   A probability density function description. It can be used in three
   different modes:
   
   1\) \"raw samples mode\"
   
   variable is a list of M values, no probability. The values represent
   samples, no binning\/probabilities made.
   
   2\) \"implicitly binned PDF\"
   
   variable and probabilty arrays have length N. variable values to be
   interpreted as \"bin centers\" \(or representative values\),
   no bin edges given.
   
   3\) \"explicitly binned PDF\"
   
   variable has length N+1, probability has length N. variable values
   describe bin edges \(upper bin edge is lower edge of next bin\).

   **Attributes**:

   - ``variable`` -- :ref:`TimeArray <api-python-datamodel-timearray>`
   - ``probability`` -- :ref:`RealArray <api-python-datamodel-realarray>`

   **Used by**:

   - :func:`TimeQuantity.pdf`

   **Methods**:

   .. py:staticmethod:: Cast(obj)

      :param obj: The object to be casted.
      :rtype: An object of type TimePDF1D if the cast was successful,
              None otherwise.

      Cast an arbitrary object to TimePDF1D if the internal wrapped
      representation is an TimePDF1D object. The cast is important if
      instances of type :ref:`Object <api-python-datamodel-object>`
      are passed to methods which need access to the real type.



   .. py:method:: equal(other)

      :param other: Another object of type TimePDF1D to compare this
                    instance to
      :rtype: A Boolean value indicating True if both objects are equal or
              False otherwise.

      Compares two objects without its child objects. Both objects are compared
      by value.

   .. py:method:: setVariable(variable)

      :param variable: :ref:`TimeArray <api-python-datamodel-timearray>`

      List of datetimes

   .. py:method:: variable()

      :rtype: :ref:`TimeArray <api-python-datamodel-timearray>`

   .. py:method:: setProbability(probability)

      :param probability: :ref:`RealArray <api-python-datamodel-realarray>`

      List of probabilities

   .. py:method:: probability()

      :rtype: :ref:`RealArray <api-python-datamodel-realarray>`

.. _api-python-datamodel-timequantity:

TimeQuantity
............................................................

.. py:class:: TimeQuantity

   Inherits :ref:`Object <api-python-datamodel-object>`.

   This type describes a point in time, given in ISO 8601 format, with
   optional symmetric or asymmetric uncertainties given in seconds. The
   time has to be specified in UTC.

   **Attributes**:

   - ``value`` -- seiscomp.core.Time
   - ``uncertainty`` -- float (optional)
   - ``lowerUncertainty`` -- float (optional)
   - ``upperUncertainty`` -- float (optional)
   - ``confidenceLevel`` -- float (optional)
   - ``pdf`` -- :ref:`TimePDF1D <api-python-datamodel-timepdf1d>` (optional)

   **Used by**:

   - :func:`Amplitude.scalingTime`
   - :func:`Origin.time`
   - :func:`Pick.time`

   **Methods**:

   .. py:staticmethod:: Cast(obj)

      :param obj: The object to be casted.
      :rtype: An object of type TimeQuantity if the cast was successful,
              None otherwise.

      Cast an arbitrary object to TimeQuantity if the internal wrapped
      representation is an TimeQuantity object. The cast is important if
      instances of type :ref:`Object <api-python-datamodel-object>`
      are passed to methods which need access to the real type.



   .. py:method:: equal(other)

      :param other: Another object of type TimeQuantity to compare this
                    instance to
      :rtype: A Boolean value indicating True if both objects are equal or
              False otherwise.

      Compares two objects without its child objects. Both objects are compared
      by value.

   .. py:method:: setValue(value)

      :param value: seiscomp.core.Time

      Point in time \(UTC\), given in ISO 8601 format.

   .. py:method:: value()

      :rtype: seiscomp.core.Time

   .. py:method:: setUncertainty(uncertainty)

      :param uncertainty: float

      Symmetric uncertainty of point in time in seconds.

   .. py:method:: uncertainty()

      :rtype: float

      .. note::

         As this attribute is optional, this method throws a ValueError if
         the value of the attribute is not set.

   .. py:method:: setLowerUncertainty(lowerUncertainty)

      :param lowerUncertainty: float

      Lower uncertainty of point in time in seconds.

   .. py:method:: lowerUncertainty()

      :rtype: float

      .. note::

         As this attribute is optional, this method throws a ValueError if
         the value of the attribute is not set.

   .. py:method:: setUpperUncertainty(upperUncertainty)

      :param upperUncertainty: float

      Upper uncertainty of point in time in seconds.

   .. py:method:: upperUncertainty()

      :rtype: float

      .. note::

         As this attribute is optional, this method throws a ValueError if
         the value of the attribute is not set.

   .. py:method:: setConfidenceLevel(confidenceLevel)

      :param confidenceLevel: float

      Confidence level of the uncertainty, given in percent.

   .. py:method:: confidenceLevel()

      :rtype: float

      .. note::

         As this attribute is optional, this method throws a ValueError if
         the value of the attribute is not set.

   .. py:method:: setPdf(pdf)

      :param pdf: :ref:`TimePDF1D <api-python-datamodel-timepdf1d>`

      Probability density function of the quantity.

   .. py:method:: pdf()

      :rtype: :ref:`TimePDF1D <api-python-datamodel-timepdf1d>`

      .. note::

         As this attribute is optional, this method throws a ValueError if
         the value of the attribute is not set.

.. _api-python-datamodel-timewindow:

TimeWindow
............................................................

.. py:class:: TimeWindow

   Inherits :ref:`Object <api-python-datamodel-object>`.

   Describes a time window for amplitude measurements, given by a central point in
   time, and points in time
   before and after this central point. Both points before and after may coincide
   with the central point.

   **Attributes**:

   - ``reference`` -- seiscomp.core.Time
   - ``begin`` -- float
   - ``end`` -- float

   **Used by**:

   - :func:`Amplitude.timeWindow`

   **Methods**:

   .. py:staticmethod:: Cast(obj)

      :param obj: The object to be casted.
      :rtype: An object of type TimeWindow if the cast was successful,
              None otherwise.

      Cast an arbitrary object to TimeWindow if the internal wrapped
      representation is an TimeWindow object. The cast is important if
      instances of type :ref:`Object <api-python-datamodel-object>`
      are passed to methods which need access to the real type.



   .. py:method:: equal(other)

      :param other: Another object of type TimeWindow to compare this
                    instance to
      :rtype: A Boolean value indicating True if both objects are equal or
              False otherwise.

      Compares two objects without its child objects. Both objects are compared
      by value.

   .. py:method:: setReference(reference)

      :param reference: seiscomp.core.Time

      Reference point in time \(\"central\" point\), in ISO 8601 format. It
      has to be given in UTC.

   .. py:method:: reference()

      :rtype: seiscomp.core.Time

   .. py:method:: setBegin(begin)

      :param begin: float

      Absolute value of duration of time interval before reference point
      in time window. The value may be zero, but not negative in seconds.

   .. py:method:: begin()

      :rtype: float

   .. py:method:: setEnd(end)

      :param end: float

      Absolute value of duration of time interval after reference point in
      time window. The value may be zero, but not negative in seconds.

   .. py:method:: end()

      :rtype: float

.. _api-python-datamodel-waveformquality:

WaveformQuality
............................................................

.. py:class:: WaveformQuality

   Inherits :ref:`Object <api-python-datamodel-object>`.


   **Parents**:

   - ``qualityControl`` -- :ref:`QualityControl <api-python-datamodel-qualitycontrol>`

   **Attributes**:

   - ``waveformID`` -- :ref:`WaveformStreamID <api-python-datamodel-waveformstreamid>`
   - ``creatorID`` -- string
   - ``created`` -- seiscomp.core.Time
   - ``start`` -- seiscomp.core.Time
   - ``end`` -- seiscomp.core.Time (optional)
   - ``type`` -- string
   - ``parameter`` -- string
   - ``value`` -- float
   - ``lowerUncertainty`` -- float (optional)
   - ``upperUncertainty`` -- float (optional)
   - ``windowLength`` -- float (optional)

   **Methods**:

   .. py:staticmethod:: Cast(obj)

      :param obj: The object to be casted.
      :rtype: An object of type WaveformQuality if the cast was successful,
              None otherwise.

      Cast an arbitrary object to WaveformQuality if the internal wrapped
      representation is an WaveformQuality object. The cast is important if
      instances of type :ref:`Object <api-python-datamodel-object>`
      are passed to methods which need access to the real type.



   .. py:method:: equal(other)

      :param other: Another object of type WaveformQuality to compare this
                    instance to
      :rtype: A Boolean value indicating True if both objects are equal or
              False otherwise.

      Compares two objects without its child objects. Both objects are compared
      by value.

   .. py:method:: index()

      :rtype: The object's index of type WaveformQualityIndex.

       Returns the objects index which is also used for the database as unique
       constraint.

   .. py:method:: equalIndex(lhs)

      :param lhs: :ref:`WaveformQuality <api-python-datamodel-waveformquality>`
      :rtype: A Boolean value indicating True if both indexes are equal or
              False otherwise.

   .. py:method:: setWaveformID(waveformID)

      :param waveformID: :ref:`WaveformStreamID <api-python-datamodel-waveformstreamid>`

   .. py:method:: waveformID()

      :rtype: :ref:`WaveformStreamID <api-python-datamodel-waveformstreamid>`

   .. py:method:: setCreatorID(creatorID)

      :param creatorID: string

   .. py:method:: creatorID()

      :rtype: string

   .. py:method:: setCreated(created)

      :param created: seiscomp.core.Time

   .. py:method:: created()

      :rtype: seiscomp.core.Time

   .. py:method:: setStart(start)

      :param start: seiscomp.core.Time

   .. py:method:: start()

      :rtype: seiscomp.core.Time

   .. py:method:: setEnd(end)

      :param end: seiscomp.core.Time

   .. py:method:: end()

      :rtype: seiscomp.core.Time

      .. note::

         As this attribute is optional, this method throws a ValueError if
         the value of the attribute is not set.

   .. py:method:: setType(type)

      :param type: string

   .. py:method:: type()

      :rtype: string

   .. py:method:: setParameter(parameter)

      :param parameter: string

   .. py:method:: parameter()

      :rtype: string

   .. py:method:: setValue(value)

      :param value: float

   .. py:method:: value()

      :rtype: float

   .. py:method:: setLowerUncertainty(lowerUncertainty)

      :param lowerUncertainty: float

   .. py:method:: lowerUncertainty()

      :rtype: float

      .. note::

         As this attribute is optional, this method throws a ValueError if
         the value of the attribute is not set.

   .. py:method:: setUpperUncertainty(upperUncertainty)

      :param upperUncertainty: float

   .. py:method:: upperUncertainty()

      :rtype: float

      .. note::

         As this attribute is optional, this method throws a ValueError if
         the value of the attribute is not set.

   .. py:method:: setWindowLength(windowLength)

      :param windowLength: float

   .. py:method:: windowLength()

      :rtype: float

      .. note::

         As this attribute is optional, this method throws a ValueError if
         the value of the attribute is not set.

   .. py:method:: qualityControl()

      :rtype: QualityControl

      Returns the parent QualityControl if available. Returns None
      if the parent is not a QualityControl. This is a convenience wrapper
      for parent().

   .. py:method:: assign(other)

      This method implements the :ref:`Object <api-python-datamodel-object>` interface.

   .. py:method:: attachTo(parent)

      This method implements the :ref:`Object <api-python-datamodel-object>` interface.

   .. py:method:: detachFrom(parent)

      This method implements the :ref:`Object <api-python-datamodel-object>` interface.

   .. py:method:: detach()

      This method implements the :ref:`Object <api-python-datamodel-object>` interface.

   .. py:method:: clone()

      :rtype: A cloned WaveformQuality.

      Returns a new instance that is a clone of the current instance. Child
      objects are being ignored.


   .. py:method:: accept(visitor)

      :param visitor: A visitor.

      This method implements the :ref:`PublicObject <api-python-datamodel-publicobject>` interface.

.. _api-python-datamodel-waveformstreamid:

WaveformStreamID
............................................................

.. py:class:: WaveformStreamID

   Inherits :ref:`Object <api-python-datamodel-object>`.

   Reference to a stream description in an inventory. This is mostly
   equivalent to the combination of networkCode, stationCode, locationCode
   and channelCode. However, additional information, e. g., sampling rate,
   can be referenced by the resourceURI. It is recommended to use
   resourceURI as a flexible, abstract, and unique stream ID that allows to
   describe different processing levels, or resampled\/filtered products of
   the same initial stream, without violating the intrinsic meaning of the
   legacy identifiers \(network, station, channel, and location codes\).
   However, for operation in the context of legacy systems, the classical
   identifier components are supported.

   **Attributes**:

   - ``networkCode`` -- string
   - ``stationCode`` -- string
   - ``locationCode`` -- string
   - ``channelCode`` -- string
   - ``resourceURI`` -- string

   **Used by**:

   - :func:`Amplitude.waveformID`
   - :func:`ArclinkRequestLine.streamID`
   - :func:`DataExtent.waveformID`
   - :func:`MomentTensorStationContribution.waveformID`
   - :func:`Outage.waveformID`
   - :func:`Pick.waveformID`
   - :func:`QCLog.waveformID`
   - :func:`StationMagnitude.waveformID`
   - :func:`WaveformQuality.waveformID`

   **Methods**:

   .. py:staticmethod:: Cast(obj)

      :param obj: The object to be casted.
      :rtype: An object of type WaveformStreamID if the cast was successful,
              None otherwise.

      Cast an arbitrary object to WaveformStreamID if the internal wrapped
      representation is an WaveformStreamID object. The cast is important if
      instances of type :ref:`Object <api-python-datamodel-object>`
      are passed to methods which need access to the real type.



   .. py:method:: equal(other)

      :param other: Another object of type WaveformStreamID to compare this
                    instance to
      :rtype: A Boolean value indicating True if both objects are equal or
              False otherwise.

      Compares two objects without its child objects. Both objects are compared
      by value.

   .. py:method:: setNetworkCode(networkCode)

      :param networkCode: string

      Network code. String with a maximum length of 8 characters.

   .. py:method:: networkCode()

      :rtype: string

   .. py:method:: setStationCode(stationCode)

      :param stationCode: string

      Station code. String with a maximum length of 8 characters.

   .. py:method:: stationCode()

      :rtype: string

   .. py:method:: setLocationCode(locationCode)

      :param locationCode: string

      Location code. String with a maximum length of 8 characters.

   .. py:method:: locationCode()

      :rtype: string

   .. py:method:: setChannelCode(channelCode)

      :param channelCode: string

      Channel code. String with a maximum length of 8 characters.

   .. py:method:: channelCode()

      :rtype: string

   .. py:method:: setResourceURI(resourceURI)

      :param resourceURI: string

      Optional resource identifier for the waveform stream. QuakeML adopts
      in many places resource descriptors with a well\-defined syntax for
      unambiguous resource identification. Resource identifiers are designed
      to be backward compatible with existing descriptors. In SeisComP this
      identifier is not used at all.

   .. py:method:: resourceURI()

      :rtype: string

.. raw:: html

   <script>
   window.onload = function() {
       let graphvizs = document.getElementsByClassName("graphviz");
       for ( let graphviz of graphvizs ) {
           obj = graphviz.firstElementChild;
           if ( obj === undefined || obj.tagName !== "OBJECT" ) {
               continue;
           }
           let url = obj.data;
           let div = obj.parentElement;
           console.log(div.tagName);
           if ( url === undefined || div === undefined || div.tagName !== "DIV" ) {
               continue;
           }

           let caption = div.nextElementSibling;
           if ( caption === undefined ) {
               continue;
           }

           let svg = document.createElement("a");
           svg.appendChild(document.createTextNode("[SVG]"));
           svg.setAttribute("href", "#")
           svg.onclick = function() { window.open(url); };
           caption.appendChild(svg);
       }
   }
   </script>

